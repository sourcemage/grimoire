default_build                                                   &&
# Backup existing kdm dir
if spell_ok $SPELL; then
  OLD_VERSION=$(installed_version $SPELL)                       &&
  if [[ ${VERSION:0:3} == ${OLD_VERSION:0:3} ]]     &&
     [[ -d "$INSTALL_ROOT/usr/share/config/kdm" ]]; then
    mkdir -p kdm-3.141594                                       &&
    echo "Backing up configuration files..."                    &&
    mv $KDE4DIR/share/config/kdm/{background,kdm}rc    \
                                                kdm-3.141594    &&
    rm -rf $KDE4DIR/share/config/kdm
  fi
fi

