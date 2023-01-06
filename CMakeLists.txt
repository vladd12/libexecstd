cmake_minimum_required(VERSION 3.15)

# Define project
project(execstd
    LANGUAGES CXX
    DESCRIPTION "execstd library for executor context"
    VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(EXECSTD_STATIC:BOOL "Build execstd as static library" OFF)

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})
message(STATUS "Library include path: ${INCLUDE_PATH}")
file(GLOB_RECURSE public_headers ${PROJECT_SOURCE_DIR}/include/*.h*)

#option(ENABLE_CUDA "Enable CUDA" ON)
#if(ENABLE_CUDA)
#    add_subdirectory(src/cuda)
#endif()

set(EXECSTD_SOURCES
    src/core/builder.cpp
    src/core/context.cpp
    src/backend/cpuwin.cpp
    src/devices/device.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)
if (EXECSTD_STATIC)
    message(STATUS "execstd is static library")
    add_library(${PROJECT_NAME} STATIC ${public_headers} ${EXECSTD_SOURCES})
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DSTATIC_BUILD)
else()
    message(STATUS "execstd is shared library")
    add_library(${PROJECT_NAME} SHARED ${public_headers} ${EXECSTD_SOURCES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DLIB_EXPORT)
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DLIB_IMPORT)
endif()

target_compile_definitions(${PROJECT_NAME} PUBLIC -DCMAKE_CONFIG)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)


