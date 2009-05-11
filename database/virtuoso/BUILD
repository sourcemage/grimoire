OPTS="$VT_OPT $OPTS" &&
if [[ $VIRT_VER == stable ]];then
# fix for missing file
echo 1.05.4401 > appsrc/ODS-Wiki/vad_version
fi  &&
make_single    &&
default_build  &&
make_normal
