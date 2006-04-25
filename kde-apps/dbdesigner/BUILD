make
echo $?
if [ "$?" != 0 ]
then
	echo "${PROBLEM_COLOR}Okay it didn't build, this is a pretty messed up way of doing thing but I don't know how else to do it... :P\n${DEFAULT_COLOR}" &&
	(echo "#include <knuminput.h>" && cat dbdesign/metaseqedit.h) > dbdesign/metaseqedit.h.new &&
	mv dbdesign/metaseqedit.h.new dbdesign/metaseqedit.h &&
	make
fi
