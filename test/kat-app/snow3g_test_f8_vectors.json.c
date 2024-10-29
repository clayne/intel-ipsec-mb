/*****************************************************************************
 Copyright (c) 2023-2024, Intel Corporation
 Copyright (c) 2022, Nokia

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

/* SNOW3G_f8 */
#include "cipher_test.h"
const struct cipher_test snow3g_cipher_bit_test_vectors_json[] = {
        { 128, 128, 1, "\xd3\xc5\xd5\x92\x32\x7f\xb1\x1c\x40\x35\xc6\x68\x0a\xf8\xc6\xd1",
          "\x39\x8a\x59\xb4\xac\x00\x00\x00\x39\x8a\x59\xb4\xac\x00\x00\x00",
          "\x98\x1b\xa6\x82\x4c\x1b\xfb\x1a\xb4\x85\x47\x20\x29\xb7\x1d\x80\x8c\xe3"
          "\x3e\x2c\xc3\xc0\xb5\xfc\x1f\x3d\xe8\xa6\xdc\x66\xb1\xf0",
          "\x5d\x5b\xfe\x75\xeb\x04\xf6\x8c\xe0\xa1\x23\x77\xea\x00\xb3\x7d\x47\xc6"
          "\xa0\xba\x06\x30\x91\x55\x08\x6a\x85\x9c\x43\x41\xb3\x7c",
          1, 256 },
        { 128, 128, 2, "\x2b\xd6\x45\x9f\x82\xc5\xb3\x00\x95\x2c\x49\x10\x48\x81\xff\x48",
          "\x72\xa4\xf2\x0f\x64\x00\x00\x00\x72\xa4\xf2\x0f\x64\x00\x00\x00",
          "\x7e\xc6\x12\x72\x74\x3b\xf1\x61\x47\x26\x44\x6a\x6c\x38\xce\xd1\x66\xf6"
          "\xca\x76\xeb\x54\x30\x04\x42\x86\x34\x6c\xef\x13\x0f\x92\x92\x2b\x03\x45"
          "\x0d\x3a\x99\x75\xe5\xbd\x2e\xa0\xeb\x55\xad\x8e\x1b\x19\x9e\x3e\xc4\x31"
          "\x60\x20\xe9\xa1\xb2\x85\xe7\x62\x79\x53\x59\xb7\xbd\xfd\x39\xbe\xf4\xb2"
          "\x48\x45\x83\xd5\xaf\xe0\x82\xae\xe6\x38\xbf\x5f\xd5\xa6\x06\x19\x39\x01"
          "\xa0\x8f\x4a\xb4\x1a\xab\x9b\x13\x48\x80",
          "\x8c\xeb\xa6\x29\x43\xdc\xed\x3a\x09\x90\xb0\x6e\xa1\xb0\xa2\xc4\xfb\x3c"
          "\xed\xc7\x1b\x36\x9f\x42\xba\x64\xc1\xeb\x66\x65\xe7\x2a\xa1\xc9\xbb\x0d"
          "\xea\xa2\x0f\xe8\x60\x58\xb8\xba\xee\x2c\x2e\x7f\x0b\xec\xce\x48\xb5\x29"
          "\x32\xa5\x3c\x9d\x5f\x93\x1a\x3a\x7c\x53\x22\x59\xaf\x43\x25\xe2\xa6\x5e"
          "\x30\x84\xad\x5f\x6a\x51\x3b\x7b\xdd\xc1\xb6\x5f\x0a\xa0\xd9\x7a\x05\x3d"
          "\xb5\x5a\x88\xc4\xc4\xf9\x60\x5e\x41\x40",
          1, 798 },
        { 128, 128, 3, "\x5a\xcb\x1d\x64\x4c\x0d\x51\x20\x4e\xa5\xf1\x45\x10\x10\xd8\x52",
          "\xfa\x55\x6b\x26\x1c\x00\x00\x00\xfa\x55\x6b\x26\x1c\x00\x00\x00",
          "\xad\x9c\x44\x1f\x89\x0b\x38\xc4\x57\xa4\x9d\x42\x14\x07\xe8",
          "\xba\x0f\x31\x30\x03\x34\xc5\x6b\x52\xa7\x49\x7c\xba\xc0\x46", 1, 120 },
        { 128, 128, 4, "\xef\xa8\xb2\x22\x9e\x72\x0c\x2a\x7c\x36\xea\x55\xe9\x60\x56\x95",
          "\xe2\x8b\xcf\x7b\xc0\x00\x00\x00\xe2\x8b\xcf\x7b\xc0\x00\x00\x00",
          "\x10\x11\x12\x31\xe0\x60\x25\x3a\x43\xfd\x3f\x57\xe3\x76\x07\xab\x28\x27"
          "\xb5\x99\xb6\xb1\xbb\xda\x37\xa8\xab\xcc\x5a\x8c\x55\x0d\x1b\xfb\x2f\x49"
          "\x46\x24\xfb\x50\x36\x7f\xa3\x6c\xe3\xbc\x68\xf1\x1c\xf9\x3b\x15\x10\x37"
          "\x6b\x02\x13\x0f\x81\x2a\x9f\xa1\x69\xd8",
          "\xe0\xda\x15\xca\x8e\x25\x54\xf5\xe5\x6c\x94\x68\xdc\x6c\x7c\x12\x9c\x56"
          "\x8a\xa5\x03\x23\x17\xe0\x4e\x07\x29\x64\x6c\xab\xef\xa6\x89\x86\x4c\x41"
          "\x0f\x24\xf9\x19\xe6\x1e\x3d\xfd\xfa\xd7\x7e\x56\x0d\xb0\xa9\xcd\x36\xc3"
          "\x4a\xe4\x18\x14\x90\xb2\x9f\x5f\xa2\xfc",
          1, 510 },
        { 128, 128, 5, "\xd3\xc5\xd5\x92\x32\x7f\xb1\x1c\x40\x35\xc6\x68\x0a\xf8\xc6\xd1",
          "\x39\x8a\x59\xb4\x2c\x00\x00\x00\x39\x8a\x59\xb4\x2c\x00\x00\x00",
          "\x98\x1b\xa6\x82\x4c\x1b\xfb\x1a\xb4\x85\x47\x20\x29\xb7\x1d\x80\x8c\xe3"
          "\x3e\x2c\xc3\xc0\xb5\xfc\x1f\x3d\xe8\xa6\xdc\x66\xb1\xf0",
          "\x98\x9b\x71\x9c\xdc\x33\xce\xb7\xcf\x27\x6a\x52\x82\x7c\xef\x94\xa5\x6c"
          "\x40\xc0\xab\x9d\x81\xf7\xa2\xa9\xba\xc6\x0e\x11\xc4\xb0",
          1, 253 },
        { 128, 128, 6, "\x60\x90\xea\xe0\x4c\x83\x70\x6e\xec\xbf\x65\x2b\xe8\xe3\x65\x66",
          "\x72\xa4\xf2\x0f\x48\x00\x00\x00\x72\xa4\xf2\x0f\x48\x00\x00\x00",
          "\x40\x98\x1b\xa6\x82\x4c\x1b\xfb\x42\x86\xb2\x99\x78\x3d\xaf\x44\x2c\x09"
          "\x9f\x7a\xb0\xf5\x8d\x5c\x8e\x46\xb1\x04\xf0\x8f\x01\xb4\x1a\xb4\x85\x47"
          "\x20\x29\xb7\x1d\x36\xbd\x1a\x3d\x90\xdc\x3a\x41\xb4\x6d\x51\x67\x2a\xc4"
          "\xc9\x66\x3a\x2b\xe0\x63\xda\x4b\xc8\xd2\x80\x8c\xe3\x3e\x2c\xcc\xbf\xc6"
          "\x34\xe1\xb2\x59\x06\x08\x76\xa0\xfb\xb5\xa4\x37\xeb\xcc\x8d\x31\xc1\x9e"
          "\x44\x54\x31\x87\x45\xe3\x98\x76\x45\x98\x7a\x98\x6f\x2c\xb0",
          "\x58\x92\xbb\xa8\x8b\xbb\xca\xae\xae\x76\x9a\xa0\x6b\x68\x3d\x3a\x17\xcc"
          "\x04\xa3\x69\x88\x16\x97\x43\x5e\x44\xfe\xd5\xff\x9a\xf5\x7b\x9e\x89\x0d"
          "\x4d\x5c\x64\x70\x98\x85\xd4\x8a\xe4\x06\x90\xec\x04\x3b\xaa\xe9\x70\x57"
          "\x96\xe4\xa9\xff\x5a\x4b\x8d\x8b\x36\xd7\xf3\xfe\x57\xcc\x6c\xfd\x6c\xd0"
          "\x05\xcd\x38\x52\xa8\x5e\x94\xce\x6b\xcd\x90\xd0\xd0\x78\x39\xce\x09\x73"
          "\x35\x44\xca\x8e\x35\x08\x43\x24\x85\x50\x92\x2a\xc1\x28\x18",
          1, 837 },
        { 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0 }
};

