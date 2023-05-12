cmake_minimum_required(VERSION 3.25)

project(my_c VERSION 0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(deps/mbedtls)

# create library `at_chops`
file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/*.c)
add_library(at_chops ${sources})
target_include_directories(at_chops PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(at_chops PUBLIC mbedtls)
target_link_libraries(at_chops PUBLIC mbedcrypto)
target_link_libraries(at_chops PUBLIC mbedx509)


file(GLOB_RECURSE tests ${CMAKE_SOURCE_DIR}/test/*.c)
add_executable(tests ${tests})
target_link_libraries(tests PRIVATE at_chops)
