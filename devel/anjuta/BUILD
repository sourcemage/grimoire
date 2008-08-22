if [[ "${ANJUTA_SCINTALLA}" == "n" ]]; then
   OPTS="--disable-plugin-scintilla ${OPTS}"
fi  &&

if [[ "${ANJUTA_VALGRIND}" == "n" ]]; then
   OPTS="--disable-plugin-valgrind ${OPTS}"
fi  &&

if [ "$CVS_CHECKOUT" == "y" ]
then
	./autogen.sh
fi &&

make_single    &&
default_build  &&
make_normal
