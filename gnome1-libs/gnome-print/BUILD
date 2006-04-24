patch  -p1  <  $SCRIPT_DIRECTORY/ftfix.patch  &&
# this instruction changes the order of arguments to ltconfig and forces HOST value
sedit "s|\$libtool_flags --no-verify \$ac_aux_dir/ltmain.sh \$lt_target|--no-verify \$libtool_flags \$ac_aux_dir/ltmain.sh $HOST|g" configure &&
default_build
