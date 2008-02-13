cd  $SOURCE_DIRECTORY/mozilla  &&

local  NVU_HOME=${INSTALL_ROOT}/usr/lib/nvu  &&

OPTS="--disable-mailnews                                              \
      --disable-installer                                             \
      --disable-activex                                               \
      --disable-activex-scripting                                     \
      --disable-tests                                                 \
      --disable-oji                                                   \
      --disable-necko-disk-cache                                      \
      --disable-profilesharing                                        \
      --disable-pedantic                                              \
      --disable-mathml                                                \
      --disable-freetype2                                             \
      --disable-svg                                                   \
      --disable-ldap                                                  \
      --disable-debug                                                 \
      --enable-reorder                                                \
      --enable-cpp-rtti                                               \
      --enable-xft                                                    \
      --enable-single-profile                                         \
      --enable-extensions=wallet,xml-rpc,xmlextras,pref,universalchardet,editor/cascades,spellcheck                                                   \
      --enable-necko-protocols=http,ftp,file,jar,viewsource,res,data  \
      --with-pthreads                                                 \
      --with-default-mozilla-five-home=$NVU_HOME                      \
      $OPTS"                                                          &&

default_build
