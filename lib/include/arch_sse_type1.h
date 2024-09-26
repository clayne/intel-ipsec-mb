/*******************************************************************************
  Copyright (c) 2022-2023, Intel Corporation

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

/* ARCH SSE TYPE 1: SSE4.2, AESNI, PCLMULQDQ, CMOV, BSWAP */

#ifndef IMB_ARCH_SSE_TYPE1_H
#define IMB_ARCH_SSE_TYPE1_H

#include "intel-ipsec-mb.h"
#include "ipsec_ooo_mgr.h"

/* AES-CBC */
void
aes_cbc_enc_128_x8_sse(AES_ARGS *args, uint64_t len_in_bytes);
void
aes_cbc_enc_192_x8_sse(AES_ARGS *args, uint64_t len_in_bytes);
void
aes_cbc_enc_256_x8_sse(AES_ARGS *args, uint64_t len_in_bytes);

IMB_JOB *
submit_job_aes128_enc_x8_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes128_enc_x8_sse(MB_MGR_AES_OOO *state);

IMB_JOB *
submit_job_aes192_enc_x8_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes192_enc_x8_sse(MB_MGR_AES_OOO *state);

IMB_JOB *
submit_job_aes256_enc_x8_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes256_enc_x8_sse(MB_MGR_AES_OOO *state);

void
aes_cbc_dec_128_by8_sse(const void *in, const uint8_t *IV, const void *keys, void *out,
                        uint64_t len_bytes);
void
aes_cbc_dec_192_by8_sse(const void *in, const uint8_t *IV, const void *keys, void *out,
                        uint64_t len_bytes);
void
aes_cbc_dec_256_by8_sse(const void *in, const uint8_t *IV, const void *keys, void *out,
                        uint64_t len_bytes);

/* AES-CTR */
void
aes_cntr_256_sse(const void *in, const void *IV, const void *keys, void *out, uint64_t len_bytes,
                 uint64_t IV_len);
void
aes_cntr_192_sse(const void *in, const void *IV, const void *keys, void *out, uint64_t len_bytes,
                 uint64_t IV_len);
void
aes_cntr_128_sse(const void *in, const void *IV, const void *keys, void *out, uint64_t len_bytes,
                 uint64_t IV_len);

/* AES-CTR-BITLEN */
void
aes_cntr_bit_256_sse(const void *in, const void *IV, const void *keys, void *out, uint64_t len_bits,
                     uint64_t IV_len);
void
aes_cntr_bit_192_sse(const void *in, const void *IV, const void *keys, void *out, uint64_t len_bits,
                     uint64_t IV_len);
void
aes_cntr_bit_128_sse(const void *in, const void *IV, const void *keys, void *out, uint64_t len_bits,
                     uint64_t IV_len);

/* AES-CCM */
IMB_JOB *
aes_cntr_ccm_128_sse(IMB_JOB *job);

IMB_JOB *
aes_cntr_ccm_256_sse(IMB_JOB *job);

/* AES-ECB */
void
aes_ecb_enc_256_by8_sse(const void *in, const void *keys, void *out, uint64_t len_bytes);
void
aes_ecb_enc_192_by8_sse(const void *in, const void *keys, void *out, uint64_t len_bytes);
void
aes_ecb_enc_128_by8_sse(const void *in, const void *keys, void *out, uint64_t len_bytes);

void
aes_ecb_dec_256_by8_sse(const void *in, const void *keys, void *out, uint64_t len_bytes);
void
aes_ecb_dec_192_by8_sse(const void *in, const void *keys, void *out, uint64_t len_bytes);
void
aes_ecb_dec_128_by8_sse(const void *in, const void *keys, void *out, uint64_t len_bytes);

void
aes_ecb_quic_enc_128_sse(const void *in, const void *keys, void *out, uint64_t num_buffers);
void
aes_ecb_quic_enc_256_sse(const void *in, const void *keys, void *out, uint64_t num_buffers);

/* AES128-ECBENC */
void
aes128_ecbenc_x3_sse(const void *in, void *keys, void *out1, void *out2, void *out3);

/* AES-CBCS */
void
aes_cbcs_1_9_dec_128_sse(const void *in, const uint8_t *IV, const void *keys, void *out,
                         uint64_t len_bytes, void *next_iv);

/* AES-CFB */
IMB_DLL_EXPORT void
aes_cfb_128_one_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);
IMB_DLL_EXPORT void
aes_cfb_256_one_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);

void
aes_cfb_128_enc_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);
void
aes_cfb_192_enc_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);
void
aes_cfb_256_enc_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);
void
aes_cfb_128_dec_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);
void
aes_cfb_192_dec_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);
void
aes_cfb_256_dec_sse(void *out, const void *in, const void *iv, const void *keys, uint64_t len);

/* stitched AES128-CNTR, CRC32 and BIP */
IMB_JOB *
submit_job_pon_enc_sse(IMB_JOB *job);
IMB_JOB *
submit_job_pon_dec_sse(IMB_JOB *job);

