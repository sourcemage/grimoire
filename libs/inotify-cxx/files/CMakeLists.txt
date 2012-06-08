# Project
project(inotify-cxx)
set(MAJOR_VERSION 0)
set(MINOR_VERSION 7)
set(SUB_VERSION 4)
set(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}.${SUB_VERSION})
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

# CMake
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
   set(CMAKE_BUILD_TYPE     Debug)
endif("${CMAKE_BUILD_TYPE}" STREQUAL "")
set(CMAKE_COLOR_MAKEFILE ON)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Packaging
set(CPACK_COMPONENTS_ALL sharedlibs staticlibs headers)
set(CPACK_COMPONENT_SHAREDLIBS_DISPLAY_NAME "Shared libraries")
set(CPACK_COMPONENT_STATICLIBS_DISPLAY_NAME "Static libraries")
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME    "C++ Headers")

set(CPACK_COMPONENT_SHAREDLIBS_DESCRIPTION "Shared library for general use.")
set(CPACK_COMPONENT_STATICLIBS_DESCRIPTION "Static library, used to embed everything in your executable.")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION    "C/C++ header files.")

set(CPACK_COMPONENT_SHAREDLIBS_GROUP "Development")
set(CPACK_COMPONENT_STATICLIBS_GROUP "Development")
set(CPACK_COMPONENT_HEADERS_GROUP    "Development")

# Create suffix to eventually install in lib64
#IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(LIB_SUFFIX "")
    SET(PACK_ARCH "")
#  ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
#    SET(LIB_SUFFIX 64)
#    SET(PACK_ARCH .x86_64)
#endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

# Package information
set(CPACK_PACKAGE_VERSION              ${VERSION_STRING})
set(CPACK_PACKAGE_CONTACT              "Gerd v. Egidy <gerd.von.egidy@intra2net.com>")
set(CPACK_PACKAGE_DESCRIPTION          "C++ Library to access inotify")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY  ${CPACK_PACKAGE_DESCRIPTION}
                                       )
# Package settings
set(CPACK_GENERATOR                    "DEB;RPM")
set(CPACK_CMAKE_GENERATOR              "Unix Makefiles")
set(CPACK_PACKAGE_NAME                 ${PROJECT_NAME})
set(CPACK_PACKAGE_FILE_NAME            ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}${PACK_ARCH})

set(CPACK_RESOURCE_FILE_LICENSE        ${CMAKE_SOURCE_DIR}/LICENSE-GPL)
set(CPACK_RESOURCE_FILE_LICENSE        ${CMAKE_SOURCE_DIR}/LICENSE-LGPL)
set(CPACK_RESOURCE_FILE_LICENSE        ${CMAKE_SOURCE_DIR}/LICENSE-X11)

set(CPACK_SOURCE_GENERATOR             TGZ)
set(CPACK_SOURCE_PACKAGE_FILE_NAME     ${CPACK_PACKAGE_FILE_NAME})
set(CPACK_SET_DESTDIR "ON")

set(cpp_sources   inotify-cxx.cpp)
set(cpp_headers   inotify-cxx.h)

# shared lib
add_library(inotify-cxx SHARED ${cpp_sources})
set_target_properties(inotify-cxx PROPERTIES
                                  VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${SUB_VERSION}
                                  SOVERSION 0)
# increase SOVERSION on every backwards-incompatible change!

# static lib
add_library(inotify-cxx-static STATIC ${cpp_sources})
set_target_properties(inotify-cxx-static PROPERTIES OUTPUT_NAME "inotify-cxx")

# Prevent clobbering each other during the build
set_target_properties(inotify-cxx PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(inotify-cxx-static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

install( TARGETS inotify-cxx
            LIBRARY DESTINATION lib${LIB_SUFFIX}
            COMPONENT sharedlibs
            )

install( TARGETS inotify-cxx-static
            ARCHIVE DESTINATION lib${LIB_SUFFIX}
            COMPONENT staticlibs
            )

install( FILES ${cpp_headers}
            DESTINATION include
            COMPONENT headers
            )


# pkgconfig
set(prefix      ${CMAKE_INSTALL_PREFIX})
set(exec_prefix ${CMAKE_INSTALL_PREFIX}/bin)
set(includedir  ${CMAKE_INSTALL_PREFIX}/include)
set(libdir      ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX})

configure_file(${CMAKE_SOURCE_DIR}/inotify-cxx.pc.in ${CMAKE_BINARY_DIR}/inotify-cxx.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/inotify-cxx.pc DESTINATION lib${LIB_SUFFIX}/pkgconfig)

include(CPack)
