. $SECTION_DIRECTORY/java-functions

set_ant_env  &&

# create build.properties
cat > $SOURCE_DIRECTORY/build.properties <<EOF
junit.home=${SM_IBM_HOME}/junit
junit.jar=\${junit.home}/junit.jar
EOF

ant  dist
