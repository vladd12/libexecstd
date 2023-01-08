cmake_minimum_required(VERSION 3.15)

# Define project
project(execstd
    LANGUAGES CXX
    DESCRIPTION "execstd library for executor context"
    VERSION 1.0.0
)
# Language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding path for cmake scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Option for compiling static library
option(EXECSTD_STATIC "Build execstd as static library" OFF)

# Collecting public headers for library
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
message(STATUS "execstd library include path: ${INCLUDE_PATH}")
file(GLOB_RECURSE EXECSTD_HEADERS ${INCLUDE_PATH}/${PROJECT_NAME}/*.hpp)

# Collecting library sources
set(EXECSTD_SOURCES
    src/backend/cpuwin.cpp
    src/core/core.cpp
    src/devices/device.cpp
    src/runtime/accelerator.cpp
    src/runtime/builder.cpp
    src/runtime/context.cpp
)

# Include directory with library's public headers
include_directories(${INCLUDE_PATH})
# Compilation static library
if (EXECSTD_STATIC)
    message(STATUS "execstd is static library")
    add_library(${PROJECT_NAME} STATIC ${EXECSTD_HEADERS} ${EXECSTD_SOURCES})
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DSTATIC_BUILD)
else() # Compilation dynamic library
    message(STATUS "execstd is dynamic library")
    add_library(${PROJECT_NAME} SHARED ${EXECSTD_HEADERS} ${EXECSTD_SOURCES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DLIB_EXPORT)
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DLIB_IMPORT)
endif()
# Library compilation settings
target_compile_definitions(${PROJECT_NAME} PUBLIC -DCMAKE_CONFIG)
target_include_directories(${PROJECT_NAME} INTERFACE ${INCLUDE_PATH})

# Option for CUDA enabling and using CUDA devices
option(CUDA_ENABLE "Enable CUDA" ON)
if(CUDA_ENABLE)
    message(STATUS "CUDA is available for using in project")
    add_subdirectory(src/cuda)
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DCUDA_ENABLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE cuda-internal)
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/cuda")
endif()

# Option for tests enabling
option(TESTS_ENABLE "Enable execstd tests" ON)
if(TESTS_ENABLE)
    # Enabling testing for project
    message(STATUS "Tests compiling is enabled")
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# Installation for library
install(TARGETS
    ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
# Installation for library's headers
install(FILES
    ${EXECSTD_HEADERS}
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"
)
