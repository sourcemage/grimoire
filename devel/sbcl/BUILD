if spell_ok sbcl ; then
  sh  make.sh  --prefix=$INSTALL_ROOT/usr --xc-host=$INSTALL_ROOT/usr/bin/sbcl
else
  SBCL_HOME=$SOURCE_DIRECTORY/sbcl-bin/lib/sbcl  \
  sh  make.sh  --prefix=$INSTALL_ROOT/usr --xc-host=$SOURCE_DIRECTORY/sbcl-bin/bin/sbcl
fi
