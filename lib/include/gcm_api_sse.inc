;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Copyright(c) 2021-2024 Intel Corporation All rights reserved.
;
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions
;  are met:
;    * Redistributions of source code must retain the above copyright
;      notice, this list of conditions and the following disclaimer.
;    * Redistributions in binary form must reproduce the above copyright
;      notice, this list of conditions and the following disclaimer in
;      the documentation and/or other materials provided with the
;      distribution.
;    * Neither the name of Intel Corporation nor the names of its
;      contributors may be used to endorse or promote products derived
;      from this software without specific prior written permission.
;
;  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;

%include "include/gcm_sse.inc"
%include "include/imb_job.inc"

%ifndef GCM_API_SSE_INC
%define GCM_API_SSE_INC

section .text
default rel

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void	aes_gcm_precomp_128_sse / aes_gcm_precomp_192_sse / aes_gcm_precomp_256_sse
;        (struct gcm_key_data *key_data);
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
align 32
MKGLOBAL(FN_NAME(precomp,_),function,)
FN_NAME(precomp,_):
        endbranch64
%ifdef SAFE_PARAM
        ;; Reset imb_errno
        IMB_ERR_CHECK_RESET

        ;; Check key_data != NULL
        cmp     arg1, 0
        jz      error_precomp
%endif

%ifidn __OUTPUT_FORMAT__, win64
        sub     rsp, 1*16
        ; only xmm6 needs to be maintained
        movdqu [rsp +  0*16], xmm6
%endif

	pxor	xmm6, xmm6
	ENCRYPT_SINGLE_BLOCK	arg1, xmm6, xmm2	; xmm6 = HashKey

        pshufb  xmm6, [SHUF_MASK]
        ;;;;;;;;;;;;;;;  PRECOMPUTATION of HashKey<<1 mod poly from the HashKey;;;;;;;;;;;;;;;
        movdqa  xmm2, xmm6
        psllq   xmm6, 1
        psrlq   xmm2, 63
        movdqa  xmm1, xmm2
        pslldq  xmm2, 8
        psrldq  xmm1, 8
        por     xmm6, xmm2
        ;reduction
        pshufd  xmm2, xmm1, 00100100b
        pcmpeqd xmm2, [TWOONE]
        pand    xmm2, [POLY]
        pxor    xmm6, xmm2                             ; xmm6 holds the HashKey<<1 mod poly
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        movdqu  [arg1 + HashKey], xmm6                  ; store HashKey<<1 mod poly

        PRECOMPUTE  arg1, xmm6, xmm0, xmm1, xmm2, xmm3, xmm4, xmm5

%ifdef SAFE_DATA
        clear_scratch_gps_asm
        clear_scratch_xmms_sse_asm
%endif
%ifidn __OUTPUT_FORMAT__, win64
        movdqu  xmm6, [rsp + 0*16]
        add     rsp, 1*16
%endif

exit_precomp:

        ret

%ifdef SAFE_PARAM
error_precomp:
        ;; Clear reg and imb_errno
        IMB_ERR_CHECK_START rax

        ;; Check key_data != NULL
        IMB_ERR_CHECK_NULL arg1, rax, IMB_ERR_NULL_EXP_KEY

        ;; Set imb_errno
        IMB_ERR_CHECK_END rax

        jmp exit_precomp
%endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void   aes_gcm_enc_128_sse / aes_gcm_enc_192_sse / aes_gcm_enc_256_sse
;       (const struct gcm_key_data *key_data,
;        struct gcm_context_data *context_data,
;        u8      *out,
;        const   u8 *in,
;        u64     msg_len,
;        u8      *iv,
;        const   u8 *aad,
;        u64     aad_len,
;        u8      *auth_tag,
;        u64     auth_tag_len);
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
align 32
MKGLOBAL(FN_NAME(enc,_),function,)
FN_NAME(enc,_):
        endbranch64
	FUNC_SAVE

