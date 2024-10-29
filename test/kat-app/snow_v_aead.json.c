/*****************************************************************************
 Copyright (c) 2023-2024, Intel Corporation

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
*****************************************************************************/

/* SNOW-V-AEAD,  */
#include "aead_test.h"

/**
 * Test vectors for SNOW-V-GCM from 'A new SNOW stream cipher called SNOW-V',
 * Patrik Ekdahl1, Thomas Johansson2, Alexander Maximov1 and Jing Yang2
 */

const struct aead_test snow_v_aead_json[] = {
        { 128, 256, 128, 1,
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "", "", "",
          "\x02\x9a\x62\x4c\xda\xa4\xd4\x6c\xb9\xa0\xef\x40\x46\x95\x6c\x9f", 1, 0, 0 },
        { 128, 256, 128, 2,
          "\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5a\x5b\x5c\x5d\x5e\x5f\x0a\x1a\x2a\x3a\x4a\x5a"
          "\x6a\x7a\x8a\x9a\xaa\xba\xca\xda\xea\xfa",
          "\x01\x23\x45\x67\x89\xab\xcd\xef\xfe\xdc\xba\x98\x76\x54\x32\x10", "", "", "",
          "\xfc\x7c\xac\x57\x4c\x49\xfe\xae\x61\x50\x31\x5b\x96\x85\x42\x4c", 1, 0, 0 },
        { 128, 256, 128, 3,
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x61\x62\x63\x64\x65\x66", "", "",
          "\x5a\x5a\xa5\xfb\xd6\x35\xef\x1a\xe1\x29\x61\x42\x03\xe1\x03\x84", 1, 128, 0 },
        { 128, 256, 128, 4,
          "\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5a\x5b\x5c\x5d\x5e\x5f\x0a\x1a\x2a\x3a\x4a\x5a"
          "\x6a\x7a\x8a\x9a\xaa\xba\xca\xda\xea\xfa",
          "\x01\x23\x45\x67\x89\xab\xcd\xef\xfe\xdc\xba\x98\x76\x54\x32\x10",
          "\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x61\x62\x63\x64\x65\x66", "", "",
          "\x25\x0e\xc8\xd7\x7a\x02\x2c\x08\x7a\xdf\x08\xb6\x5a\xdc\xbb\x1a", 1, 128, 0 },
        { 128, 256, 128, 5,
          "\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5a\x5b\x5c\x5d\x5e\x5f\x0a\x1a\x2a\x3a\x4a\x5a"
          "\x6a\x7a\x8a\x9a\xaa\xba\xca\xda\xea\xfa",
          "\x01\x23\x45\x67\x89\xab\xcd\xef\xfe\xdc\xba\x98\x76\x54\x32\x10", "",
          "\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39", "\xdd\x7e\x01\xb2\xb4\x24\xa2\xef\x82\x50",
          "\xdd\xfe\x4e\x31\xe7\xbf\xe6\x90\x23\x31\xec\x5c\xe3\x19\xd9\x0d", 1, 0, 80 },
        { 128, 256, 128, 6,
          "\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5a\x5b\x5c\x5d\x5e\x5f\x0a\x1a\x2a\x3a\x4a\x5a"
          "\x6a\x7a\x8a\x9a\xaa\xba\xca\xda\xea\xfa",
          "\x01\x23\x45\x67\x89\xab\xcd\xef\xfe\xdc\xba\x98\x76\x54\x32\x10",
          "\x41\x41\x44\x20\x74\x65\x73\x74\x20\x76\x61\x6c\x75\x65\x21",
          "\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x61\x62\x63\x64\x65\x66\x20\x53\x6e\x6f\x77\x56"
          "\x2d\x41\x45\x41\x44\x20\x6d\x6f\x64\x65\x21",
          "\xdd\x7e\x01\xb2\xb4\x24\xa2\xef\x82\x50\x27\x07\xe8\x7a\x32\xc1\x52\xb0\xd0\x18\x18\xfd"
          "\x7f\x12\x24\x3e\xb5\xa1\x56\x59\xe9\x1b\x4c",
          "\x90\x7e\xa6\xa5\xb7\x3a\x51\xde\x74\x7c\x3e\x9a\xd9\xee\x02\x9b", 1, 120, 264 },
        { 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0 }
};
