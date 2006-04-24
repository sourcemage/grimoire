(

  . $SECTION_DIRECTORY/java-functions

  set_java_env  	&&
  
  chmod  a+x  build.sh	&&
  ./build.sh  pack-bin	&&
  
  prepare_install				&&
  
  extract_jakarta_dist  xerces  xerces-${PKG_VERSION}  build/${PKG_SPELL}-bin.${VERSION}.tar.gz &&
  register_jakarta_jar  xerces-${PKG_VERSION}/xercesImpl.jar	xercesImpl.jar			&&
  register_jakarta_jar  xerces-${PKG_VERSION}/xml-apis.jar	xml-apis.jar			&&
  register_jakarta_jar  xerces-${PKG_VERSION}/xmlParserAPIs.jar xmlParserAPIs.jar
  
) > $C_FIFO 2>&1