const struct cipher_test snow3g_cipher_linear_test_vectors_json[] = {
        { 128, 128, 1, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x00\x1c\x00\x00\x00\x00\x00\x00\x00\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xea\xe9\x11\x49\x21\x58\x44\x59\xc6\xec\x77\x82\x71\x6f\x91\xd4\xe1\xf6"
          "\xbf\xfa\x45\xfc\x80\x94\xc2\x3d\x5c\x5f\x17\x72\x44\x92",
          1, 256 },
        { 128, 128, 2, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x01\x1c\x00\x00\x00\x00\x00\x00\x01\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xe3\x96\x7f\x63\x88\x74\x2d\x7c\x3b\x3d\x5a\x08\xc0\x8d\x1a\xc2\xa1\xf2"
          "\x38\x96\xc7\x41\x1b\xc1\xde\xac\x24\x57\x9c\x45\x0d\xb0",
          1, 256 },
        { 128, 128, 3, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x02\x1c\x00\x00\x00\x00\x00\x00\x02\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x4d\x50\xd2\xe3\xa6\xe7\x97\xee\xf3\xe6\x2a\x32\xf3\x66\xea\x99\xbc\x54"
          "\x24\xa6\x3f\xc3\xbb\x27\xc7\xba\x42\xd8\x2f\x86\xfc\xdf",
          1, 256 },
        { 128, 128, 4, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x03\x1c\x00\x00\x00\x00\x00\x00\x03\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x4a\x98\xa3\x04\xad\xcf\xb9\xfa\xdb\x3b\xe7\x7c\xd1\x69\x59\x6c\x7e\x44"
          "\x73\x8d\x96\xd0\x51\x1f\x55\x32\x55\x59\xc2\xe9\x0a\x21",
          1, 256 },
        { 128, 128, 5, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x04\x1c\x00\x00\x00\x00\x00\x00\x04\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xe4\xf5\x71\x42\xaf\x93\x5e\x6d\x7d\xb8\x44\xf7\xcb\x0d\x08\xd3\x3a\xe6"
          "\x20\xcd\xc5\x33\xa3\x5a\x5e\x5a\x41\x92\x96\x44\x28\xc1",
          1, 256 },
        { 128, 128, 6, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x05\x1c\x00\x00\x00\x00\x00\x00\x05\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x1b\x6e\x3a\x76\x18\x77\x0b\x77\xf2\xda\xca\x1d\xd2\x9c\xa9\xc2\x10\x6b"
          "\xe7\x4b\xdb\x30\x79\xc5\x56\xf4\xcb\xb7\x19\xdf\xe5\xcb",
          1, 256 },
        { 128, 128, 7, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x06\x1c\x00\x00\x00\x00\x00\x00\x06\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x10\x4e\x19\x91\x09\x91\xd0\x9d\x41\x99\x33\x1b\xfd\xa0\xe0\xf7\x80\x6c"
          "\x1f\x7b\x12\x78\x3d\x46\x65\x86\x7e\xdf\x9f\xac\x31\x42",
          1, 256 },
        { 128, 128, 8, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x07\x1c\x00\x00\x00\x00\x00\x00\x07\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x59\x02\x9f\xe6\x98\x24\xe3\xc5\x1b\x19\x61\x08\x37\x79\xd0\xfe\xe4\xa1"
          "\xd8\xd4\x04\xf2\x43\x60\xa4\x68\x08\x9b\x06\x9c\xb3\x51",
          1, 256 },
        { 128, 128, 9, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x08\x1c\x00\x00\x00\x00\x00\x00\x08\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x60\x59\x72\x8f\xd0\x0b\x69\x67\xdf\x89\xb0\xd1\xc3\x02\x3e\xe4\x5b\xde"
          "\xe2\x0a\xea\x67\xc6\x05\x40\x4f\xe9\x38\xd4\x10\x1d\x5a",
          1, 256 },
        { 128, 128, 10, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x09\x1c\x00\x00\x00\x00\x00\x00\x09\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x46\x63\x8d\x94\x5a\xcc\x87\x2d\x57\x4f\xcb\x55\x71\xaa\x6c\x17\xcb\x7c"
          "\x7a\x6d\x19\xbf\xba\xcd\xe1\x3c\x77\xed\x0f\x10\x4f\x38",
          1, 256 },
        { 128, 128, 11, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0a\x1c\x00\x00\x00\x00\x00\x00\x0a\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xe5\xdd\xa1\x58\xbe\x47\x6e\xa6\x3b\xea\x90\x02\xf6\x87\xbd\x69\x1b\x15"
          "\xb7\x3c\x6f\xa1\x28\xde\x0f\xf3\x80\xfb\xef\x89\xa5\xd5",
          1, 256 },
        { 128, 128, 12, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0b\x1c\x00\x00\x00\x00\x00\x00\x0b\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xae\x68\x9e\x4e\x8d\x49\x2a\x59\x5c\x02\x53\x73\x91\xb2\x92\x94\xc3\x7e"
          "\x09\xae\xe3\x6d\x3c\xea\xac\x57\x34\x19\x82\x56\x10\x2e",
          1, 256 },
        { 128, 128, 13, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0c\x1c\x00\x00\x00\x00\x00\x00\x0c\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xd4\x35\x4b\x73\x1b\x6e\xa3\x4c\xd5\x9b\x10\xd0\x93\x64\xc9\xdf\xe0\xe5"
          "\x2e\xa0\x8c\x2d\x85\x38\x53\xaa\x79\x92\xad\xae\x36\xb3",
          1, 256 },
        { 128, 128, 14, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0d\x1c\x00\x00\x00\x00\x00\x00\x0d\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xdb\x9b\x66\x28\xf7\x9d\x37\x32\xbe\x36\x78\x8d\xa3\xd0\xc2\x73\x68\x0d"
          "\x47\xf7\x13\x8f\x3d\x83\x2a\xcf\x5e\xe1\xb8\x6d\x86\xb8",
          1, 256 },
        { 128, 128, 15, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0e\x1c\x00\x00\x00\x00\x00\x00\x0e\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xd5\xbf\x80\x07\x53\x33\xad\x71\x9a\x05\x70\xd9\xe7\xdd\x45\xf0\xd0\x2d"
          "\xaf\xdc\xf1\x12\x67\x8f\x46\x20\xac\xb4\xd7\xf8\x98\x41",
          1, 256 },
        { 128, 128, 16, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0e\x1c\x00\x00\x00\x00\x00\x00\x0e\x1c\x00\x00\x00", "",
          "\xd5\xbf\x80\x07\x53\x33\xad\x71\x9a\x05\x70\xd9\xe7\xdd\x45\xf0\xd0\x2d"
          "\xaf\xdc\xf1\x12\x67\x8f\x46\x20\xac\xb4\xd7\xf8\x98\x41",
          1, 0 },
        { 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0 }
};

