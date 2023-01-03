# remove options not supported by ld.gold
LDFLAGS="${LDFLAGS//-Wl,-znoseparate-code}" &&
OPTS="$WEBKIT_OPTS $OPTS -DENABLE_GAMEPAD=false -DENABLE_WEBKIT_LEGACY=off -DCMAKE_SKIP_RPATH=on -DUSE_SYSTEM_MALLOC=on -DPORT=GTK" &&
sed -i '30i#include <unicode/utf8.h>' \
    Source/WebCore/platform/text/hyphen/HyphenationLibHyphen.cpp \
    Source/JavaScriptCore/runtime/JSGlobalObjectFunctions.cpp \
    Source/WTF/wtf/URLHelpers.cpp \
    Source/WTF/wtf/URLParser.cpp \
    Source/WTF/wtf/unicode/UTF8Conversion.cpp \
    Source/WebCore/dom/TextEncoder.cpp \
    Source/WebCore/xml/XSLTProcessorLibxslt.cpp &&
sed -i '30i#include <unicode/utf16.h>' \
    Source/WTF/wtf/text/StringBuilder.h \
    Source/WebCore/PAL/pal/text/TextCodecCJK.cpp \
    Source/WebCore/PAL/pal/text/TextCodecSingleByte.cpp &&
sed -i '26i#include <unicode/utf16.h>' \
    Source/WTF/wtf/text/StringImpl.h &&
sed -i '29i#include <unicode/utf16.h>' \
    Source/WTF/wtf/unicode/UTF8Conversion.h &&
cmake_build