IMB_JOB *
submit_job_pon_enc_no_ctr_sse(IMB_JOB *job);
IMB_JOB *
submit_job_pon_dec_no_ctr_sse(IMB_JOB *job);

/* CRC */
uint32_t
ethernet_fcs_sse(const void *msg, const uint64_t len);
uint32_t
crc16_x25_sse(const void *msg, const uint64_t len);
uint32_t
crc32_sctp_sse(const void *msg, const uint64_t len);
uint32_t
crc24_lte_a_sse(const void *msg, const uint64_t len);
uint32_t
crc24_lte_b_sse(const void *msg, const uint64_t len);
uint32_t
crc16_fp_data_sse(const void *msg, const uint64_t len);
uint32_t
crc11_fp_header_sse(const void *msg, const uint64_t len);
uint32_t
crc7_fp_header_sse(const void *msg, const uint64_t len);
uint32_t
crc10_iuup_data_sse(const void *msg, const uint64_t len);
uint32_t
crc6_iuup_header_sse(const void *msg, const uint64_t len);
uint32_t
crc32_wimax_ofdma_data_sse(const void *msg, const uint64_t len);
uint32_t
crc8_wimax_ofdma_hcs_sse(const void *msg, const uint64_t len);
uint32_t
ethernet_fcs_sse_local(const void *msg, const uint64_t len, const void *tag_ouput);

/* SHA */
void
call_sha1_mult_sse_from_c(SHA1_ARGS *args, uint32_t size_in_blocks);
void
call_sha_256_mult_sse_from_c(SHA256_ARGS *args, uint32_t size_in_blocks);
void
call_sha512_x2_sse_from_c(SHA512_ARGS *args, uint64_t size_in_blocks);

void
sha1_block_sse(const void *, void *);
void
sha224_block_sse(const void *, void *);
void
sha256_block_sse(const void *, void *);
void
sha384_block_sse(const void *, void *);
void
sha512_block_sse(const void *, void *);

IMB_DLL_EXPORT void
sha1_sse(const void *data, const uint64_t length, void *digest);
IMB_DLL_EXPORT void
sha1_one_block_sse(const void *data, void *digest);
IMB_DLL_EXPORT void
sha224_sse(const void *data, const uint64_t length, void *digest);
IMB_DLL_EXPORT void
sha224_one_block_sse(const void *data, void *digest);
IMB_DLL_EXPORT void
sha256_sse(const void *data, const uint64_t length, void *digest);
IMB_DLL_EXPORT void
sha256_one_block_sse(const void *data, void *digest);
IMB_DLL_EXPORT void
sha384_sse(const void *data, const uint64_t length, void *digest);
IMB_DLL_EXPORT void
sha384_one_block_sse(const void *data, void *digest);
IMB_DLL_EXPORT void
sha512_sse(const void *data, const uint64_t length, void *digest);
IMB_DLL_EXPORT void
sha512_one_block_sse(const void *data, void *digest);

/* moved from MB MGR */
IMB_JOB *
submit_job_aes128_enc_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes128_enc_sse(MB_MGR_AES_OOO *state);

IMB_JOB *
submit_job_aes192_enc_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes192_enc_sse(MB_MGR_AES_OOO *state);

IMB_JOB *
submit_job_aes256_enc_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes256_enc_sse(MB_MGR_AES_OOO *state);

