/*
 * FIPS 180-2 SHA-224/256/384/512 implementation
 *
 * Copyright (C) 2005-2023 Olivier Gay <olivier.gay@a3.epfl.ch>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef SHA2_H
#define SHA2_H

#define SHA224_DIGEST_SIZE (224 / 8)
#define SHA256_DIGEST_SIZE (256 / 8)
#define SHA384_DIGEST_SIZE (384 / 8)
#define SHA512_DIGEST_SIZE (512 / 8)

#define SHA256_BLOCK_SIZE (512 / 8)
#define SHA512_BLOCK_SIZE (1024 / 8)
#define SHA384_BLOCK_SIZE SHA512_BLOCK_SIZE
#define SHA224_BLOCK_SIZE SHA256_BLOCK_SIZE

#ifndef SHA2_TYPES
#define SHA2_TYPES
typedef unsigned char      uint8;
typedef unsigned int       uint32;
typedef unsigned long long uint64;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        uint64 tot_len;
        uint64 len;
        uint8  block[2 * SHA256_BLOCK_SIZE];
        uint32 h[8];
    } sha256_ctx;

    typedef struct
    {
        uint64 tot_len;
        uint64 len;
        uint8  block[2 * SHA512_BLOCK_SIZE];
        uint64 h[8];
    } sha512_ctx;

    typedef sha512_ctx sha384_ctx;
    typedef sha256_ctx sha224_ctx;

    void sha224Init(sha224_ctx *ctx);
    void sha224Update(sha224_ctx *ctx, const uint8 *message, uint64 len);
    void sha224Final(sha224_ctx *ctx, uint8 *digest);
    void sha224(const uint8 *message, uint64 len, uint8 *digest);

    void sha256Init(sha256_ctx *ctx);
    void sha256Update(sha256_ctx *ctx, const uint8 *message, uint64 len);
    void sha256Final(sha256_ctx *ctx, uint8 *digest);
    void sha256(const uint8 *message, uint64 len, uint8 *digest);

    void sha384Init(sha384_ctx *ctx);
    void sha384Update(sha384_ctx *ctx, const uint8 *message, uint64 len);
    void sha384Final(sha384_ctx *ctx, uint8 *digest);
    void sha384(const uint8 *message, uint64 len, uint8 *digest);

    void sha512Init(sha512_ctx *ctx);
    void sha512Update(sha512_ctx *ctx, const uint8 *message, uint64 len);
    void sha512Final(sha512_ctx *ctx, uint8 *digest);
    void sha512(const uint8 *message, uint64 len, uint8 *digest);

#ifdef __cplusplus
}
#endif

#endif /* !SHA2_H */
