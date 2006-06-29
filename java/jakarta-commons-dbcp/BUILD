. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&

# ant test 
export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar"

# create build.properties
cat > $SOURCE_DIRECTORY/${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}-src/build.properties <<EOF
base.path=${SM_JAKARTA_HOME}
commons-collections.home=\${base.path}/commons-collections
commons-collections.jar=\${commons-collections.home}/commons-collections.jar
commons-lang.home=\${base.path}/commons-lang/dist
commons-lang.jar=\${commons-lang.home}/commons-lang-2.0-dev.jar
commons-pool.home=\${base.path}/commons-pool/dist
commons-pool.jar=\${commons-pool.home}/commons-pool.jar
jdbc20ext.home=${SM_SUN_HOME}/jdbc2_0-stdext
jdbc20ext.lib=\${jdbc20ext.home}
jdbc20ext.jar=\${jdbc20ext.lib}/jdbc2_0-stdext.jar
junit.home=${SM_IBM_HOME}/junit
junit.lib=\${junit.home}
junit.jar=\${junit.lib}/junit.jar
jndi.home=${SM_SUN_HOME}/jndi
jndi.lib=\${jndi.home}/lib
jndi.jar=\${jndi.lib}/jndi.jar
EOF

cd  ${PKG_SUBPRJ}-${PKG_NAME}-${VERSION}-src &&
cp  LICENSE.txt ../LICENSE  &&
ant  dist
