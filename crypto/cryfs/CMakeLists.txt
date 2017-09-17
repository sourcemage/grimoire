# use own CMake script to build relevant bits of scrypt library
project (scrypt C)
set (SOURCES 
lib/crypto/crypto_scrypt.c
lib/crypto/crypto_scrypt_smix.c
lib/crypto/crypto_scrypt_smix_sse2.c

libcperciva/alg/sha256.c
libcperciva/cpusupport/cpusupport_x86_aesni.c
libcperciva/cpusupport/cpusupport_x86_sse2.c
libcperciva/crypto/crypto_aes_aesni.c
libcperciva/crypto/crypto_aes.c
libcperciva/crypto/crypto_aesctr.c
libcperciva/crypto/crypto_entropy.c
libcperciva/util/warnp.c
libcperciva/util/insecure_memzero.c
)

add_library(${PROJECT_NAME} STATIC
 ${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
 .
 libcperciva/cpusupport
 libcperciva/alg
 libcperciva/util
)

target_compile_options(${PROJECT_NAME} PRIVATE
#  -DCPUSUPPORT_X86_SSE2
  -DCONFIG_H_FILE="${CMAKE_CURRENT_SOURCE_DIR}/config.h"
  -DCPUSUPPORT_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/cpusupport-config.h"
)