const struct cipher_test snow3g_cipher_test_vectors_json[] = {
        { 128, 128, 1, "\xd3\xc5\xd5\x92\x32\x7f\xb1\x1c\x40\x35\xc6\x68\x0a\xf8\xc6\xd1",
          "\x39\x8a\x59\xb4\xac\x00\x00\x00\x39\x8a\x59\xb4\xac\x00\x00\x00",
          "\x98\x1b\xa6\x82\x4c\x1b\xfb\x1a\xb4\x85\x47\x20\x29\xb7\x1d\x80\x8c\xe3"
          "\x3e\x2c\xc3\xc0\xb5\xfc\x1f\x3d\xe8\xa6\xdc\x66\xb1\xf0",
          "\x5d\x5b\xfe\x75\xeb\x04\xf6\x8c\xe0\xa1\x23\x77\xea\x00\xb3\x7d\x47\xc6"
          "\xa0\xba\x06\x30\x91\x55\x08\x6a\x85\x9c\x43\x41\xb3\x7c",
          1, 256 },
        { 128, 128, 2, "\x2b\xd6\x45\x9f\x82\xc5\xb3\x00\x95\x2c\x49\x10\x48\x81\xff\x48",
          "\x72\xa4\xf2\x0f\x64\x00\x00\x00\x72\xa4\xf2\x0f\x64\x00\x00\x00",
          "\x7e\xc6\x12\x72\x74\x3b\xf1\x61\x47\x26\x44\x6a\x6c\x38\xce\xd1\x66\xf6"
          "\xca\x76\xeb\x54\x30\x04\x42\x86\x34\x6c\xef\x13\x0f\x92\x92\x2b\x03\x45"
          "\x0d\x3a\x99\x75\xe5\xbd\x2e\xa0\xeb\x55\xad\x8e\x1b\x19\x9e\x3e\xc4\x31"
          "\x60\x20\xe9\xa1\xb2\x85\xe7\x62\x79\x53\x59\xb7\xbd\xfd\x39\xbe\xf4\xb2"
          "\x48\x45\x83\xd5\xaf\xe0\x82\xae\xe6\x38\xbf\x5f\xd5\xa6\x06\x19\x39\x01"
          "\xa0\x8f\x4a\xb4\x1a\xab\x9b\x13\x48",
          "\x8c\xeb\xa6\x29\x43\xdc\xed\x3a\x09\x90\xb0\x6e\xa1\xb0\xa2\xc4\xfb\x3c"
          "\xed\xc7\x1b\x36\x9f\x42\xba\x64\xc1\xeb\x66\x65\xe7\x2a\xa1\xc9\xbb\x0d"
          "\xea\xa2\x0f\xe8\x60\x58\xb8\xba\xee\x2c\x2e\x7f\x0b\xec\xce\x48\xb5\x29"
          "\x32\xa5\x3c\x9d\x5f\x93\x1a\x3a\x7c\x53\x22\x59\xaf\x43\x25\xe2\xa6\x5e"
          "\x30\x84\xad\x5f\x6a\x51\x3b\x7b\xdd\xc1\xb6\x5f\x0a\xa0\xd9\x7a\x05\x3d"
          "\xb5\x5a\x88\xc4\xc4\xf9\x60\x5e\x41",
          1, 792 },
        { 128, 128, 3, "\x5a\xcb\x1d\x64\x4c\x0d\x51\x20\x4e\xa5\xf1\x45\x10\x10\xd8\x52",
          "\xfa\x55\x6b\x26\x1c\x00\x00\x00\xfa\x55\x6b\x26\x1c\x00\x00\x00",
          "\xad\x9c\x44\x1f\x89\x0b\x38\xc4\x57\xa4\x9d\x42\x14\x07\xe8",
          "\xba\x0f\x31\x30\x03\x34\xc5\x6b\x52\xa7\x49\x7c\xba\xc0\x46", 1, 120 },
        { 128, 128, 4, "\xef\xa8\xb2\x22\x9e\x72\x0c\x2a\x7c\x36\xea\x55\xe9\x60\x56\x95",
          "\xe2\x8b\xcf\x7b\xc0\x00\x00\x00\xe2\x8b\xcf\x7b\xc0\x00\x00\x00",
          "\x10\x11\x12\x31\xe0\x60\x25\x3a\x43\xfd\x3f\x57\xe3\x76\x07\xab\x28\x27"
          "\xb5\x99\xb6\xb1\xbb\xda\x37\xa8\xab\xcc\x5a\x8c\x55\x0d\x1b\xfb\x2f\x49"
          "\x46\x24\xfb\x50\x36\x7f\xa3\x6c\xe3\xbc\x68\xf1\x1c\xf9\x3b\x15\x10\x37"
          "\x6b\x02\x13\x0f\x81\x2a\x9f\xa1\x69",
          "\xe0\xda\x15\xca\x8e\x25\x54\xf5\xe5\x6c\x94\x68\xdc\x6c\x7c\x12\x9c\x56"
          "\x8a\xa5\x03\x23\x17\xe0\x4e\x07\x29\x64\x6c\xab\xef\xa6\x89\x86\x4c\x41"
          "\x0f\x24\xf9\x19\xe6\x1e\x3d\xfd\xfa\xd7\x7e\x56\x0d\xb0\xa9\xcd\x36\xc3"
          "\x4a\xe4\x18\x14\x90\xb2\x9f\x5f\xa2",
          1, 504 },
        { 128, 128, 5, "\xd3\xc5\xd5\x92\x32\x7f\xb1\x1c\x40\x35\xc6\x68\x0a\xf8\xc6\xd1",
          "\x39\x8a\x59\xb4\x2c\x00\x00\x00\x39\x8a\x59\xb4\x2c\x00\x00\x00",
          "\x98\x1b\xa6\x82\x4c\x1b\xfb\x1a\xb4\x85\x47\x20\x29\xb7\x1d\x80\x8c\xe3"
          "\x3e\x2c\xc3\xc0\xb5\xfc\x1f\x3d\xe8\xa6\xdc\x66\xb1",
          "\x98\x9b\x71\x9c\xdc\x33\xce\xb7\xcf\x27\x6a\x52\x82\x7c\xef\x94\xa5\x6c"
          "\x40\xc0\xab\x9d\x81\xf7\xa2\xa9\xba\xc6\x0e\x11\xc4\xb6",
          1, 248 },
        { 128, 128, 6, "\x60\x90\xea\xe0\x4c\x83\x70\x6e\xec\xbf\x65\x2b\xe8\xe3\x65\x66",
          "\x72\xa4\xf2\x0f\x48\x00\x00\x00\x72\xa4\xf2\x0f\x48\x00\x00\x00",
          "\x40\x98\x1b\xa6\x82\x4c\x1b\xfb\x42\x86\xb2\x99\x78\x3d\xaf\x44\x2c\x09"
          "\x9f\x7a\xb0\xf5\x8d\x5c\x8e\x46\xb1\x04\xf0\x8f\x01\xb4\x1a\xb4\x85\x47"
          "\x20\x29\xb7\x1d\x36\xbd\x1a\x3d\x90\xdc\x3a\x41\xb4\x6d\x51\x67\x2a\xc4"
          "\xc9\x66\x3a\x2b\xe0\x63\xda\x4b\xc8\xd2\x80\x8c\xe3\x3e\x2c\xcc\xbf\xc6"
          "\x34\xe1\xb2\x59\x06\x08\x76\xa0\xfb\xb5\xa4\x37\xeb\xcc\x8d\x31\xc1\x9e"
          "\x44\x54\x31\x87\x45\xe3\x98\x76\x45\x98\x7a\x98\x6f\x2c",
          "\x58\x92\xbb\xa8\x8b\xbb\xca\xae\xae\x76\x9a\xa0\x6b\x68\x3d\x3a\x17\xcc"
          "\x04\xa3\x69\x88\x16\x97\x43\x5e\x44\xfe\xd5\xff\x9a\xf5\x7b\x9e\x89\x0d"
          "\x4d\x5c\x64\x70\x98\x85\xd4\x8a\xe4\x06\x90\xec\x04\x3b\xaa\xe9\x70\x57"
          "\x96\xe4\xa9\xff\x5a\x4b\x8d\x8b\x36\xd7\xf3\xfe\x57\xcc\x6c\xfd\x6c\xd0"
          "\x05\xcd\x38\x52\xa8\x5e\x94\xce\x6b\xcd\x90\xd0\xd0\x78\x39\xce\x09\x73"
          "\x35\x44\xca\x8e\x35\x08\x43\x24\x85\x50\x92\x2a\xc1\x28",
          1, 832 },
        { 128, 128, 7, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x00\x1c\x00\x00\x00\x00\x00\x00\x00\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xea\xe9\x11\x49\x21\x58\x44\x59\xc6\xec\x77\x82\x71\x6f\x91\xd4\xe1\xf6"
          "\xbf\xfa\x45\xfc\x80\x94\xc2\x3d\x5c\x5f\x17\x72\x44\x92",
          1, 256 },
        { 128, 128, 8, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x01\x1c\x00\x00\x00\x00\x00\x00\x01\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xe3\x96\x7f\x63\x88\x74\x2d\x7c\x3b\x3d\x5a\x08\xc0\x8d\x1a\xc2\xa1\xf2"
          "\x38\x96\xc7\x41\x1b\xc1\xde\xac\x24\x57\x9c\x45\x0d\xb0",
          1, 256 },
        { 128, 128, 9, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x02\x1c\x00\x00\x00\x00\x00\x00\x02\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x4d\x50\xd2\xe3\xa6\xe7\x97\xee\xf3\xe6\x2a\x32\xf3\x66\xea\x99\xbc\x54"
          "\x24\xa6\x3f\xc3\xbb\x27\xc7\xba\x42\xd8\x2f\x86\xfc\xdf",
          1, 256 },
        { 128, 128, 10, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x03\x1c\x00\x00\x00\x00\x00\x00\x03\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x4a\x98\xa3\x04\xad\xcf\xb9\xfa\xdb\x3b\xe7\x7c\xd1\x69\x59\x6c\x7e\x44"
          "\x73\x8d\x96\xd0\x51\x1f\x55\x32\x55\x59\xc2\xe9\x0a\x21",
          1, 256 },
        { 128, 128, 11, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x04\x1c\x00\x00\x00\x00\x00\x00\x04\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xe4\xf5\x71\x42\xaf\x93\x5e\x6d\x7d\xb8\x44\xf7\xcb\x0d\x08\xd3\x3a\xe6"
          "\x20\xcd\xc5\x33\xa3\x5a\x5e\x5a\x41\x92\x96\x44\x28\xc1",
          1, 256 },
        { 128, 128, 12, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x05\x1c\x00\x00\x00\x00\x00\x00\x05\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x1b\x6e\x3a\x76\x18\x77\x0b\x77\xf2\xda\xca\x1d\xd2\x9c\xa9\xc2\x10\x6b"
          "\xe7\x4b\xdb\x30\x79\xc5\x56\xf4\xcb\xb7\x19\xdf\xe5\xcb",
          1, 256 },
        { 128, 128, 13, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x06\x1c\x00\x00\x00\x00\x00\x00\x06\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x10\x4e\x19\x91\x09\x91\xd0\x9d\x41\x99\x33\x1b\xfd\xa0\xe0\xf7\x80\x6c"
          "\x1f\x7b\x12\x78\x3d\x46\x65\x86\x7e\xdf\x9f\xac\x31\x42",
          1, 256 },
        { 128, 128, 14, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x07\x1c\x00\x00\x00\x00\x00\x00\x07\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x59\x02\x9f\xe6\x98\x24\xe3\xc5\x1b\x19\x61\x08\x37\x79\xd0\xfe\xe4\xa1"
          "\xd8\xd4\x04\xf2\x43\x60\xa4\x68\x08\x9b\x06\x9c\xb3\x51",
          1, 256 },
        { 128, 128, 15, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x08\x1c\x00\x00\x00\x00\x00\x00\x08\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x60\x59\x72\x8f\xd0\x0b\x69\x67\xdf\x89\xb0\xd1\xc3\x02\x3e\xe4\x5b\xde"
          "\xe2\x0a\xea\x67\xc6\x05\x40\x4f\xe9\x38\xd4\x10\x1d\x5a",
          1, 256 },
        { 128, 128, 16, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x09\x1c\x00\x00\x00\x00\x00\x00\x09\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x46\x63\x8d\x94\x5a\xcc\x87\x2d\x57\x4f\xcb\x55\x71\xaa\x6c\x17\xcb\x7c"
          "\x7a\x6d\x19\xbf\xba\xcd\xe1\x3c\x77\xed\x0f\x10\x4f\x38",
          1, 256 },
        { 128, 128, 17, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0a\x1c\x00\x00\x00\x00\x00\x00\x0a\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xe5\xdd\xa1\x58\xbe\x47\x6e\xa6\x3b\xea\x90\x02\xf6\x87\xbd\x69\x1b\x15"
          "\xb7\x3c\x6f\xa1\x28\xde\x0f\xf3\x80\xfb\xef\x89\xa5\xd5",
          1, 256 },
        { 128, 128, 18, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0b\x1c\x00\x00\x00\x00\x00\x00\x0b\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xae\x68\x9e\x4e\x8d\x49\x2a\x59\x5c\x02\x53\x73\x91\xb2\x92\x94\xc3\x7e"
          "\x09\xae\xe3\x6d\x3c\xea\xac\x57\x34\x19\x82\x56\x10\x2e",
          1, 256 },
        { 128, 128, 19, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0c\x1c\x00\x00\x00\x00\x00\x00\x0c\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xd4\x35\x4b\x73\x1b\x6e\xa3\x4c\xd5\x9b\x10\xd0\x93\x64\xc9\xdf\xe0\xe5"
          "\x2e\xa0\x8c\x2d\x85\x38\x53\xaa\x79\x92\xad\xae\x36\xb3",
          1, 256 },
        { 128, 128, 20, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0d\x1c\x00\x00\x00\x00\x00\x00\x0d\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xdb\x9b\x66\x28\xf7\x9d\x37\x32\xbe\x36\x78\x8d\xa3\xd0\xc2\x73\x68\x0d"
          "\x47\xf7\x13\x8f\x3d\x83\x2a\xcf\x5e\xe1\xb8\x6d\x86\xb8",
          1, 256 },
        { 128, 128, 21, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0e\x1c\x00\x00\x00\x00\x00\x00\x0e\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\xd5\xbf\x80\x07\x53\x33\xad\x71\x9a\x05\x70\xd9\xe7\xdd\x45\xf0\xd0\x2d"
          "\xaf\xdc\xf1\x12\x67\x8f\x46\x20\xac\xb4\xd7\xf8\x98\x41",
          1, 256 },
        { 128, 128, 22, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x00\x00\x00\x0f\x1c\x00\x00\x00\x00\x00\x00\x0f\x1c\x00\x00\x00",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
          "\x62\x45\xff\xfa\x89\x47\x18\x63\x28\x4e\xd5\xf2\x94\xb0\x54\x43\xd5\xae"
          "\xb5\x68\x2f\xf6\x7c\x81\xe3\xc5\x81\x32\x0e\x59\xc5\x60",
          1, 256 },
        { 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0 }
};
