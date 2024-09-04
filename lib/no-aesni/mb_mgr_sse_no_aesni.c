/*******************************************************************************
  Copyright (c) 2018-2023, Intel Corporation

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

      * Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of Intel Corporation nor the names of its contributors
        may be used to endorse or promote products derived from this software
        without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SSE_AESNI_EMU

#include "intel-ipsec-mb.h"
#include "include/ipsec_ooo_mgr.h"
#include "include/kasumi_interface.h"
#include "include/zuc_internal.h"
#include "include/snow3g.h"
#include "include/chacha20_poly1305.h"

#include "include/save_xmms.h"
#include "include/des.h"
#include "include/gcm.h"
#include "include/noaesni.h"
#include "include/error.h"
#include "include/arch_x86_64.h" /* self-test */
#include "include/arch_noaesni.h"
#include "include/arch_sse_type1.h"

#include "include/ooo_mgr_reset.h"

/* ====================================================================== */

#define SAVE_XMMS    save_xmms
#define RESTORE_XMMS restore_xmms

#define SUBMIT_JOB_AES_CBC_128_ENC submit_job_aes128_enc_sse_no_aesni
#define SUBMIT_JOB_AES_CBC_128_DEC submit_job_aes128_dec_sse_no_aesni
#define FLUSH_JOB_AES_CBC_128_ENC  flush_job_aes128_enc_sse_no_aesni
#define SUBMIT_JOB_AES_CBC_192_ENC submit_job_aes192_enc_sse_no_aesni
#define SUBMIT_JOB_AES_CBC_192_DEC submit_job_aes192_dec_sse_no_aesni
#define FLUSH_JOB_AES_CBC_192_ENC  flush_job_aes192_enc_sse_no_aesni
#define SUBMIT_JOB_AES_CBC_256_ENC submit_job_aes256_enc_sse_no_aesni
#define SUBMIT_JOB_AES_CBC_256_DEC submit_job_aes256_dec_sse_no_aesni
#define FLUSH_JOB_AES_CBC_256_ENC  flush_job_aes256_enc_sse_no_aesni
#define SUBMIT_JOB_AES_ECB_128_ENC submit_job_aes_ecb_128_enc_sse_no_aesni
#define SUBMIT_JOB_AES_ECB_128_DEC submit_job_aes_ecb_128_dec_sse_no_aesni
#define SUBMIT_JOB_AES_ECB_192_ENC submit_job_aes_ecb_192_enc_sse_no_aesni
#define SUBMIT_JOB_AES_ECB_192_DEC submit_job_aes_ecb_192_dec_sse_no_aesni
#define SUBMIT_JOB_AES_ECB_256_ENC submit_job_aes_ecb_256_enc_sse_no_aesni
#define SUBMIT_JOB_AES_ECB_256_DEC submit_job_aes_ecb_256_dec_sse_no_aesni
#define SUBMIT_JOB_HMAC            submit_job_hmac_sse
#define FLUSH_JOB_HMAC             flush_job_hmac_sse
#define SUBMIT_JOB_HMAC_NI         submit_job_hmac_sse
#define FLUSH_JOB_HMAC_NI          flush_job_hmac_sse
#define SUBMIT_JOB_HMAC_SHA_224    submit_job_hmac_sha_224_sse
#define FLUSH_JOB_HMAC_SHA_224     flush_job_hmac_sha_224_sse
#define SUBMIT_JOB_HMAC_SHA_224_NI submit_job_hmac_sha_224_sse
#define FLUSH_JOB_HMAC_SHA_224_NI  flush_job_hmac_sha_224_sse
#define SUBMIT_JOB_HMAC_SHA_256    submit_job_hmac_sha_256_sse
#define FLUSH_JOB_HMAC_SHA_256     flush_job_hmac_sha_256_sse
#define SUBMIT_JOB_HMAC_SHA_256_NI submit_job_hmac_sha_256_sse
#define FLUSH_JOB_HMAC_SHA_256_NI  flush_job_hmac_sha_256_sse
#define SUBMIT_JOB_HMAC_SHA_384    submit_job_hmac_sha_384_sse
#define FLUSH_JOB_HMAC_SHA_384     flush_job_hmac_sha_384_sse
#define SUBMIT_JOB_HMAC_SHA_512    submit_job_hmac_sha_512_sse
#define FLUSH_JOB_HMAC_SHA_512     flush_job_hmac_sha_512_sse
#define SUBMIT_JOB_HMAC_MD5        submit_job_hmac_md5_sse
#define FLUSH_JOB_HMAC_MD5         flush_job_hmac_md5_sse
#define SUBMIT_JOB_AES_XCBC        submit_job_aes_xcbc_sse_no_aesni
#define FLUSH_JOB_AES_XCBC         flush_job_aes_xcbc_sse_no_aesni
#define SUBMIT_JOB_SHA1            submit_job_sha1_sse
#define FLUSH_JOB_SHA1             flush_job_sha1_sse
#define SUBMIT_JOB_SHA224          submit_job_sha224_sse
#define FLUSH_JOB_SHA224           flush_job_sha224_sse
#define SUBMIT_JOB_SHA256          submit_job_sha256_sse
#define FLUSH_JOB_SHA256           flush_job_sha256_sse
#define SUBMIT_JOB_SHA1_NI         submit_job_sha1_ni_sse
#define FLUSH_JOB_SHA1_NI          flush_job_sha1_ni_sse
#define SUBMIT_JOB_SHA224_NI       submit_job_sha224_ni_sse
#define FLUSH_JOB_SHA224_NI        flush_job_sha224_ni_sse
#define SUBMIT_JOB_SHA256_NI       submit_job_sha256_ni_sse
#define FLUSH_JOB_SHA256_NI        flush_job_sha256_ni_sse
#define SUBMIT_JOB_SHA384          submit_job_sha384_sse
#define FLUSH_JOB_SHA384           flush_job_sha384_sse
#define SUBMIT_JOB_SHA512          submit_job_sha512_sse
#define FLUSH_JOB_SHA512           flush_job_sha512_sse

