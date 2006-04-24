# create our own config file
cat << EOF > setup.cfg &&
[manual_config]
# Enable assert()ions in the C layer?
checked_build=0
database_is_firebird=1
database_home_dir=$INSTALL_ROOT/usr/firebird
[build]
[install]
compile=1
optimize=1
EOF
  python setup.py build
