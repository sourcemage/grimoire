# - Try to find Firebird
# Once done this will define
#
#  FIREBIRD_FOUND - system has Firebird
#  FIREBIRD_INCLUDE_DIR - the Firebird include directory
#  FIREBIRD_LIBRARY - Link these to use Firebird
#  FIREBIRD_DEFINITIONS - Compiler switches required for using Firebird
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

cmake_policy(SET CMP0111 NEW)
if ( FIREBIRD_INCLUDE_DIR AND FIREBIRD_LIBRARY )
   # in cache already
   SET(Firebird_FIND_QUIETLY TRUE)
endif ()

FIND_PATH(FIREBIRD_INCLUDE_DIR NAMES ibase.h PATHS /opt/firebird5/include  /opt/firebird4/include)

FIND_LIBRARY(FIREBIRD_LIBRARY NAMES fbclient PATHS /opt/firebird5/lib /opt/firebird4/lib)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Firebird DEFAULT_MSG FIREBIRD_INCLUDE_DIR FIREBIRD_LIBRARY )

# show the FIREBIRD_INCLUDE_DIR and FIREBIRD_LIBRARY variables only in the advanced view
MARK_AS_ADVANCED(FIREBIRD_INCLUDE_DIR FIREBIRD_LIBRARY )

add_library(Firebird::firebird SHARED IMPORTED)
set_target_properties(Firebird::firebird PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES "${FIREBIRD_INCLUDE_DIR}"
	INTERFACE_LINK_LIBRARIES "-Wl,--as-needed"
	IMPORTED_LOCATION "${FIREBIRD_LIBRARY}"
)
