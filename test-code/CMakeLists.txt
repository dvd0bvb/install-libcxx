cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project("TestInstallLibcxx" LANGUAGES CXX)

set(EXECUTABLE_NAME DontRunThis)
option(LIBCXX_INCLUDE_PATH "Path to libc++ includes")
option(LIBCXX_LIB_PATH "Path to libc++ libraries")

add_executable(${EXECUTABLE_NAME} main.cpp)

target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_23)
target_compile_options(${EXECUTABLE_NAME} PRIVATE -stdlib=libc++)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE c++abi)
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${LIBCXX_INCLUDE_PATH}/c++/v1)
target_link_directories(${EXECUTABLE_NAME} PRIVATE ${LIBCXX_LIB_PATH})