IMB_JOB *
submit_job_hmac_sse(MB_MGR_HMAC_SHA_1_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_hmac_sse(MB_MGR_HMAC_SHA_1_OOO *state);

IMB_JOB *
submit_job_hmac_sha_224_sse(MB_MGR_HMAC_SHA_256_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_hmac_sha_224_sse(MB_MGR_HMAC_SHA_256_OOO *state);

IMB_JOB *
submit_job_hmac_sha_256_sse(MB_MGR_HMAC_SHA_256_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_hmac_sha_256_sse(MB_MGR_HMAC_SHA_256_OOO *state);

IMB_JOB *
submit_job_hmac_sha_384_sse(MB_MGR_HMAC_SHA_512_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_hmac_sha_384_sse(MB_MGR_HMAC_SHA_512_OOO *state);

IMB_JOB *
submit_job_hmac_sha_512_sse(MB_MGR_HMAC_SHA_512_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_hmac_sha_512_sse(MB_MGR_HMAC_SHA_512_OOO *state);

IMB_JOB *
submit_job_hmac_md5_sse(MB_MGR_HMAC_MD5_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_hmac_md5_sse(MB_MGR_HMAC_MD5_OOO *state);

IMB_JOB *
submit_job_aes_xcbc_sse(MB_MGR_AES_XCBC_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_aes_xcbc_sse(MB_MGR_AES_XCBC_OOO *state);

IMB_JOB *
submit_job_aes128_cmac_auth_x8_sse(MB_MGR_CMAC_OOO *state, IMB_JOB *job);

IMB_JOB *
flush_job_aes128_cmac_auth_x8_sse(MB_MGR_CMAC_OOO *state);

IMB_JOB *
submit_job_aes256_cmac_auth_x8_sse(MB_MGR_CMAC_OOO *state, IMB_JOB *job);

IMB_JOB *
flush_job_aes256_cmac_auth_x8_sse(MB_MGR_CMAC_OOO *state);

IMB_JOB *
submit_job_aes128_ccm_auth_x8_sse(MB_MGR_CCM_OOO *state, IMB_JOB *job);

IMB_JOB *
flush_job_aes128_ccm_auth_x8_sse(MB_MGR_CCM_OOO *state);

IMB_JOB *
submit_job_aes256_ccm_auth_x8_sse(MB_MGR_CCM_OOO *state, IMB_JOB *job);

IMB_JOB *
flush_job_aes256_ccm_auth_x8_sse(MB_MGR_CCM_OOO *state);

IMB_JOB *
submit_job_zuc_eea3_no_gfni_sse(MB_MGR_ZUC_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_zuc_eea3_no_gfni_sse(MB_MGR_ZUC_OOO *state);

IMB_JOB *
submit_job_zuc256_eea3_no_gfni_sse(MB_MGR_ZUC_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_zuc256_eea3_no_gfni_sse(MB_MGR_ZUC_OOO *state);

IMB_JOB *
submit_job_zuc_eia3_no_gfni_sse(MB_MGR_ZUC_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_zuc_eia3_no_gfni_sse(MB_MGR_ZUC_OOO *state);

IMB_JOB *
submit_job_zuc256_eia3_no_gfni_sse(MB_MGR_ZUC_OOO *state, IMB_JOB *job, const uint64_t tag_sz);
IMB_JOB *
flush_job_zuc256_eia3_no_gfni_sse(MB_MGR_ZUC_OOO *state, const uint64_t tag_sz);

IMB_JOB *
submit_job_sha1_sse(MB_MGR_SHA_1_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_sha1_sse(MB_MGR_SHA_1_OOO *state, IMB_JOB *job);

IMB_JOB *
submit_job_sha224_sse(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_sha224_sse(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);

IMB_JOB *
submit_job_sha256_sse(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_sha256_sse(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);

IMB_JOB *
submit_job_sha384_sse(MB_MGR_SHA_512_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_sha384_sse(MB_MGR_SHA_512_OOO *state, IMB_JOB *job);

IMB_JOB *
submit_job_sha512_sse(MB_MGR_SHA_512_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_sha512_sse(MB_MGR_SHA_512_OOO *state, IMB_JOB *job);

void
aes_cmac_256_subkey_gen_sse(const void *key_exp, void *key1, void *key2);
uint32_t
hec_32_sse(const uint8_t *in);
uint64_t
hec_64_sse(const uint8_t *in);

IMB_JOB *
submit_job_aes128_cbcs_1_9_enc_sse(MB_MGR_AES_OOO *state, IMB_JOB *job);

IMB_JOB *
flush_job_aes128_cbcs_1_9_enc_sse(MB_MGR_AES_OOO *state);

IMB_JOB *
submit_job_chacha20_enc_dec_sse(IMB_JOB *job);

IMB_JOB *
snow_v_sse(IMB_JOB *job);
IMB_JOB *
snow_v_aead_init_sse(IMB_JOB *job);

IMB_JOB *
submit_job_snow3g_uea2_sse(MB_MGR_SNOW3G_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_snow3g_uea2_sse(MB_MGR_SNOW3G_OOO *state);

IMB_JOB *
submit_job_snow3g_uia2_sse(MB_MGR_SNOW3G_OOO *state, IMB_JOB *job);
IMB_JOB *
flush_job_snow3g_uia2_sse(MB_MGR_SNOW3G_OOO *state);

/* SM4 */
void
sm4_ecb_sse(const void *in, void *out, const uint64_t size, const void *exp_keys);

void
sm4_cbc_enc_sse(const void *in, void *out, const uint64_t size, const void *exp_enc_keys,
                const void *iv);
void
sm4_cbc_dec_sse(const void *in, void *out, const uint64_t size, const void *exp_dec_keys,
                const void *iv);
void
sm4_cntr_sse(const void *in, void *out, const uint64_t size, const void *exp_enc_keys,
             const void *iv, const uint64_t iv_len);

void
sm4_set_key_sse(const void *pKey, void *exp_enc_keys, void *exp_dec_keys);

/* SM3 */
void
sm3_one_block_sse(void *tag, const void *msg);
void
sm3_msg_sse(void *tag, const uint64_t tag_length, const void *msg, const uint64_t msg_length);
IMB_JOB *
sm3_hmac_submit_sse(IMB_JOB *job);
IMB_JOB *
sm3_msg_submit_sse(IMB_JOB *job);

/* suite id */
IMB_DLL_EXPORT void
set_suite_id_sse_t1(IMB_MGR *state, IMB_JOB *job);

#endif /* IMB_ARCH_SSE_TYPE1_H */
