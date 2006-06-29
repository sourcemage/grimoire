. $SECTION_DIRECTORY/java-functions
  
set_ant_env  &&

export CLASSPATH="${JAVA_HOME}/lib/tools.jar:${JAVA_HOME}/lib/classes.zip:${ANT_HOME}/lib/ant.jar"

# create build.properties
cat > $SOURCE_DIRECTORY/jakarta-${SPELL}-${VERSION}-src/build.properties <<EOF
# -----------------------------------------------------------------------------
# Source Mage GNU/Linux Tomcat ${VERSION} build.properties
# -----------------------------------------------------------------------------
# ----- Compile Control Flags -----
compile.debug=on
compile.deprecation=off
compile.optimize=on
# ----- Build Control Flags
#Build all components
#full.dist=on
#Build lightweight JDK 1.4 distribution
#light.dist=on
#Hide configuration flags display
#flags.hide=on
#Version number
version=4.1
#Proxy to download subproject
#proxy.host=proxy.domain
#proxy.port=8080
#proxy.use=on
#CVS root for the jakarta subprojects that do not have released yet.
cvsroot=":pserver:anoncvs@cvs.apache.org:/home/cvspublic"
# ----- Default Base Path for Dependent Packages -----
base.path=${SM_JAKARTA_HOME}
# ----- Jakarta Tomcat Connectors source path -----
jtc.home=../../jakarta-tomcat-connectors-${VERSION}-src
# ----- Jakarta Tomcat Jasper source path -----
#jasper.home=../jakarta-tomcat-jasper/jasper2
jasper.home=jasper
# --------------------------------------------------
#                REQUIRED LIBRARIES
# --------------------------------------------------
# ----- Commons Beanutils, version 1.1 or later -----
commons-beanutils.home=\${base.path}/commons-beanutils
commons-beanutils.lib=\${commons-beanutils.home}/dist
commons-beanutils.jar=\${commons-beanutils.lib}/commons-beanutils.jar
commons-beanutils.loc=http://www.apache.org/dist/jakarta/commons/beanutils/binaries/commons-beanutils-1.6.1.tar.gz
# ----- Commons Collections, version 1.0 or later -----
commons-collections.home=\${base.path}/commons-collections
commons-collections.lib=\${commons-collections.home}
commons-collections.jar=\${commons-collections.lib}/commons-collections.jar
commons-collections.loc=http://www.apache.org/dist/jakarta/commons/collections/binaries/collections-2.1.tar.gz
# ----- Commons Digester, version 1.1.1 or later -----
commons-digester.home=\${base.path}/commons-digester
commons-digester.lib=\${commons-digester.home}/dist
commons-digester.jar=\${commons-digester.lib}/commons-digester.jar
commons-digester.loc=http://www.apache.org/dist/jakarta/commons/digester/binaries/commons-digester-1.4.1.tar.gz
# ----- Commons FileUpload, nightly build -----
commons-fileupload.home=\${base.path}/commons-fileupload/dist
commons-fileupload.lib=\${commons-fileupload.home}
commons-fileupload.jar=\${commons-fileupload.lib}/commons-fileupload-1.0-dev.jar
commons-fileupload.loc=http://www.apache.org/dist/jakarta/commons/fileupload/commons-fileupload-1.0-beta-1.tar.gz 
# ----- Commons Logging, version 1.0.1 or later -----
commons-logging.home=\${base.path}/commons-logging
commons-logging.lib=\${commons-logging.home}
commons-logging-api.jar=\${commons-logging.lib}/commons-logging-api.jar
commons-logging.jar=\${commons-logging.lib}/commons-logging.jar
commons-logging.loc=http://jakarta.apache.org/builds/jakarta-commons/release/commons-logging/v1.0.2/commons-logging-1.0.2.tar.gz
# ----- Java Naming and Directory Interface (JNDI), version 1.2 or later -----
# Note: Optional with JDK 1.3+
jndi.home=${SM_SUN_HOME}/jndi
jndi.lib=\${jndi.home}/lib
jndi.jar=\${jndi.lib}/jndi.jar
ldap.jar=\${jndi.lib}/ldap.jar
jaas.jar=\${jndi.lib}/jaas.jar
# ----- Jakarta Regular Expressions Library, version 1.2 -----
regexp.home=\${base.path}/regexp
regexp.lib=\${regexp.home}
regexp.jar=\${regexp.lib}/jakarta-regexp-1.2.jar
regexp.loc=http://jakarta.apache.org/builds/jakarta-regexp/release/v1.2/jakarta-regexp-1.2.tar.gz
# ----- Jakarta Servlet API Classes (Servlet 2.3 / JSP 1.2) -----
servlet.home=\${base.path}/servletapi-4
servlet.lib=\${servlet.home}/lib
servlet.jar=\${servlet.lib}/servlet.jar
servlet.loc=jakarta-servletapi-4
# ----- Xerces XML Parser, version 1.4.4 to 2.0.0 Beta 4 -----
# Note: Optional with JDK 1.4+
#xerces.home=\${base.path}/xerces
#xerces.lib=\${xerces.home}
#xerces.jar=\${xerces.lib}/xercesImpl.jar
# ----- Xerces XML Parser, version 2.0.0 or later -----
# Note: Optional with JDK 1.4+, or if Xerces 1.x is present
xerces.home=\${base.path}/xerces
xerces.lib=\${xerces.home}
xercesImpl.jar=\${xerces.lib}/xercesImpl.jar
xmlParserAPIs.jar=\${xerces.lib}/xmlParserAPIs.jar
xerces.loc=http://xml.apache.org/dist/xerces-j/Xerces-J-bin.2.3.0.tar.gz
# --------------------------------------------------
#                OPTIONAL LIBRARIES
# --------------------------------------------------
# ----- Java Activation Framework (JAF), version 1.0.1 or later -----
activation.home=${SM_SUN_HOME}/jaf
activation.lib=\${activation.home}
activation.jar=\${activation.lib}/activation.jar
# ----- Commons Daemon, version 20020219 or later -----
commons-daemon.home=\${base.path}/commons-daemon/dist
commons-daemon.lib=\${commons-daemon.home}
commons-daemon.jar=\${commons-daemon.lib}/commons-daemon.jar
commons-daemon.loc=jakarta-commons-sandbox/daemon
# ----- Commons DBCP, version 1.0 or later -----
commons-dbcp.home=\${base.path}/commons-dbcp/dist
commons-dbcp.lib=\${commons-dbcp.home}
commons-dbcp.jar=\${commons-dbcp.lib}/commons-dbcp.jar
commons-dbcp.loc=http://jakarta.apache.org/builds/jakarta-commons/release/commons-dbcp/v1.0/commons-dbcp-1.0.zip
# ----- Commons Modeler, version 1.0 or later -----
commons-modeler.home=\${base.path}/commons-modeler/dist
commons-modeler.lib=\${commons-modeler.home}
commons-modeler.jar=${SM_JAKARTA_HOME}/lib/commons-modeler.jar
#commons-modeler.jar=\${commons-modeler.lib}/commons-modeler.jar
commons-modeler.loc=http://jakarta.apache.org/builds/jakarta-commons/release/commons-modeler/v1.0/commons-modeler-1.0.tar.gz
# ----- Commons Pool, version 1.0 or later -----
commons-pool.home=\${base.path}/commons-pool/dist
commons-pool.lib=\${commons-pool.home}
commons-pool.jar=\${commons-pool.lib}/commons-pool.jar
commons-pool.loc=http://jakarta.apache.org/builds/jakarta-commons/release/commons-pool/v1.0.1/commons-pool-1.0.1.tar.gz
# ----- JavaService, version 1.2.0 or later -----
javaservice.home=\${base.path}/javaservice
javaservice.loc=http://www.alexandriasc.com/software/JavaService/JavaService-bin-1.2.0.zip
# ----- Java Database Connectivity (JDBC) Optional Package, version 2.0 -----
jdbc20ext.home=${SM_SUN_HOME}/jdbc2_0-stdext
jdbc20ext.lib=\${jdbc20ext.home}
jdbc20ext.jar=\${jdbc20ext.lib}/jdbc2_0-stdext.jar
# ----- Java Management Extensions (JMX), JMX RI 1.0.1 or later or MX4J 1.0 or later -----
jmx.home=${SM_OTH_HOME}/mx4j
jmx.lib=\${jmx.home}/lib
jmx.jar=\${jmx.lib}/mx4j-jmx.jar
jmx.loc=http://telia.dl.sourceforge.net/sourceforge/mx4j/mx4j-1.1.1.tar.gz
# ----- Java Secure Sockets Extension (JSSE), version 1.0.2 or later -----
#jsse.home=\${base.path}/jsse-1.0.2
#jsse.lib=\${jsse.home}/lib
#jcert.jar=\${jsse.lib}/jcert.jar
#jnet.jar=\${jsse.lib}/jnet.jar
#jsse.jar=\${jsse.lib}/jsse.jar
# ----- Java Transaction API (JTA), version 1.0.1 or later -----
jta.home=${SM_SUN_HOME}/jta
jta.lib=\${jta.home}
jta.jar=\${jta.lib}/jta.jar
# ----- JUnit Unit Test Suite, version 3.7 or later -----
junit.home=${SM_IBM_HOME}/junit
junit.lib=\${junit.home}
junit.jar=\${junit.lib}/junit.jar
junit.loc=http://download.sourceforge.net/junit/junit3.7.zip
# ----- Java Mail, version 1.2 or later -----
mail.home=${SM_SUN_HOME}/javamail
mail.lib=\${mail.home}
mail.jar=\${mail.lib}/mail.jar
# ----- NSIS, version 1.9x -----
#nsis.home=\${base.path}/nsis
#nsis.loc=http://www.nullsoft.com/free/nsis/nsis198.exe
# ----- PureTLS Extension, version 0.9 or later -----
#puretls.home=\${base.path}/puretls-0.9b2
#puretls.lib=\${puretls.home}/build
#puretls.jar=\${puretls.lib}/puretls.jar
# ----- Struts, version 1.0.1 or later -----
struts.home=\${base.path}/struts
struts.lib=\${struts.home}/lib
struts.jar=\${struts.lib}/struts.jar
struts.loc=http://jakarta.apache.org/builds/jakarta-struts/release/v1.0.2/jakarta-struts-1.0.2.tar.gz
# ----- Tyrex Data Source, version 1.0 -----
#tyrex.home=\${base.path}/tyrex-1.0
#tyrex.lib=\${tyrex.home}
#tyrex.jar=\${tyrex.lib}/tyrex-1.0.jar
#tyrex.loc=ftp://ftp.exolab.org/pub/tyrex/tyrex-1.0/tyrex-1.0.jar
EOF

cd  jakarta-${SPELL}-${VERSION}-src  &&
ln  -s ../jakarta-${SPELL}-connectors-${VERSION}-src jakarta-${SPELL}-connectors-${VERSION}-src &&
  
ant  detect  &&
ant  dist
