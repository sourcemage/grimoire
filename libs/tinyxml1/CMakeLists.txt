project(tinyxml)

set(tinyxmlSources
	tinystr.cpp  tinyxml.cpp  tinyxmlerror.cpp  tinyxmlparser.cpp 
	)

set(tinyxmlHeaders
	tinystr.h  tinyxml.h
	)

add_definitions(-DTIXML_USE_STL)

add_library(tinyxml SHARED  ${tinyxmlSources} )
add_library(tinyxml_static STATIC  ${tinyxmlSources} )

install(TARGETS tinyxml
	DESTINATION lib)

install(TARGETS tinyxml_static
	DESTINATION lib)

install(FILES ${tinyxmlHeaders}
	DESTINATION include)


