#ifndef NB_SHA2_H
#define NB_SHA2_H

#include_next <sha2.h>

typedef SHA2_CTX SHA256_CTX;
typedef SHA2_CTX SHA384_CTX;
typedef SHA2_CTX SHA512_CTX;

#define SHA256_Update	SHA256Update
#define SHA384_Update	SHA384Update
#define SHA512_Update	SHA512Update

#define SHA256_Init	SHA256Init
#define SHA384_Init	SHA384Init
#define SHA512_Init	SHA512Init

#define SHA256_Final	SHA256Final
#define SHA384_Final	SHA384Final
#define SHA512_Final	SHA512Final

#define SHA256_End	SHA256End
#define SHA384_End	SHA384End
#define SHA512_End	SHA512End

#define SHA256_Data	SHA256Data
#define SHA384_Data	SHA384Data
#define SHA512_Data	SHA512Data

#define SHA256_File	SHA256File
#define SHA384_File	SHA384File
#define SHA512_File	SHA512File

#define SHA256_FileChunk	SHA256FileChunk
#define SHA384_FileChunk	SHA384FileChunk
#define SHA512_FileChunk	SHA512FileChunk

#endif
