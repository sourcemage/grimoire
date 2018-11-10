local GCC=gcc           &&
local GNATMAKE=gnatmake &&

local xmlada_src="$SOURCE_DIRECTORY/xmlada-gpl-${VERSION}-src" &&

local bin_progs="gprbuild gprconfig gprclean gprinstall gprname gprls" &&
local lib_progs="gprlib gprbind" &&

local incflags="-Isrc -Igpr/src -I${xmlada_src}/sax -I${xmlada_src}/dom \
	-I${xmlada_src}/schema -I${xmlada_src}/unicode \
	-I${xmlada_src}/input_sources"

${GCC} -c ${CFLAGS} gpr/src/gpr_imports.c -o gpr_imports.o &&

for bin in ${bin_progs}; do
	${GNATMAKE} ${incflags} $ADAFLAGS ${bin}-main \
		-o ${bin} -largs gpr_imports.o || return 1
done &&

for lib in $lib_progs; do
	${GNATMAKE} ${incflags} ${lib} $ADAFLAGS \
		-largs gpr_imports.o || die
done