%ifdef SAFE_PARAM
        ;; Reset imb_errno
        IMB_ERR_CHECK_RESET

        ;; Load max len to reg on windows
        INIT_GCM_MAX_LENGTH

        ;; Check key_data != NULL
        cmp     arg1, 0
        jz      error_enc

        ;; Check context_data != NULL
        cmp     arg2, 0
        jz      error_enc

        ;; Check IV != NULL
        cmp     arg6, 0
        jz      error_enc

        ;; Check auth_tag != NULL
        cmp     arg9, 0
        jz      error_enc

        ;; Check auth_tag_len == 0 or > 16
        cmp     arg10, 0
        jz      error_enc

        cmp     arg10, 16
        ja      error_enc

        ;; Check if msg_len == 0
        cmp     arg5, 0
        jz      skip_in_out_check_enc

        ;; Check if msg_len > max_len
        cmp     arg5, GCM_MAX_LENGTH
        ja      error_enc

        ;; Check out != NULL (msg_len != 0)
        cmp     arg3, 0
        jz      error_enc

        ;; Check in != NULL (msg_len != 0)
        cmp     arg4, 0
        jz      error_enc

skip_in_out_check_enc:
        ;; Check if aad_len == 0
        cmp     arg8, 0
        jz      skip_aad_check_enc

        ;; Check aad != NULL (aad_len != 0)
        cmp     arg7, 0
        jz      error_enc

skip_aad_check_enc:
%endif
	GCM_INIT arg1, arg2, arg6, arg7, arg8

	GCM_ENC_DEC  arg1, arg2, arg3, arg4, arg5, ENC

	GCM_COMPLETE arg1, arg2, arg9, arg10

exit_enc:
	FUNC_RESTORE

	ret

%ifdef SAFE_PARAM
error_enc:
        ;; Clear reg and imb_errno
        IMB_ERR_CHECK_START rax

        ;; Check key_data != NULL
        IMB_ERR_CHECK_NULL arg1, rax, IMB_ERR_NULL_EXP_KEY

        ;; Check context_data != NULL
        IMB_ERR_CHECK_NULL arg2, rax, IMB_ERR_NULL_CTX

        ;; Check IV != NULL
        IMB_ERR_CHECK_NULL arg6, rax, IMB_ERR_NULL_IV

        ;; Check auth_tag != NULL
        IMB_ERR_CHECK_NULL arg9, rax, IMB_ERR_NULL_AUTH

        ;; Check auth_tag_len == 0 or > 16
        IMB_ERR_CHECK_ZERO arg10, rax, IMB_ERR_AUTH_TAG_LEN

        IMB_ERR_CHECK_ABOVE arg10, 16, rax, IMB_ERR_AUTH_TAG_LEN

        ;; Check if msg_len == 0
        cmp     arg5, 0
        jz      skip_in_out_check_error_enc

        ;; Check if msg_len > max_len
        IMB_ERR_CHECK_ABOVE arg5, GCM_MAX_LENGTH, rax, IMB_ERR_CIPH_LEN

        ;; Check out != NULL (msg_len != 0)
        IMB_ERR_CHECK_NULL arg3, rax, IMB_ERR_NULL_DST

        ;; Check in != NULL (msg_len != 0)
        IMB_ERR_CHECK_NULL arg4, rax, IMB_ERR_NULL_SRC

skip_in_out_check_error_enc:
        ;; Check if aad_len == 0
        cmp     arg8, 0
        jz      skip_aad_check_error_enc

        ;; Check aad != NULL (aad_len != 0)
        IMB_ERR_CHECK_NULL arg7, rax, IMB_ERR_NULL_AAD

skip_aad_check_error_enc:
        ;; Set imb_errno
        IMB_ERR_CHECK_END rax
        jmp     exit_enc
%endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void   aes_gcm_dec_128_sse / aes_gcm_dec_192_sse / aes_gcm_dec_256_sse
;       (const struct gcm_key_data *key_data,
;        struct gcm_context_data *context_data,
;        u8      *out,
;        const   u8 *in,
;        u64     msg_len,
;        u8      *iv,
;        const   u8 *aad,
;        u64     aad_len,
;        u8      *auth_tag,
;        u64     auth_tag_len);
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
align 32
MKGLOBAL(FN_NAME(dec,_),function,)
FN_NAME(dec,_):
        endbranch64
	FUNC_SAVE

