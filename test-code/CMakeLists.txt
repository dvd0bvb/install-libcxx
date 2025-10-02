cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project("TestInstallLibcxx" LANGUAGES CXX)

set(EXECUTABLE_NAME DontRunThis)
option(LIBCXX_INSTALL_PREFIX "Path to libc++ top level directory")

add_executable(${EXECUTABLE_NAME} main.cpp)

target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_23)
target_compile_options(${EXECUTABLE_NAME} PRIVATE -stdlib=libc++)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE c++abi)
# target_link_directories(${EXECUTABLE_NAME} PRIVATE ${LIBCXX_INSTALL_PREFIX}/lib)