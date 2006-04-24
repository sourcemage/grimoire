(
 
  . $SECTION_DIRECTORY/java-functions
  
  set_ant_env		&&
  
  cd  build 		&&
  ant package-tgz 	&&
  
# ToDO : succesfullt pass the test
#  ant  test		&&

  prepare_install 	&&
  
  extract_jakarta_dist ${PKG_NAME} ${PKG_NAME}-${VERSION} ${SOURCE} 			&&
  register_jakarta_jar ${PKG_NAME}-${VERSION}/velocity-1.3.1-rc2.jar  velocity.jar 	&&
  register_jakarta_jar ${PKG_NAME}-${VERSION}/velocity-dep-1.3.1-rc2.jar  velocity-dep.jar 
	
) > $C_FIFO 2>&1