#define SUBMIT_JOB_ZUC_EEA3    submit_job_zuc_eea3_sse_no_aesni
#define FLUSH_JOB_ZUC_EEA3     flush_job_zuc_eea3_sse_no_aesni
#define SUBMIT_JOB_ZUC_EIA3    submit_job_zuc_eia3_sse_no_aesni
#define FLUSH_JOB_ZUC_EIA3     flush_job_zuc_eia3_sse_no_aesni
#define SUBMIT_JOB_ZUC256_EEA3 submit_job_zuc256_eea3_sse_no_aesni
#define FLUSH_JOB_ZUC256_EEA3  flush_job_zuc256_eea3_sse_no_aesni
#define SUBMIT_JOB_ZUC256_EIA3 submit_job_zuc256_eia3_sse_no_aesni
#define FLUSH_JOB_ZUC256_EIA3  flush_job_zuc256_eia3_sse_no_aesni

#define AES_CBC_DEC_128 aes_cbc_dec_128_sse_no_aesni
#define AES_CBC_DEC_192 aes_cbc_dec_192_sse_no_aesni
#define AES_CBC_DEC_256 aes_cbc_dec_256_sse_no_aesni

#define AES_CTR_128     aes_cntr_128_sse_no_aesni
#define AES_CTR_192     aes_cntr_192_sse_no_aesni
#define AES_CTR_256     aes_cntr_256_sse_no_aesni
#define AES_CTR_128_BIT aes_cntr_bit_128_sse_no_aesni
#define AES_CTR_192_BIT aes_cntr_bit_192_sse_no_aesni
#define AES_CTR_256_BIT aes_cntr_bit_256_sse_no_aesni

#define AES_CNTR_CCM_128 aes_cntr_ccm_128_sse_no_aesni
#define AES_CNTR_CCM_256 aes_cntr_ccm_256_sse_no_aesni

