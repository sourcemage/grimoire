local FF PP TARGET UNIT              &&
if  [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]];  then
  TARGET=x86_64
else
  TARGET=i386
fi  &&


#create idemake.cfg
#LazarusDir=$SOURCE_DIRECTORY        &&
mkdir -p ~/.lazarus                 &&
cat > idemake.cfg << EOF
#-Fu\$(LazarusDir)/components/synedit/units/$TARGET-linux/
#-Fu\$(LazarusDir)/components/synedit/units/$TARGET-linux/
#-Fu\$(LazarusDir)/ideintf/units/$TARGET-linux/
#-Fu\$(LazarusDir)/lcl/units/$TARGET-linux/
#-Fu\$(LazarusDir)/lcl/units/$TARGET-linux/$LAZ_GUI/
#-Fu\$(LazarusDir)/components/codetools/units/$TARGET-linux/
#-Fu\$(LazarusDir)/packager/units/$TARGET-linux/
-Fu.
-dLCL
-dLCL${LAZ_GUI}
-dAddStaticPkgs
-Fi~/.lazarus/
EOF
#export LCL_PLATFORM=$LAZ_GUI          &&
make_single                           &&
make LCL_PLATFORM=$LAZ_GUI $OPTS      &&
UNIT=$SOURCE_DIRECTORY/components     &&
cd $SOURCE_DIRECTORY/components       &&
# only build the sqlite3 package
rm sqlite/sqlitelaz.lpk             &&
for FF in $LAZ_PACK;do
  if [[ $FF == lazreport ]];then
    FF=$FF/source
    echo -Fu${UNIT}/$FF/lib/$TARGET-linux/ >> ../idemake.cfg
  else
    echo -Fu${UNIT}/$FF/lib/$TARGET-linux/$LAZ_GUI/ >> ../idemake.cfg
  fi                                  &&
  cp ../idemake.cfg ~/.lazarus        &&
  cd $FF                              &&
  $SOURCE_DIRECTORY/lazbuild -B `ls *.lpk` --ws=$LAZ_GUI &&
# add to package list
  PP=`grep '<Name Value=' *.lpk|cut -d\" -f2`  &&
  echo $PP, >> $SOURCE_DIRECTORY/staticpackages.inc   &&
  cd -
done                                  &&
cd $SOURCE_DIRECTORY                  &&
cp staticpackages.inc ~/.lazarus      &&
make LCL_PLATFORM=$LAZ_GUI $OPTS idepkg     &&
cp ~/.lazarus/packagefiles.xml ./     &&
sed -i "s|$SOURCE_DIRECTORY|$TRACK_ROOT/usr/share/lazarus|" idemake.cfg &&
strip -s lazarus startlazarus         &&
make_normal
