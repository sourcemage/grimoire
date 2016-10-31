project(pugixml)
cmake_minimum_required(VERSION 3.6)
set(VERSION 1.7)
set(HEADERS src/pugixml.hpp src/pugiconfig.hpp)
set(SOURCES src/pugixml.cpp)

add_library(pugixml SHARED ${SOURCES})

set_target_properties(pugixml PROPERTIES VERSION ${VERSION} SOVERSION ${VERSION})

install(TARGETS pugixml LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