#define AES_ECB_ENC_128 aes_ecb_enc_128_sse_no_aesni
#define AES_ECB_ENC_192 aes_ecb_enc_192_sse_no_aesni
#define AES_ECB_ENC_256 aes_ecb_enc_256_sse_no_aesni
#define AES_ECB_DEC_128 aes_ecb_dec_128_sse_no_aesni
#define AES_ECB_DEC_192 aes_ecb_dec_192_sse_no_aesni
#define AES_ECB_DEC_256 aes_ecb_dec_256_sse_no_aesni

#define SUBMIT_JOB_PON_ENC        submit_job_pon_enc_sse_no_aesni
#define SUBMIT_JOB_PON_DEC        submit_job_pon_dec_sse_no_aesni
#define SUBMIT_JOB_PON_ENC_NO_CTR submit_job_pon_enc_no_ctr_sse_no_aesni
#define SUBMIT_JOB_PON_DEC_NO_CTR submit_job_pon_dec_no_ctr_sse_no_aesni

#define AES_GCM_DEC_IV_128 aes_gcm_dec_var_iv_128_sse_no_aesni
#define AES_GCM_ENC_IV_128 aes_gcm_enc_var_iv_128_sse_no_aesni
#define AES_GCM_DEC_IV_192 aes_gcm_dec_var_iv_192_sse_no_aesni
#define AES_GCM_ENC_IV_192 aes_gcm_enc_var_iv_192_sse_no_aesni
#define AES_GCM_DEC_IV_256 aes_gcm_dec_var_iv_256_sse_no_aesni
#define AES_GCM_ENC_IV_256 aes_gcm_enc_var_iv_256_sse_no_aesni

#define SUBMIT_JOB_AES_GCM_DEC submit_job_aes_gcm_dec_sse_no_aesni
#define SUBMIT_JOB_AES_GCM_ENC submit_job_aes_gcm_enc_sse_no_aesni

/* ====================================================================== */

#define SUBMIT_JOB                  submit_job_sse_no_aesni
#define FLUSH_JOB                   flush_job_sse_no_aesni
#define SUBMIT_JOB_NOCHECK          submit_job_nocheck_sse_no_aesni
#define GET_NEXT_JOB                get_next_job_sse_no_aesni
#define GET_COMPLETED_JOB           get_completed_job_sse_no_aesni
#define GET_NEXT_BURST              get_next_burst_sse_no_aesni
#define SUBMIT_BURST                submit_burst_sse_no_aesni
#define SUBMIT_BURST_NOCHECK        submit_burst_nocheck_sse_no_aesni
#define FLUSH_BURST                 flush_burst_sse_no_aesni
#define SUBMIT_CIPHER_BURST         submit_cipher_burst_sse_no_aesni
#define SUBMIT_CIPHER_BURST_NOCHECK submit_cipher_burst_nocheck_sse_no_aesni
#define SUBMIT_HASH_BURST           submit_hash_burst_sse_no_aesni
#define SUBMIT_HASH_BURST_NOCHECK   submit_hash_burst_nocheck_sse_no_aesni
#define SUBMIT_AEAD_BURST           submit_aead_burst_sse_no_aesni
#define SUBMIT_AEAD_BURST_NOCHECK   submit_aead_burst_nocheck_sse_no_aesni
#define SET_SUITE_ID_FN             set_suite_id_sse_no_aesni

#define SUBMIT_JOB_AES128_DEC submit_job_aes128_dec_sse_no_aesni
#define SUBMIT_JOB_AES192_DEC submit_job_aes192_dec_sse_no_aesni
#define SUBMIT_JOB_AES256_DEC submit_job_aes256_dec_sse_no_aesni
#define QUEUE_SIZE            queue_size_sse_no_aesni

/* ====================================================================== */

#define SUBMIT_JOB_CIPHER_ENC SUBMIT_JOB_CIPHER_ENC_SSE
#define FLUSH_JOB_CIPHER_ENC  FLUSH_JOB_CIPHER_ENC_SSE
#define SUBMIT_JOB_CIPHER_DEC SUBMIT_JOB_CIPHER_DEC_SSE
#define SUBMIT_JOB_HASH       SUBMIT_JOB_HASH_SSE
#define FLUSH_JOB_HASH        FLUSH_JOB_HASH_SSE

/* ====================================================================== */

