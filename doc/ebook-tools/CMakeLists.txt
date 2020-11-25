include_directories( .  ${LIBXML2_INCLUDE_DIR} ${LIBZIP_INCLUDE_DIR})
add_library (epub SHARED epub.c ocf.c opf.c linklist.c list.c)
target_link_libraries (epub libzip::zip ${LIBXML2_LIBRARIES})

set_target_properties (epub PROPERTIES VERSION 0.2.2 SOVERSION 0)

install ( TARGETS epub RUNTIME DESTINATION bin LIBRARY DESTINATION lib )
install ( FILES epub.h epub_shared.h epub_version.h DESTINATION include )
