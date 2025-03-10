/*******************************************************************************
 Copyright (c) 2025, Intel Corporation

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

#ifndef PROV_PROVIDER_H
#define PROV_PROVIDER_H

#include <openssl/core.h>
#include <openssl/provider.h>
#include <openssl/bio.h>
#include <openssl/core_dispatch.h>

#define PROV_PROVIDER_VERSION_STR      "v1.0"
#define PROV_PROVIDER_FULL_VERSION_STR "img-provider v1.0"
#define PROV_PROVIDER_NAME_STR         "imb-provider"

#define OSSL_NELEM(x)          (sizeof(x) / sizeof((x)[0]))
#define PROV_NAMES_AES_128_GCM "AES-128-GCM"
#define PROV_NAMES_AES_192_GCM "AES-192-GCM"
#define PROV_NAMES_AES_256_GCM "AES-256-GCM"

#define PROV_NAMES_SHA2_224 "SHA2-224:SHA-224:SHA224:2.16.840.1.101.3.4.2.4"
#define PROV_NAMES_SHA2_256 "SHA2-256:SHA-256:SHA256:2.16.840.1.101.3.4.2.1"
#define PROV_NAMES_SHA2_384 "SHA2-384:SHA-384:SHA384:2.16.840.1.101.3.4.2.2"
#define PROV_NAMES_SHA2_512 "SHA2-512:SHA-512:SHA512:2.16.840.1.101.3.4.2.3"

#define ALGC(NAMES, FUNC, CHECK) { { NAMES, PROV_DEFAULT_PROPERTIES, FUNC }, CHECK }
#define ALG(NAMES, FUNC)         ALGC(NAMES, FUNC, NULL)

static const char PROV_DEFAULT_PROPERTIES[] = "provider=imb-provider";

typedef struct bio_method_st {
        int type;
        char *name;
        int (*bwrite)(BIO *, const char *, size_t, size_t *);
        int (*bwrite_old)(BIO *, const char *, int);
        int (*bread)(BIO *, char *, size_t, size_t *);
        int (*bread_old)(BIO *, char *, int);
        int (*bputs)(BIO *, const char *);
        int (*bgets)(BIO *, char *, int);
        long (*ctrl)(BIO *, int, long, void *);
        int (*create)(BIO *);
        int (*destroy)(BIO *);
        long (*callback_ctrl)(BIO *, int, BIO_info_cb *);
} PROV_BIO_METHOD;

typedef struct prov_provider_ctx_st {
        const OSSL_CORE_HANDLE *handle;
        OSSL_LIB_CTX *libctx;
        PROV_BIO_METHOD *corebiometh;
} PROV_CTX;

typedef struct prov_provider_params_st {
        char *enable_inline_polling;
        char *prov_poll_interval;
        char *prov_epoll_timeout;
        char *enable_event_driven_polling;
        char *enable_instance_for_thread;
        char *prov_max_retry_count;
} PROV_PARAMS;

typedef struct prov_ag_capable_st {
        OSSL_ALGORITHM alg;
        int (*capable)(void);
} OSSL_ALGORITHM_CAPABLE;
void
prov_cache_exported_algorithms(const OSSL_ALGORITHM_CAPABLE *in, OSSL_ALGORITHM *out);
int
prov_is_running(void);
OSSL_LIB_CTX *
prov_libctx_of(PROV_CTX *ctx);

int
prov_securitycheck_enabled(OSSL_LIB_CTX *libctx);

#endif /* PROV_PROVIDER_H */