#define AES_CFB_128_ONE aes_cfb_128_one_sse_no_aesni
#define AES_CFB_256_ONE aes_cfb_256_one_sse_no_aesni

#define AES_CFB_128_ENC aes_cfb_128_enc_sse_no_aesni
#define AES_CFB_192_ENC aes_cfb_192_enc_sse_no_aesni
#define AES_CFB_256_ENC aes_cfb_256_enc_sse_no_aesni

#define AES_CFB_128_DEC aes_cfb_128_dec_sse_no_aesni
#define AES_CFB_192_DEC aes_cfb_192_dec_sse_no_aesni
#define AES_CFB_256_DEC aes_cfb_256_dec_sse_no_aesni

#define AES128_CBC_MAC aes128_cbc_mac_x4_no_aesni

#define FLUSH_JOB_AES128_CCM_AUTH  flush_job_aes128_ccm_auth_sse_no_aesni
#define SUBMIT_JOB_AES128_CCM_AUTH submit_job_aes128_ccm_auth_sse_no_aesni

#define FLUSH_JOB_AES256_CCM_AUTH  flush_job_aes256_ccm_auth_sse_no_aesni
#define SUBMIT_JOB_AES256_CCM_AUTH submit_job_aes256_ccm_auth_sse_no_aesni

#define FLUSH_JOB_AES128_CMAC_AUTH  flush_job_aes128_cmac_auth_sse_no_aesni
#define SUBMIT_JOB_AES128_CMAC_AUTH submit_job_aes128_cmac_auth_sse_no_aesni

#define FLUSH_JOB_AES256_CMAC_AUTH  flush_job_aes256_cmac_auth_sse_no_aesni
#define SUBMIT_JOB_AES256_CMAC_AUTH submit_job_aes256_cmac_auth_sse_no_aesni

/* ====================================================================== */

#define SUBMIT_JOB_AES128_CBCS_1_9_ENC   submit_job_aes128_cbcs_1_9_enc_sse_no_aesni
#define FLUSH_JOB_AES128_CBCS_1_9_ENC    flush_job_aes128_cbcs_1_9_enc_sse_no_aesni
#define SUBMIT_JOB_AES128_CBCS_1_9_DEC   submit_job_aes128_cbcs_1_9_dec_sse_no_aesni
#define AES_CBCS_1_9_DEC_128             aes_cbcs_1_9_dec_128_sse_no_aesni
#define SUBMIT_JOB_CHACHA20_ENC_DEC      submit_job_chacha20_enc_dec_sse
#define SUBMIT_JOB_CHACHA20_POLY1305     aead_chacha20_poly1305_sse
#define SUBMIT_JOB_CHACHA20_POLY1305_SGL aead_chacha20_poly1305_sgl_sse
#define POLY1305_MAC                     poly1305_mac_scalar

#define SUBMIT_JOB_SNOW_V      snow_v_sse_no_aesni
#define SUBMIT_JOB_SNOW_V_AEAD snow_v_aead_init_sse_no_aesni

/* ====================================================================== */

#define ETHERNET_FCS ethernet_fcs_sse_no_aesni_local

/* ====================================================================== */

/* SM4 */
#define SM4_ECB     sm4_ecb_sse_no_aesni
#define SM4_CBC_ENC sm4_cbc_enc_sse_no_aesni
#define SM4_CBC_DEC sm4_cbc_dec_sse_no_aesni

/* SM3 */
#define SUBMIT_JOB_SM3      sm3_msg_submit_sse
#define FLUSH_JOB_SM3       unused
#define SUBMIT_JOB_HMAC_SM3 sm3_hmac_submit_sse
#define FLUSH_JOB_HMAC_SM3  unused

