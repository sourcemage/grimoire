cmake_minimum_required(VERSION 2.8.12)
set(SOVERSION "1")
set(VERSION "1.2.3")
#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#find_package(Readline REQUIRED)

add_library(duktape SHARED src/duktape.c)
set_target_properties(duktape PROPERTIES VERSION ${VERSION} SOVERSION ${SOVERSION})
install(TARGETS duktape DESTINATION lib)

install(FILES src/duktape.h DESTINATION include)
