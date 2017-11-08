INCLUDEPATH *= $$system(pwd)/lib

HEADERS *= $$system(pwd)/lib/base58.h \
	$$system(pwd)/lib/prevector.h \
	$$system(pwd)/lib/uint256.h \
	$$system(pwd)/lib/utilstrencodings.h \
	$$system(pwd)/lib/crypto/common.h \
	$$system(pwd)/lib/crypto/ripemd160.h \
	$$system(pwd)/lib/crypto/hmac_sha512.h \
	$$system(pwd)/lib/crypto/sha512.h \
	$$system(pwd)/lib/crypto/sha256.h \
	$$system(pwd)/lib/version.h \
	$$system(pwd)/lib/tinyformat.h \
	$$system(pwd)/lib/support/allocators/zeroafterfree.h \
	$$system(pwd)/lib/support/cleanse.h \
	$$system(pwd)/lib/compat/byteswap.h \
	$$system(pwd)/lib/compat/endian.h \
	$$system(pwd)/lib/hash.h \
	$$system(pwd)/lib/serialize.h \
	$$system(pwd)/lib/base58checktranscoder.h

SOURCES *= $$system(pwd)/lib/uint256.cpp \
	$$system(pwd)/lib/base58.cpp \
	$$system(pwd)/lib/utilstrencodings.cpp \
	$$system(pwd)/lib/crypto/sha256.cpp \
	$$system(pwd)/lib/crypto/sha512.cpp \
	$$system(pwd)/lib/crypto/ripemd160.cpp \
	$$system(pwd)/lib/hash.cpp \
	$$system(pwd)/lib/support/cleanse.cpp \
	$$system(pwd)/lib/crypto/hmac_sha512.cpp \
	$$system(pwd)/lib/base58checktranscoder.cpp