static void
reset_ooo_mgrs(IMB_MGR *state)
{
        /* Init AES out-of-order fields */
        ooo_mgr_aes_reset(state->aes128_ooo, 4);
        ooo_mgr_aes_reset(state->aes192_ooo, 4);
        ooo_mgr_aes_reset(state->aes256_ooo, 4);

        /* DOCSIS SEC BPI uses same settings as AES CBC */
        ooo_mgr_docsis_aes_reset(state->docsis128_sec_ooo, 4);
        ooo_mgr_docsis_aes_reset(state->docsis128_crc32_sec_ooo, 4);
        ooo_mgr_docsis_aes_reset(state->docsis256_sec_ooo, 4);
        ooo_mgr_docsis_aes_reset(state->docsis256_crc32_sec_ooo, 4);

        /* Init ZUC out-of-order fields */
        ooo_mgr_zuc_reset(state->zuc_eea3_ooo, 4);
        ooo_mgr_zuc_reset(state->zuc_eia3_ooo, 4);
        ooo_mgr_zuc_reset(state->zuc256_eea3_ooo, 4);
        ooo_mgr_zuc_reset(state->zuc256_eia3_ooo, 4);
        ooo_mgr_zuc_reset(state->zuc256_eia3_8B_ooo, 4);
        ooo_mgr_zuc_reset(state->zuc256_eia3_16B_ooo, 4);

        /* Init HMAC/SHA1 out-of-order fields */
        ooo_mgr_hmac_sha1_reset(state->hmac_sha_1_ooo, SSE_NUM_SHA1_LANES);

        /* Init HMAC/SHA224 out-of-order fields */
        ooo_mgr_hmac_sha224_reset(state->hmac_sha_224_ooo, SSE_NUM_SHA256_LANES);

        /* Init HMAC/SHA_256 out-of-order fields */
        ooo_mgr_hmac_sha256_reset(state->hmac_sha_256_ooo, SSE_NUM_SHA256_LANES);

        /* Init HMAC/SHA384 out-of-order fields */
        ooo_mgr_hmac_sha384_reset(state->hmac_sha_384_ooo, SSE_NUM_SHA512_LANES);

        /* Init HMAC/SHA512 out-of-order fields */
        ooo_mgr_hmac_sha512_reset(state->hmac_sha_512_ooo, SSE_NUM_SHA512_LANES);

        /* Init HMAC/MD5 out-of-order fields */
        ooo_mgr_hmac_md5_reset(state->hmac_md5_ooo, SSE_NUM_MD5_LANES);

        /* Init AES/XCBC OOO fields */
        ooo_mgr_aes_xcbc_reset(state->aes_xcbc_ooo, 4);

        /* Init AES-CCM auth out-of-order fields */
        ooo_mgr_ccm_reset(state->aes_ccm_ooo, 4);
        ooo_mgr_ccm_reset(state->aes256_ccm_ooo, 4);

        /* Init AES-CMAC auth out-of-order fields */
        ooo_mgr_cmac_reset(state->aes_cmac_ooo, 4);
        ooo_mgr_cmac_reset(state->aes256_cmac_ooo, 4);

        /* Init AES-CBCS out-of-order fields */
        ooo_mgr_aes_reset(state->aes128_cbcs_ooo, 4);

        /* Init SHA1 out-of-order fields */
        ooo_mgr_sha1_reset(state->sha_1_ooo, SSE_NUM_SHA1_LANES);

        /* Init SHA224 out-of-order fields */
        ooo_mgr_sha256_reset(state->sha_224_ooo, SSE_NUM_SHA256_LANES);

        /* Init SHA256 out-of-order fields */
        ooo_mgr_sha256_reset(state->sha_256_ooo, SSE_NUM_SHA256_LANES);

        /* Init SHA384 out-of-order fields */
        ooo_mgr_sha512_reset(state->sha_384_ooo, SSE_NUM_SHA512_LANES);

        /* Init SHA512 out-of-order fields */
        ooo_mgr_sha512_reset(state->sha_512_ooo, SSE_NUM_SHA512_LANES);

        /* Init SNOW3G-UEA out-of-order fields */
        ooo_mgr_snow3g_reset(state->snow3g_uea2_ooo, 4);

        /* Init SNOW3G-UIA out-of-order fields */
        ooo_mgr_snow3g_reset(state->snow3g_uia2_ooo, 4);

        /*  Init AES-CFB out-of-order fields */
        ooo_mgr_aes_reset(state->aes_cfb_128_ooo, 1);
        ooo_mgr_aes_reset(state->aes_cfb_192_ooo, 1);
        ooo_mgr_aes_reset(state->aes_cfb_256_ooo, 1);
}

