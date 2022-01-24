project(motionlink)
cmake_minimum_required (VERSION 3.5)

include_directories(./include)
link_directories(${CMAKE_SOURCE_DIR}/build/lib)

add_definitions( -DPOCO_STATIC )

option(ENABLE_SEVENZIP OFF)
option(ENABLE_XML OFF) 
option(ENABLE_JWT ON) 
option(ENABLE_CRYPTO ON)
option(ENABLE_DATA OFF)
option(ENABLE_DATA_SQLITE OFF) 
option(ENABLE_DATA_MYSQL OFF) 
option(ENABLE_DATA_POSTGRESQL OFF) 
option(ENABLE_DATA_ODBC OFF)
option(ENABLE_MONGODB OFF)
option(ENABLE_REDIS OFF)
option(ENABLE_PDF OFF)
option(ENABLE_ZIP ON) 
option(ENABLE_APACHECONNECTOR OFF)
option(ENABLE_CPPPARSER OFF)
option(ENABLE_ENCODINGS OFF)
option(ENABLE_ENCODINGS_COMPILER OFF)
option(ENABLE_PAGECOMPILER OFF)
option(ENABLE_PAGECOMPILER_FILE2PAGE OFF) 
option(ENABLE_POCODOC OFF)
option(ENABLE_TESTS OFF)
option(ENABLE_LONG_RUNNING_TESTS OFF)
option(POCO_UNBUNDLED OFF)
option(BUILD_SHARED_LIBS OFF)

add_subdirectory(poco)
set(CMAKE_INSTALL_PREFIX "../install")

set(SRC_FILE    src/motionLink.cpp
                src/main.cpp
            )
add_executable(${PROJECT_NAME} ${SRC_FILE})

target_link_libraries(${PROJECT_NAME} Poco::Foundation)
target_link_libraries(${PROJECT_NAME} Poco::Net)
target_link_libraries(${PROJECT_NAME} Poco::Util)
target_link_libraries(${PROJECT_NAME} Poco::JSON)


# INSTALL 
install(
    TARGETS ${PROJECT_NAME} 
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

if(UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif(UNIX)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)