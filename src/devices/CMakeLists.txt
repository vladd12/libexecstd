project(devices LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEVICES_INCLUDE_PATH ${INCLUDE_PATH}/${PROJECT_NAME})
message(STATUS "Devices static library include path: ${DEVICES_INCLUDE_PATH}")

file(GLOB_RECURSE cpp_sources ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE private_headers ${PROJECT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE public_headers ${DEVICES_INCLUDE_PATH}/*.hpp)

include_directories(${INCLUDE_PATH})
add_library(${PROJECT_NAME} STATIC
  ${public_headers} ${private_headers} ${cpp_sources}
)