IMB_DLL_LOCAL void
init_mb_mgr_sse_no_aesni_internal(IMB_MGR *state, const int reset_mgrs)
{
#ifdef SAFE_PARAM
        if (state == NULL) {
                imb_set_errno(NULL, IMB_ERR_NULL_MBMGR);
                return;
        }
#endif

        /* reset error status */
        imb_set_errno(state, 0);

        /* Check if CPU flags needed for NO_AESNI interface are present */
        if ((state->features & IMB_CPUFLAGS_NO_AESNI) != IMB_CPUFLAGS_NO_AESNI) {
                imb_set_errno(state, IMB_ERR_MISSING_CPUFLAGS_INIT_MGR);
                return;
        }

        /* Set architecture for future checks */
        state->used_arch = (uint32_t) IMB_ARCH_NOAESNI;

        /* Set architecture type for future checks */
        state->used_arch_type = 1;

        if (reset_mgrs) {
                reset_ooo_mgrs(state);

                /* Init "in order" components */
                state->next_job = 0;
                state->earliest_job = -1;
        }

        /* set SSE NO AESNI handlers */
        state->get_next_job = get_next_job_sse_no_aesni;
        state->submit_job = submit_job_sse_no_aesni;
        state->get_next_burst = get_next_burst_sse_no_aesni;
        state->submit_burst = submit_burst_sse_no_aesni;
        state->submit_burst_nocheck = submit_burst_nocheck_sse_no_aesni;
        state->flush_burst = flush_burst_sse_no_aesni;
        state->submit_cipher_burst = submit_cipher_burst_sse_no_aesni;
        state->submit_cipher_burst_nocheck = submit_cipher_burst_nocheck_sse_no_aesni;
        state->submit_hash_burst = submit_hash_burst_sse_no_aesni;
        state->submit_hash_burst_nocheck = submit_hash_burst_nocheck_sse_no_aesni;
        state->submit_aead_burst = submit_aead_burst_sse_no_aesni;
        state->submit_aead_burst_nocheck = submit_aead_burst_nocheck_sse_no_aesni;
        state->submit_job_nocheck = submit_job_nocheck_sse_no_aesni;
        state->get_completed_job = get_completed_job_sse_no_aesni;
        state->flush_job = flush_job_sse_no_aesni;
        state->queue_size = queue_size_sse_no_aesni;
        state->keyexp_128 = aes_keyexp_128_sse_no_aesni;
        state->keyexp_192 = aes_keyexp_192_sse_no_aesni;
        state->keyexp_256 = aes_keyexp_256_sse_no_aesni;
        state->cmac_subkey_gen_128 = aes_cmac_subkey_gen_sse_no_aesni;
        state->cmac_subkey_gen_256 = aes_cmac_256_subkey_gen_sse_no_aesni;
        state->xcbc_keyexp = aes_xcbc_expand_key_sse_no_aesni;
        state->des_key_sched = des_key_schedule;
        state->sha1_one_block = sha1_one_block_sse;
        state->sha1 = sha1_sse;
        state->sha224_one_block = sha224_one_block_sse;
        state->sha224 = sha224_sse;
        state->sha256_one_block = sha256_one_block_sse;
        state->sha256 = sha256_sse;
        state->sha384_one_block = sha384_one_block_sse;
        state->sha384 = sha384_sse;
        state->sha512_one_block = sha512_one_block_sse;
        state->sha512 = sha512_sse;
        state->md5_one_block = md5_one_block_sse;
        state->aes128_cfb_one = aes_cfb_128_one_sse_no_aesni;
        state->aes256_cfb_one = aes_cfb_256_one_sse_no_aesni;

        state->eea3_1_buffer = zuc_eea3_1_buffer_sse_no_aesni;
        state->eea3_4_buffer = zuc_eea3_4_buffer_sse_no_aesni;
        state->eea3_n_buffer = zuc_eea3_n_buffer_sse_no_aesni;
        state->eia3_1_buffer = zuc_eia3_1_buffer_sse_no_aesni;
        state->eia3_n_buffer = zuc_eia3_n_buffer_sse_no_aesni;

        state->f8_1_buffer = kasumi_f8_1_buffer_sse;
        state->f8_1_buffer_bit = kasumi_f8_1_buffer_bit_sse;
        state->f8_2_buffer = kasumi_f8_2_buffer_sse;
        state->f8_3_buffer = kasumi_f8_3_buffer_sse;
        state->f8_4_buffer = kasumi_f8_4_buffer_sse;
        state->f8_n_buffer = kasumi_f8_n_buffer_sse;
        state->f9_1_buffer = kasumi_f9_1_buffer_sse;
        state->f9_1_buffer_user = kasumi_f9_1_buffer_user_sse;
        state->kasumi_init_f8_key_sched = kasumi_init_f8_key_sched_sse;
        state->kasumi_init_f9_key_sched = kasumi_init_f9_key_sched_sse;
        state->kasumi_key_sched_size = kasumi_key_sched_size_sse;

        state->snow3g_f8_1_buffer_bit = snow3g_f8_1_buffer_bit_sse_no_aesni;
        state->snow3g_f8_1_buffer = snow3g_f8_1_buffer_sse_no_aesni;
        state->snow3g_f8_2_buffer = snow3g_f8_2_buffer_sse_no_aesni;
        state->snow3g_f8_4_buffer = snow3g_f8_4_buffer_sse_no_aesni;
        state->snow3g_f8_8_buffer = snow3g_f8_8_buffer_sse_no_aesni;
        state->snow3g_f8_n_buffer = snow3g_f8_n_buffer_sse_no_aesni;
        state->snow3g_f8_8_buffer_multikey = snow3g_f8_8_buffer_multikey_sse_no_aesni;
        state->snow3g_f8_n_buffer_multikey = snow3g_f8_n_buffer_multikey_sse_no_aesni;
        state->snow3g_f9_1_buffer = snow3g_f9_1_buffer_sse_no_aesni;
        state->snow3g_init_key_sched = snow3g_init_key_sched_sse_no_aesni;
        state->snow3g_key_sched_size = snow3g_key_sched_size_sse_no_aesni;

        state->gcm128_enc = aes_gcm_enc_128_sse_no_aesni;
        state->gcm192_enc = aes_gcm_enc_192_sse_no_aesni;
        state->gcm256_enc = aes_gcm_enc_256_sse_no_aesni;
        state->gcm128_dec = aes_gcm_dec_128_sse_no_aesni;
        state->gcm192_dec = aes_gcm_dec_192_sse_no_aesni;
        state->gcm256_dec = aes_gcm_dec_256_sse_no_aesni;
        state->gcm128_init = aes_gcm_init_128_sse_no_aesni;
        state->gcm192_init = aes_gcm_init_192_sse_no_aesni;
        state->gcm256_init = aes_gcm_init_256_sse_no_aesni;
        state->gcm128_init_var_iv = aes_gcm_init_var_iv_128_sse_no_aesni;
        state->gcm192_init_var_iv = aes_gcm_init_var_iv_192_sse_no_aesni;
        state->gcm256_init_var_iv = aes_gcm_init_var_iv_256_sse_no_aesni;
        state->gcm128_enc_update = aes_gcm_enc_128_update_sse_no_aesni;
        state->gcm192_enc_update = aes_gcm_enc_192_update_sse_no_aesni;
        state->gcm256_enc_update = aes_gcm_enc_256_update_sse_no_aesni;
        state->gcm128_dec_update = aes_gcm_dec_128_update_sse_no_aesni;
        state->gcm192_dec_update = aes_gcm_dec_192_update_sse_no_aesni;
        state->gcm256_dec_update = aes_gcm_dec_256_update_sse_no_aesni;
        state->gcm128_enc_finalize = aes_gcm_enc_128_finalize_sse_no_aesni;
        state->gcm192_enc_finalize = aes_gcm_enc_192_finalize_sse_no_aesni;
        state->gcm256_enc_finalize = aes_gcm_enc_256_finalize_sse_no_aesni;
        state->gcm128_dec_finalize = aes_gcm_dec_128_finalize_sse_no_aesni;
        state->gcm192_dec_finalize = aes_gcm_dec_192_finalize_sse_no_aesni;
        state->gcm256_dec_finalize = aes_gcm_dec_256_finalize_sse_no_aesni;
        state->gcm128_precomp = aes_gcm_precomp_128_sse_no_aesni;
        state->gcm192_precomp = aes_gcm_precomp_192_sse_no_aesni;
        state->gcm256_precomp = aes_gcm_precomp_256_sse_no_aesni;
        state->gcm128_pre = aes_gcm_pre_128_sse_no_aesni;
        state->gcm192_pre = aes_gcm_pre_192_sse_no_aesni;
        state->gcm256_pre = aes_gcm_pre_256_sse_no_aesni;
        state->ghash = ghash_sse_no_aesni;
        state->ghash_pre = ghash_pre_sse_no_aesni;

        state->gmac128_init = imb_aes_gmac_init_128_sse_no_aesni;
        state->gmac192_init = imb_aes_gmac_init_192_sse_no_aesni;
        state->gmac256_init = imb_aes_gmac_init_256_sse_no_aesni;
        state->gmac128_update = imb_aes_gmac_update_128_sse_no_aesni;
        state->gmac192_update = imb_aes_gmac_update_192_sse_no_aesni;
        state->gmac256_update = imb_aes_gmac_update_256_sse_no_aesni;
        state->gmac128_finalize = imb_aes_gmac_finalize_128_sse_no_aesni;
        state->gmac192_finalize = imb_aes_gmac_finalize_192_sse_no_aesni;
        state->gmac256_finalize = imb_aes_gmac_finalize_256_sse_no_aesni;

        state->hec_32 = hec_32_sse_no_aesni;
        state->hec_64 = hec_64_sse_no_aesni;
        state->crc32_ethernet_fcs = ethernet_fcs_sse_no_aesni;
        state->crc16_x25 = crc16_x25_sse_no_aesni;
        state->crc32_sctp = crc32_sctp_sse_no_aesni;
        state->crc24_lte_a = crc24_lte_a_sse_no_aesni;
        state->crc24_lte_b = crc24_lte_b_sse_no_aesni;
        state->crc16_fp_data = crc16_fp_data_sse_no_aesni;
        state->crc11_fp_header = crc11_fp_header_sse_no_aesni;
        state->crc7_fp_header = crc7_fp_header_sse_no_aesni;
        state->crc10_iuup_data = crc10_iuup_data_sse_no_aesni;
        state->crc6_iuup_header = crc6_iuup_header_sse_no_aesni;
        state->crc32_wimax_ofdma_data = crc32_wimax_ofdma_data_sse_no_aesni;
        state->crc8_wimax_ofdma_hcs = crc8_wimax_ofdma_hcs_sse_no_aesni;

        state->chacha20_poly1305_init = init_chacha20_poly1305_sse;
        state->chacha20_poly1305_enc_update = update_enc_chacha20_poly1305_sse;
        state->chacha20_poly1305_dec_update = update_dec_chacha20_poly1305_sse;
        state->chacha20_poly1305_finalize = finalize_chacha20_poly1305_sse;

        state->aes_ecb_128_quic = aes_ecb_quic_enc_128_sse_no_aesni;
        state->aes_ecb_256_quic = aes_ecb_quic_enc_256_sse_no_aesni;

        state->chacha20_poly1305_quic = aead_chacha20_poly1305_sse;
        state->chacha20_hp_quic = quic_hp_chacha20_sse;

        state->set_suite_id = SET_SUITE_ID_FN;

        state->sm4_keyexp = sm4_set_key_sse_no_aesni;
}

void
init_mb_mgr_sse_no_aesni(IMB_MGR *state)
{
        init_mb_mgr_sse_no_aesni_internal(state, 1);

        if (!self_test(state))
                imb_set_errno(state, IMB_ERR_SELFTEST);
}

#include "mb_mgr_code.h"
