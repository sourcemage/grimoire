if [[ "$NEDIT_WMCLASS" == "y" ]]
then
  patch -Np1 < ${SCRIPT_DIRECTORY}/nedit-5.5-svrname-in-wmclass.patch
fi &&
cd ${SOURCE_DIRECTORY}/makefiles &&
mv Makefile.linux Makefile.linux.tmp &&
sed -e "s/CFLAGS\=/CFLAGS:=-DBUILD_UNTESTED_NEDIT -DREPLACE_SCOPE /" \
    -e "s/-DUSE_LPR_PRINT_CMD/& \$\(CFLAGS\)/" \
    -e 's/\(LIBS=.*\) -Wl,-Bstatic -lXm -Wl,-Bdynamic \(.*\)/\1 -lXm \2 -lXft/' \
	Makefile.linux.tmp > Makefile.linux &&
rm Makefile.linux.tmp &&
cd ${SOURCE_DIRECTORY} &&
# echo to make build continue in case of untested build warning
echo | make linux
