sedit 's/\/usr\/local/\/usr/' config.mk &&
sedit 's/\${PREFIX}\/etc/\/etc/' config.mk &&
#ugly hack to prevent static linking
sedit 's/-static//' util/Makefile &&

make clean install