%ifdef SAFE_PARAM
        ;; Reset imb_errno
        IMB_ERR_CHECK_RESET

        ;; Load max len to reg on windows
        INIT_GCM_MAX_LENGTH

        ;; Check key_data != NULL
        cmp     arg1, 0
        jz      error_dec

        ;; Check context_data != NULL
        cmp     arg2, 0
        jz      error_dec

        ;; Check IV != NULL
        cmp     arg6, 0
        jz      error_dec

        ;; Check auth_tag != NULL
        cmp     arg9, 0
        jz      error_dec

        ;; Check auth_tag_len == 0 or > 16
        cmp     arg10, 0
        jz      error_dec

        cmp     arg10, 16
        ja      error_dec

        ;; Check if msg_len == 0
        cmp     arg5, 0
        jz      skip_in_out_check_dec

        ;; Check if msg_len > max_len
        cmp     arg5, GCM_MAX_LENGTH
        ja      error_dec

        ;; Check out != NULL (msg_len != 0)
        cmp     arg3, 0
        jz      error_dec

        ;; Check in != NULL (msg_len != 0)
        cmp     arg4, 0
        jz      error_dec

skip_in_out_check_dec:
        ;; Check if aad_len == 0
        cmp     arg8, 0
        jz      skip_aad_check_dec

        ;; Check aad != NULL (aad_len != 0)
        cmp     arg7, 0
        jz      error_dec

skip_aad_check_dec:
%endif

	GCM_INIT arg1, arg2, arg6, arg7, arg8

	GCM_ENC_DEC  arg1, arg2, arg3, arg4, arg5, DEC

	GCM_COMPLETE arg1, arg2, arg9, arg10

exit_dec:
	FUNC_RESTORE

	ret

%ifdef SAFE_PARAM
error_dec:
        ;; Clear reg and imb_errno
        IMB_ERR_CHECK_START rax

        ;; Check key_data != NULL
        IMB_ERR_CHECK_NULL arg1, rax, IMB_ERR_NULL_EXP_KEY

        ;; Check context_data != NULL
        IMB_ERR_CHECK_NULL arg2, rax, IMB_ERR_NULL_CTX

        ;; Check IV != NULL
        IMB_ERR_CHECK_NULL arg6, rax, IMB_ERR_NULL_IV

        ;; Check auth_tag != NULL
        IMB_ERR_CHECK_NULL arg9, rax, IMB_ERR_NULL_AUTH

        ;; Check auth_tag_len == 0 or > 16
        IMB_ERR_CHECK_ZERO arg10, rax, IMB_ERR_AUTH_TAG_LEN

        IMB_ERR_CHECK_ABOVE arg10, 16, rax, IMB_ERR_AUTH_TAG_LEN

        ;; Check if msg_len == 0
        cmp     arg5, 0
        jz      skip_in_out_check_error_dec

        ;; Check if msg_len > max_len
        IMB_ERR_CHECK_ABOVE arg5, GCM_MAX_LENGTH, rax, IMB_ERR_CIPH_LEN

        ;; Check out != NULL (msg_len != 0)
        IMB_ERR_CHECK_NULL arg3, rax, IMB_ERR_NULL_DST

        ;; Check in != NULL (msg_len != 0)
        IMB_ERR_CHECK_NULL arg4, rax, IMB_ERR_NULL_SRC

skip_in_out_check_error_dec:
        ;; Check if aad_len == 0
        cmp     arg8, 0
        jz      skip_aad_check_error_dec

        ;; Check aad != NULL (aad_len != 0)
        IMB_ERR_CHECK_NULL arg7, rax, IMB_ERR_NULL_AAD

skip_aad_check_error_dec:

        ;; Set imb_errno
        IMB_ERR_CHECK_END rax
        jmp     exit_dec
%endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; NOTE: THIS API IS USED BY JOB-API ONLY, NO NEED FOR 2ND SAFE PARAM CHECK
;
;IMB_JOB *aes_gcm_enc_var_iv_128_sse / aes_gcm_enc_var_iv_192_sse /
;       aes_gcm_enc_var_iv_256_sse(IMB_MGR *state, IMB_JOB *job)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
align 32
MKGLOBAL(FN_NAME(enc_var_iv,_),function,internal)
FN_NAME(enc_var_iv,_):
        endbranch64
	FUNC_SAVE alloc_context

        mov     arg1, [arg2 + _enc_keys]

        cmp     qword [arg2 + _iv_len_in_bytes], 12
        je      iv_len_12_enc_IV

        GCM_INIT arg1, {rsp + CONTEXT_OFFSET}, {[arg2 + _iv]}, \
                 {[arg2 + _gcm_aad]}, {[arg2 + _gcm_aad_len]}, \
                 {[arg2 + _iv_len_in_bytes]}

        jmp     skip_iv_len_12_enc_IV

iv_len_12_enc_IV:
	GCM_INIT arg1, {rsp + CONTEXT_OFFSET}, {[arg2 + _iv]}, \
                 {[arg2 + _gcm_aad]}, {[arg2 + _gcm_aad_len]}

skip_iv_len_12_enc_IV:
        mov     arg3, [arg2 + _src]
        add     arg3, [arg2 + _cipher_start_src_offset]
        mov     arg4, [arg2 + _dst]
        mov     [rsp + GP_OFFSET + 5*8], arg2   ; preserve job pointer
        mov     arg2, [arg2 + _msg_len_to_cipher]
	GCM_ENC_DEC  arg1, {rsp + CONTEXT_OFFSET}, arg4, arg3, arg2, ENC

        mov     arg2, [rsp + GP_OFFSET + 5*8]
        GCM_COMPLETE arg1, {rsp + CONTEXT_OFFSET}, \
                     {[arg2 + _auth_tag_output]}, {[arg2 + _auth_tag_output_len_in_bytes]}

        ;; mark job complete
        mov     dword [arg2 + _status], IMB_STATUS_COMPLETED

        mov     rax, arg2       ;; return the job

        FUNC_RESTORE
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; NOTE: THIS API IS USED BY JOB-API ONLY, NO NEED FOR 2ND SAFE PARAM CHECK
;
;IMB_JOB *aes_gcm_dec_var_iv_128_sse / aes_gcm_dec_var_iv_192_sse /
;       aes_gcm_dec_var_iv_256_sse(IMB_MGR *state, IMB_JOB *job)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
align 32
MKGLOBAL(FN_NAME(dec_var_iv,_),function,internal)
FN_NAME(dec_var_iv,_):
        endbranch64
	FUNC_SAVE alloc_context

        mov     arg1, [arg2 + _dec_keys]

        cmp     qword [arg2 + _iv_len_in_bytes], 12
        je      iv_len_12_dec_IV

        GCM_INIT arg1, {rsp + CONTEXT_OFFSET}, {[arg2 + _iv]}, \
                 {[arg2 + _gcm_aad]}, {[arg2 + _gcm_aad_len]}, \
                 {[arg2 + _iv_len_in_bytes]}

        jmp     skip_iv_len_12_dec_IV

iv_len_12_dec_IV:
	GCM_INIT arg1, {rsp + CONTEXT_OFFSET}, {[arg2 + _iv]}, \
                 {[arg2 + _gcm_aad]}, {[arg2 + _gcm_aad_len]}

skip_iv_len_12_dec_IV:
        mov     arg3, [arg2 + _src]
        add     arg3, [arg2 + _cipher_start_src_offset]
        mov     arg4, [arg2 + _dst]
        mov     [rsp + GP_OFFSET + 5*8], arg2   ; preserve job pointer
        mov     arg2, [arg2 + _msg_len_to_cipher]
	GCM_ENC_DEC  arg1, {rsp + CONTEXT_OFFSET}, arg4, arg3, arg2, DEC

        mov     arg2, [rsp + GP_OFFSET + 5*8]
        GCM_COMPLETE arg1, {rsp + CONTEXT_OFFSET}, \
                     {[arg2 + _auth_tag_output]}, {[arg2 + _auth_tag_output_len_in_bytes]}

        ;; mark job complete
        mov     dword [arg2 + _status], IMB_STATUS_COMPLETED

        mov     rax, arg2       ;; return the job

        FUNC_RESTORE
	ret

mksection stack-noexec
%endif ; GCM_API_SSE_INC
