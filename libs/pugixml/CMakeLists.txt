project(pugixml)
cmake_minimum_required(VERSION 2.8.11)
set(VERSION 1.2)
set(HEADERS src/pugixml.hpp src/pugiconfig.hpp)
set(SOURCES ${HEADERS} src/pugixml.cpp)

add_library(pugixml SHARED ${SOURCES})

set_target_properties(pugixml PROPERTIES VERSION ${VERSION} SOVERSION ${VERSION})

install(TARGETS pugixml LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
