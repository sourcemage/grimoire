OPTS="$OPENOFFICE_ODK                                         \
      $OPENOFFICE_QA                                          \
      --disable-epm                                           \
      --disable-ldap                                          \
      --disable-mozilla                                       \
      --without-gpc                                           \
      --without-myspell-dicts                                 \
      --with-system-alloc="system"                            \
      --with-system-stdlibs                                   \
      --with-lang=${LANGUAGE}                                 \
      --with-dict=${DICTIONARY}                               \
      $OPTS"                                                  &&

#
# If not using Xorg modular, then we have a 'normal' X install
#
if  !  check_if_xorg_modular_server;  then
  OPTS="--with-system-xrender-headers  \
        $OPTS"
fi  &&

if  [[  "$(get_spell_provider  $SPELL  JAVA)"  ==  "gcj"  ]];  then
  OPTS="--with-java=gij  \
        $OPTS"
fi  &&

source  $INSTALL_ROOT/etc/profile.d/java.sh  &&
source  $INSTALL_ROOT/etc/profile.d/ant.sh   &&

cd  $SOURCE_DIRECTORY/config_office                  &&
./configure --prefix=${INSTALL_ROOT}/usr             \
        --sysconfdir=${INSTALL_ROOT}/etc             \
     --localstatedir=${INSTALL_ROOT}/var             \
            --mandir=${INSTALL_ROOT}/usr/share/man   \
           --infodir=${INSTALL_ROOT}/usr/share/info  \
                     $OPTS                           &&

cd  $SOURCE_DIRECTORY  &&

if    [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "ia32"    ]];  then
  source  LinuxX86Env.Set.sh
elif  [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "x86_64"  ]];  then
  source  LinuxX86-64Env.Set.sh
else
  echo  "Platform not supported yet."  &&
  return  1
fi  &&

./bootstrap                 &&
dmake
