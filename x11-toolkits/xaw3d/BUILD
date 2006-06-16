cd  lib/Xaw3d                                                &&
ln  -s  ..  X11                                              &&
perl  -i  -pe  's/#  (EXTRA_INCLUDES = -I.)/$1/'  Imakefile  &&
perl  -i  -pe  's/#include <widec.h>//'           XawI18n.h  &&
sedit          's/#  (EXTRA_INCLUDES = -I.)/$1/'  Imakefile  &&
sedit          's/#include <widec.h>//'           XawI18n.h  &&
sedit          's/#define wcslen.*$//'            XawI18n.h  &&
sedit          's/#define wcscpy.*$//'            XawI18n.h  &&
sedit          's/#define wcsncpy.*$//'           XawI18n.h  &&
xmkmf                                                        &&
make  Makefiles                                              &&

if test "$(get_spell_provider $SPELL X11-LIBS)" = xorg-server; then
sedit "s:/X11R6::g" Makefile
fi                                                           &&

make
