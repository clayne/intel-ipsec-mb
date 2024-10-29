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

/* CHACHA20  */
#include "cipher_test.h"
const struct cipher_test chacha_test_json[] = {
        { 96, 256, 1,
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01",
          "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02",
          "\x41\x6e\x79\x20\x73\x75\x62\x6d\x69\x73\x73\x69\x6f\x6e\x20\x74\x6f\x20"
          "\x74\x68\x65\x20\x49\x45\x54\x46\x20\x69\x6e\x74\x65\x6e\x64\x65\x64\x20"
          "\x62\x79\x20\x74\x68\x65\x20\x43\x6f\x6e\x74\x72\x69\x62\x75\x74\x6f\x72"
          "\x20\x66\x6f\x72\x20\x70\x75\x62\x6c\x69\x63\x61\x74\x69\x6f\x6e\x20\x61"
          "\x73\x20\x61\x6c\x6c\x20\x6f\x72\x20\x70\x61\x72\x74\x20\x6f\x66\x20\x61"
          "\x6e\x20\x49\x45\x54\x46\x20\x49\x6e\x74\x65\x72\x6e\x65\x74\x2d\x44\x72"
          "\x61\x66\x74\x20\x6f\x72\x20\x52\x46\x43\x20\x61\x6e\x64\x20\x61\x6e\x79"
          "\x20\x73\x74\x61\x74\x65\x6d\x65\x6e\x74\x20\x6d\x61\x64\x65\x20\x77\x69"
          "\x74\x68\x69\x6e\x20\x74\x68\x65\x20\x63\x6f\x6e\x74\x65\x78\x74\x20\x6f"
          "\x66\x20\x61\x6e\x20\x49\x45\x54\x46\x20\x61\x63\x74\x69\x76\x69\x74\x79"
          "\x20\x69\x73\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x65\x64\x20\x61\x6e\x20"
          "\x22\x49\x45\x54\x46\x20\x43\x6f\x6e\x74\x72\x69\x62\x75\x74\x69\x6f\x6e"
          "\x22\x2e\x20\x53\x75\x63\x68\x20\x73\x74\x61\x74\x65\x6d\x65\x6e\x74\x73"
          "\x20\x69\x6e\x63\x6c\x75\x64\x65\x20\x6f\x72\x61\x6c\x20\x73\x74\x61\x74"
          "\x65\x6d\x65\x6e\x74\x73\x20\x69\x6e\x20\x49\x45\x54\x46\x20\x73\x65\x73"
          "\x73\x69\x6f\x6e\x73\x2c\x20\x61\x73\x20\x77\x65\x6c\x6c\x20\x61\x73\x20"
          "\x77\x72\x69\x74\x74\x65\x6e\x20\x61\x6e\x64\x20\x65\x6c\x65\x63\x74\x72"
          "\x6f\x6e\x69\x63\x20\x63\x6f\x6d\x6d\x75\x6e\x69\x63\x61\x74\x69\x6f\x6e"
          "\x73\x20\x6d\x61\x64\x65\x20\x61\x74\x20\x61\x6e\x79\x20\x74\x69\x6d\x65"
          "\x20\x6f\x72\x20\x70\x6c\x61\x63\x65\x2c\x20\x77\x68\x69\x63\x68\x20\x61"
          "\x72\x65\x20\x61\x64\x64\x72\x65\x73\x73\x65\x64\x20\x74\x6f",
          "\xa3\xfb\xf0\x7d\xf3\xfa\x2f\xde\x4f\x37\x6c\xa2\x3e\x82\x73\x70\x41\x60"
          "\x5d\x9f\x4f\x4f\x57\xbd\x8c\xff\x2c\x1d\x4b\x79\x55\xec\x2a\x97\x94\x8b"
          "\xd3\x72\x29\x15\xc8\xf3\xd3\x37\xf7\xd3\x70\x05\x0e\x9e\x96\xd6\x47\xb7"
          "\xc3\x9f\x56\xe0\x31\xca\x5e\xb6\x25\x0d\x40\x42\xe0\x27\x85\xec\xec\xfa"
          "\x4b\x4b\xb5\xe8\xea\xd0\x44\x0e\x20\xb6\xe8\xdb\x09\xd8\x81\xa7\xc6\x13"
          "\x2f\x42\x0e\x52\x79\x50\x42\xbd\xfa\x77\x73\xd8\xa9\x05\x14\x47\xb3\x29"
          "\x1c\xe1\x41\x1c\x68\x04\x65\x55\x2a\xa6\xc4\x05\xb7\x76\x4d\x5e\x87\xbe"
          "\xa8\x5a\xd0\x0f\x84\x49\xed\x8f\x72\xd0\xd6\x62\xab\x05\x26\x91\xca\x66"
          "\x42\x4b\xc8\x6d\x2d\xf8\x0e\xa4\x1f\x43\xab\xf9\x37\xd3\x25\x9d\xc4\xb2"
          "\xd0\xdf\xb4\x8a\x6c\x91\x39\xdd\xd7\xf7\x69\x66\xe9\x28\xe6\x35\x55\x3b"
          "\xa7\x6c\x5c\x87\x9d\x7b\x35\xd4\x9e\xb2\xe6\x2b\x08\x71\xcd\xac\x63\x89"
          "\x39\xe2\x5e\x8a\x1e\x0e\xf9\xd5\x28\x0f\xa8\xca\x32\x8b\x35\x1c\x3c\x76"
          "\x59\x89\xcb\xcf\x3d\xaa\x8b\x6c\xcc\x3a\xaf\x9f\x39\x79\xc9\x2b\x37\x20"
          "\xfc\x88\xdc\x95\xed\x84\xa1\xbe\x05\x9c\x64\x99\xb9\xfd\xa2\x36\xe7\xe8"
          "\x18\xb0\x4b\x0b\xc3\x9c\x1e\x87\x6b\x19\x3b\xfe\x55\x69\x75\x3f\x88\x12"
          "\x8c\xc0\x8a\xaa\x9b\x63\xd1\xa1\x6f\x80\xef\x25\x54\xd7\x18\x9c\x41\x1f"
          "\x58\x69\xca\x52\xc5\xb8\x3f\xa3\x6f\xf2\x16\xb9\xc1\xd3\x00\x62\xbe\xbc"
          "\xfd\x2d\xc5\xbc\xe0\x91\x19\x34\xfd\xa7\x9a\x86\xf6\xe6\x98\xce\xd7\x59"
          "\xc3\xff\x9b\x64\x77\x33\x8f\x3d\xa4\xf9\xcd\x85\x14\xea\x99\x82\xcc\xaf"
          "\xb3\x41\xb2\x38\x4d\xd9\x02\xf3\xd1\xab\x7a\xc6\x1d\xd2\x9c\x6f\x21\xba"
          "\x5b\x86\x2f\x37\x30\xe3\x7c\xfd\xc4\xfd\x80\x6c\x22\xf2\x21",
          1, 3000 },
        { 96, 256, 2,
          "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91"
          "\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f",
          "\x07\x00\x00\x00\x40\x41\x42\x43\x44\x45\x46\x47",
          "\x4c\x61\x64\x69\x65\x73\x20\x61\x6e\x64\x20\x47\x65\x6e\x74\x6c\x65\x6d"
          "\x65\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x20\x6f\x66"
          "\x20\x27\x39\x39\x3a\x20\x49\x66\x20\x49\x20\x63\x6f\x75\x6c\x64\x20\x6f"
          "\x66\x66\x65\x72\x20\x79\x6f\x75\x20\x6f\x6e\x6c\x79\x20\x6f\x6e\x65\x20"
          "\x74\x69\x70\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x66\x75\x74\x75\x72\x65"
          "\x2c\x20\x73\x75\x6e\x73\x63\x72\x65\x65\x6e\x20\x77\x6f\x75\x6c\x64\x20"
          "\x62\x65\x20\x69\x74\x2e",
          "\xd3\x1a\x8d\x34\x64\x8e\x60\xdb\x7b\x86\xaf\xbc\x53\xef\x7e\xc2\xa4\xad"
          "\xed\x51\x29\x6e\x08\xfe\xa9\xe2\xb5\xa7\x36\xee\x62\xd6\x3d\xbe\xa4\x5e"
          "\x8c\xa9\x67\x12\x82\xfa\xfb\x69\xda\x92\x72\x8b\x1a\x71\xde\x0a\x9e\x06"
          "\x0b\x29\x05\xd6\xa5\xb6\x7e\xcd\x3b\x36\x92\xdd\xbd\x7f\x2d\x77\x8b\x8c"
          "\x98\x03\xae\xe3\x28\x09\x1b\x58\xfa\xb3\x24\xe4\xfa\xd6\x75\x94\x55\x85"
          "\x80\x8b\x48\x31\xd7\xbc\x3f\xf4\xde\xf0\x8e\x4b\x7a\x9d\xe5\x76\xd2\x65"
          "\x86\xce\xc6\x4b\x61\x16",
          1, 912 },
        { 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0 }
};
