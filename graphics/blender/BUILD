if [ "$BLENDER_PLAYER" == "WITH_BF_PLAYER=True" ]; then
   BLENDER_GAMEENGINE="WITH_BF_GAMEENGINE=True"
fi  &&

if is_depends_enabled $SPELL openjpeg; then

cat <<- EOF >> "${SOURCE_DIRECTORY}"/user-config.py
BF_OPENJPEG="/usr"
BF_OPENJPEG_INC="/usr/include"
BF_OPENJPEG_LIB="openjpeg"
EOF

fi  &&

#if is_depends_enabled $SPELL openexr; then
#
#cat <<- EOF >> "${SOURCE_DIRECTORY}"/user-config.py
#BF_OPENEXR="/usr"
#BF_OPENJPEG_INC="/usr/include"
#BF_OPENEXR_INC="${BF_OPENEXR}/include/OpenEXR ${BF_OPENEXR}/include"
#BF_OPENEXR_LIBPATH="${BF_OPENEXR}/lib"
#EOF
#
#fi  &&

if is_depends_enabled $SPELL lcms; then

cat <<- EOF >> "${SOURCE_DIRECTORY}"/user-config.py
BF_LCMS_INC="/usr/include/"
BF_LCMS_LIB="lcms"
BF_LCMS_LIBPATH="/usr/lib/"
EOF

fi  &&

echo "CFLAGS=[`for i in ${CFLAGS[@]}; do printf "%s \'$i"\',; done`] " \
     | sed -e "s:,]: ]:" >> "${SOURCE_DIRECTORY}"/user-config.py

local FILTERED_CXXFLAGS="`for i in ${CXXFLAGS[@]}; do printf "%s \'$i"\',; done`"
echo "CXXFLAGS=[${FILTERED_CXXFLAGS}]" | sed -e "s:,]: ]:" >> "${SOURCE_DIRECTORY}"/user-config.py
echo "BGE_CXXFLAGS=[${FILTERED_CXXFLAGS}]" | sed -e "s:,]: ]:" >> "${SOURCE_DIRECTORY}"/user-config.py

echo "CCFLAGS= ['-funsigned-char', '-D_LARGEFILE_SOURCE', '-D_FILE_OFFSET_BITS=64']" >> "${SOURCE_DIRECTORY}"/user-config.py

local FILTERED_LDFLAGS="`for i in ${LDFLAGS[@]}; do printf "%s \'$i"\',; done`"
echo "LINKFLAGS=[${FILTERED_LDFLAGS}]" | sed -e "s:,]: ]:" >> "${SOURCE_DIRECTORY}"/user-config.py
echo "PLATFORM_LINKFLAGS=[${FILTERED_LDFLAGS}]" | sed -e "s:,]: ]:" >> "${SOURCE_DIRECTORY}"/user-config.py

OPTS="WITHOUT_BF_PYTHON_INSTALL=True WITH_BF_3DMOUSE=False $BLENDER_PLAYER $BLENDER_GAMEENGINE $BLENDER_OCEANSIM $BLENDER_OGG $OPTS"

python ./scons/scons.py $OPTS

make CFLAGS="${CFLAGS} -fPIC" LDFLAGS="-Bshareable" -C release/plugins
