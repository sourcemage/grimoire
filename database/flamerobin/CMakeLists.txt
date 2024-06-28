cmake_minimum_required(VERSION 3.16)
project(flamerobin)

set(CMAKE_CXX_STANDARD 14)

#--------------------------------------
# wxWidgets location


# We want the wx static build, and Unicode support
set(wxWidgets_USE_STATIC ON)
set(wxWidgets_USE_UNICODE ON)

# Find the wxWidgets library
find_package(wxWidgets REQUIRED core base html xml aui stc adv OPTIONAL_COMPONENTS scintilla)
message(STATUS "wxWidgets version : ${wxWidgets_VERSION_STRING}")


# Add wxWidgets to include path
include(${wxWidgets_USE_FILE})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(Firebird REQUIRED)

#--------------------------------------
# Source files

# FlameRobin app source files



set_source_files_properties(
  src/gui/InsertDialog.cpp
  src/gui/InsertParametersDialog.cpp
  src/gui/PreferencesDialogSettings.cpp
  PROPERTIES SKIP_UNITY_BUILD_INCLUSION true)


list(APPEND SOURCE_LIST
       src/addconstrainthandler.cpp
       src/databasehandler.cpp
       src/frprec.cpp
       src/frutils.cpp
       src/logger.cpp
       src/main.cpp
       src/MasterPassword.cpp
       src/objectdescriptionhandler.cpp
       src/statementHistory.cpp
       src/config/Config.cpp
       src/config/DatabaseConfig.cpp
       src/config/LocalSettings.cpp
       src/core/ArtProvider.cpp
       src/core/CodeTemplateProcessor.cpp
       src/core/FRDecimal.cpp
       src/core/FRError.cpp
       src/core/FRInt128.cpp
       src/core/Observer.cpp
       src/core/ProgressIndicator.cpp
       src/core/StringUtils.cpp
       src/core/Subject.cpp
       src/core/TemplateProcessor.cpp
       src/core/URIProcessor.cpp
       src/core/Visitor.cpp
       src/engine/MetadataLoader.cpp
       src/gui/AboutBox.cpp
       src/gui/AdvancedMessageDialog.cpp
       src/gui/AdvancedSearchFrame.cpp
       src/gui/BackupFrame.cpp
       src/gui/BackupRestoreBaseFrame.cpp
       src/gui/BaseDialog.cpp
       src/gui/BaseFrame.cpp
       src/gui/CommandManager.cpp
       src/gui/ConfdefTemplateProcessor.cpp
       src/gui/ContextMenuMetadataItemVisitor.cpp
       src/gui/CreateIndexDialog.cpp
       src/gui/DatabaseRegistrationDialog.cpp
       src/gui/DataGeneratorFrame.cpp
       src/gui/EditBlobDialog.cpp
       src/gui/EventWatcherFrame.cpp
       src/gui/ExecuteSql.cpp
       src/gui/ExecuteSqlFrame.cpp
       src/gui/FieldPropertiesDialog.cpp
       src/gui/FindDialog.cpp
       src/gui/FRLayoutConfig.cpp
       src/gui/FRStyle.cpp
       src/gui/GUIURIHandlerHelper.cpp
       src/gui/HtmlHeaderMetadataItemVisitor.cpp
       src/gui/HtmlTemplateProcessor.cpp
       src/gui/InsertDialog.cpp
       src/gui/InsertParametersDialog.cpp
       src/gui/MainFrame.cpp
       src/gui/MetadataItemPropertiesFrame.cpp
       src/gui/MultilineEnterDialog.cpp
       src/gui/PreferencesDialog.cpp
       src/gui/PreferencesDialogSettings.cpp
       src/gui/PrivilegesDialog.cpp
       src/gui/ProgressDialog.cpp
       src/gui/ReorderFieldsDialog.cpp
       src/gui/RestoreFrame.cpp
       src/gui/ServerRegistrationDialog.cpp
       src/gui/ServiceBaseFrame.cpp
       src/gui/ShutdownFrame.cpp
       src/gui/ShutdownStartupBaseFrame.cpp
       src/gui/SimpleHtmlFrame.cpp
       src/gui/StartupFrame.cpp
       src/gui/StatementHistoryDialog.cpp
       src/gui/StyleGuide.cpp
       src/gui/UserDialog.cpp
       src/gui/UsernamePasswordDialog.cpp
       src/gui/controls/ControlUtils.cpp
       src/gui/controls/DataGrid.cpp
       src/gui/controls/DataGridRowBuffer.cpp
       src/gui/controls/DataGridRows.cpp
       src/gui/controls/DataGridTable.cpp
       src/gui/controls/DBHTreeControl.cpp
       src/gui/controls/DndTextControls.cpp
       src/gui/controls/LogTextControl.cpp
       src/gui/controls/PrintableHtmlWindow.cpp
       src/gui/controls/TextControl.cpp
       src/metadata/CharacterSet.cpp
       src/metadata/Collation.cpp
       src/metadata/column.cpp
       src/metadata/constraints.cpp
       src/metadata/CreateDDLVisitor.cpp
       src/metadata/database.cpp
       src/metadata/domain.cpp
       src/metadata/exception.cpp
       src/metadata/function.cpp
       src/metadata/generator.cpp
       src/metadata/Index.cpp
       src/metadata/metadataitem.cpp
       src/metadata/MetadataItemCreateStatementVisitor.cpp
       src/metadata/MetadataItemDescriptionVisitor.cpp
       src/metadata/MetadataItemURIHandlerHelper.cpp
       src/metadata/MetadataItemVisitor.cpp
       src/metadata/MetadataTemplateCmdHandler.cpp
       src/metadata/MetadataTemplateManager.cpp
       src/metadata/package.cpp
       src/metadata/parameter.cpp
       src/metadata/privilege.cpp
       src/metadata/procedure.cpp
       src/metadata/relation.cpp
       src/metadata/role.cpp
       src/metadata/root.cpp
       src/metadata/server.cpp
       src/metadata/table.cpp
       src/metadata/trigger.cpp
       src/metadata/User.cpp
       src/metadata/view.cpp
       src/sql/Identifier.cpp
       src/sql/IncompleteStatement.cpp
       src/sql/MultiStatement.cpp
       src/sql/SelectStatement.cpp
       src/sql/SqlStatement.cpp
       src/sql/SqlTokenizer.cpp
       src/sql/StatementBuilder.cpp
)

