(

  case $MOZILLA_MAIL  in
    n|N)      OPTS="$OPTS --disable-mailnews"
              ;;
          *)  ;;
  esac

  case $MOZILLA_CHAT  in
    n|N)      OPTS="$OPTS --disable-chat"
              ;;
          *)  ;;
  esac

  case $MOZILLA_JAVA  in
    y|Y|j|J)  OPTS="$OPTS --enable-java-supplement"
              ;;
          *)  ;;
  esac

  case $MOZILLA_SVG  in
    y|Y|j|J)  OPTS="$OPTS --enable-svg"
              export MOZ_INTERNAL_LIBART_LGPL=1
              ;;
          *)  ;;
  esac

  case $MOZILLA_MATHML  in
    n|N)      OPTS="$OPTS --disable-mathml"
              ;;
          *)  ;;
  esac

  case $MOZILLA_LDAP  in
    y|Y|j|J)  OPTS="$OPTS --enable-ldap-experimental"
              ;;
          *)  ;;
  esac

  case $MOZILLA_XINERAMA  in
    y|Y|j|J)  OPTS="$OPTS --enable-xinerama"
              ;;
          *)  ;;
  esac

  case $MOZILLA_CRYPTO  in
    y|Y|j|J)  OPTS="$OPTS --enable-crypto"
              ;;
          *)  ;;
  esac

  export    CFLAGS="$(  echo  $CFLAGS    |  sed  s/-ffast-math//  )"
  export  CXXFLAGS="$(  echo  $CXXFLAGS  |  sed  s/-ffast-math//  )"

  ./configure  --disable-tests              \
               --disable-debug              \
               --disable-pedantic           \
               --enable-optimize="$CFLAGS"  \
               --without-jpeg               \
               --without-zlib               \
               --without-png                \
               $OPTS                        &&
  make                                      &&
  prepare_install                           &&


  if  !  grep  -q  "mozilla"  /etc/ld.so.conf
  then
    echo  "/usr/lib/mozilla"  >>  /etc/ld.so.conf
  fi

) > $C_FIFO 2>&1  &&  (

  rm     -f                          /usr/lib/mozilla/component.reg
  mkdir  -p                          /usr/lib/mozilla
  cp     -rL  dist/bin/*             /usr/lib/mozilla
  mkdir  -p                          /usr/include/mozilla
  cp	 -rL  dist/include/*         /usr/include/mozilla
  mkdir  -p                          /usr/include/moznss
  cp     -L   dist/public/security/* /usr/include/moznss  

  for  library  in  /usr/lib/mozilla/*.so;  do 
    libname=`basename  $library`
    ln  -sf  mozilla/$libname /usr/lib/$libname
  done

  cp  $SCRIPT_DIRECTORY/mozilla  /usr/bin

  #
  # Script to set MOZILLA_FIVE_HOME
  #
  cp  ${SCRIPT_DIRECTORY}/${SPELL}.sh  /etc/profile.d

  export  MOZILLA_FIVE_HOME=/usr/lib/mozilla
  export    LD_LIBRARY_PATH=/usr/lib/mozilla:$LD_LIBRARY_PATH

         /usr/lib/mozilla/regxpcom
         /usr/lib/mozilla/regchrome
  touch  /usr/lib/mozilla/chrome/user-skins.rdf
  touch  /usr/lib/mozilla/chrome/user-locales.rdf

# The following lines have been commented out since they break the spell.
# The reason is that somewhere before this check is done, the files from 
# /etc/mozilla are deleted leaving the tree intact, leaving mozilla with
# no config files what so ever. 

#  if [ -d /etc/mozilla ]; then
#    echo "Old mozilla config in /etc/mozilla kept."
#    echo "New default config moved to /usr/lib/mozilla/new-defaults."
#    mv /usr/lib/mozilla/defaults/ /usr/lib/mozilla/new-defaults/
#  else
#    mv     /usr/lib/mozilla/defaults/ /etc/mozilla
#  fi
#  ln -s  /etc/mozilla/ /usr/lib/mozilla/defaults
)
