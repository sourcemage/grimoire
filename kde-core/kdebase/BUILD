OPTS="$OPTS  $KDEBASE_XCONSOLE  $KDEBASE_DPMS  $KDEBASE_XDMCP"  &&

#
# Kerberos has linking errors :(
#
#if  [  "$KDEBASE_KRB4"  ==  "y"  ];  then
#  OPTS="$OPTS  --with-krb4"
#fi  &&
#
#if  [  "$KDEBASE_KRB5"  ==  "y"  ];  then
#  OPTS="$OPTS  --with-krb5auth"
#fi  &&

.  $SECTION_DIRECTORY/KDE_BUILD

# Backup existing kdm dir
if spell_ok $SPELL; then
  OLD_VERSION=$(installed_version $SPELL)                       &&
  if [[ ${VERSION:0:3} == ${OLD_VERSION:0:3} ]]     &&
     [[ -d "$INSTALL_ROOT/usr/share/config/kdm" ]]; then
    mkdir -p $TMP_DIR/kdm                                       &&
    echo "Backing up configuration files..."                    &&
    mv $INSTALL_ROOT/usr/share/config/kdm/{background,kdm}rc    \
                                                $TMP_DIR/kdm    &&
    rm -rf $INSTALL_ROOT/usr/share/config/kdm
  fi
fi