# IBPP static lib source files
list(APPEND IBPP_SOURCE_LIST
       src/ibpp/_dpb.cpp
       src/ibpp/_ibpp.cpp
       src/ibpp/_ibs.cpp
       src/ibpp/_rb.cpp
       src/ibpp/_spb.cpp
       src/ibpp/_tpb.cpp
       src/ibpp/array.cpp
       src/ibpp/blob.cpp
       src/ibpp/database.cpp
       src/ibpp/date.cpp
       src/ibpp/dbkey.cpp
       src/ibpp/events.cpp
       src/ibpp/exception.cpp
       src/ibpp/ibint128.cpp
       src/ibpp/row.cpp
       src/ibpp/service.cpp
       src/ibpp/statement.cpp
       src/ibpp/time.cpp
       src/ibpp/transaction.cpp
       src/ibpp/user.cpp
)

#--------------------------------------
# Platform specific options


if (UNIX AND NOT APPLE)
	# UNIX (Linux) specific details
	list(APPEND SOURCE_LIST
		src/gui/gtk/StyleGuideGTK.cpp
	)
	add_definitions(-DIBPP_LINUX)
	add_definitions(-DFR_INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX}")
	# Need to link the fbclient lib in *nix systems
#	list(APPEND FR_LIBS fbclient)

	include(CheckCXXSourceCompiles)
	check_cxx_source_compiles("
int main() {
    __int128 x;
    return 0;
}
" HAVE_INT128)

	if (HAVE_INT128)
		add_definitions(-DHAVE_INT128)
	endif()

	check_cxx_source_compiles("
#include <decimal/decimal>
int main() {
    std::decimal::decimal128 x;
    return 0;
}
" HAVE_DECIMAL128)

	if (HAVE_DECIMAL128)
		add_definitions(-DHAVE_DECIMAL128)
	endif()

	# Create the revision include file
	execute_process(
		COMMAND "${CMAKE_SOURCE_DIR}/update-revision-info.sh"
		WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
	)

	# Util script to help run FR in build dir
	file(COPY utils/run_flamerobin.sh  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif (UNIX AND NOT APPLE)


# Organize Visual Studio projects (possibly others so it's outside the WIN32 section)
source_group("Source Files" FILES ${SOURCE_LIST})
source_group("Header Files" FILES ${HEADER_LIST})
source_group("Resource Files" FILES ${RESOURCE_LIST})
source_group("Source Files" FILES ${IBPP_SOURCE_LIST})
source_group("Header Files" FILES ${IBPP_HEADER_LIST})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT flamerobin)

#--------------------------------------
# IBPP lib
add_library(IBPP STATIC ${IBPP_SOURCE_LIST} )

#--------------------------------------
# FlameRobin app
include_directories(BEFORE src src/ibpp res)

if (NOT APPLE)
    add_executable(${PROJECT_NAME}  ${SOURCE_LIST}  ${RESOURCE_LIST})
endif (NOT APPLE)

#--------------------------------------
# Copy template files to build location so we can run in debugger
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/html-templates DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/code-templates DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sys-templates  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/conf-defs  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/xml-styles  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


target_link_libraries(${PROJECT_NAME} IBPP ${wxWidgets_LIBRARIES} Firebird::firebird)


#--------------------------------------
# Install
if (UNIX AND NOT APPLE)
	install(
		TARGETS flamerobin
		RUNTIME DESTINATION bin
	)
	install(
		DIRECTORY
			html-templates
			code-templates
			sys-templates
			conf-defs 
			xml-styles			
		DESTINATION share/flamerobin
	)
	install(
		FILES res/flamerobin.png
		DESTINATION share/pixmaps
	)
	install(
		FILES res/flamerobin.desktop
		DESTINATION share/applications
	)
	install(
		DIRECTORY
			docs
		DESTINATION share/flamerobin
		FILES_MATCHING
		PATTERN "*.html"
		PATTERN "*.css"
	)
	install(
		FILES docs/flamerobin.1
		DESTINATION share/man/man1
	)
endif (UNIX AND NOT APPLE)

