OPTS="$VT_OPT $OPTS" &&
if [[ $VIRT_VER == stable ]];then
make_single    &&
# fix for missing file
echo 1.05.4401 > appsrc/ODS-Wiki/vad_version
fi  &&
default_build  &&
make_normal
