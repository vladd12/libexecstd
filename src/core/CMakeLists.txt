project(core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CORE_INCLUDE_PATH ${INCLUDE_PATH}/${PROJECT_NAME})
message(STATUS "Core static library include path: ${CORE_INCLUDE_PATH}")

file(GLOB_RECURSE cpp_sources ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE private_headers ${PROJECT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE public_headers ${CORE_INCLUDE_PATH}/*.h)

include_directories(${CORE_INCLUDE_PATH})
add_library(${PROJECT_NAME} STATIC
  ${public_headers} ${private_headers} ${cpp_sources}
)
