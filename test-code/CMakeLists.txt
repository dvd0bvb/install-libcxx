cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project("TestInstallLibcxx" LANGUAGES CXX)

set(EXECUTABLE_NAME DontRunThis)
option(LIBCXX_INCLUDE_PATH "Path to libc++ includes")
option(LIBCXX_LIB_PATH "Path to libc++ libraries")
option(MSAN_FLAGS "Add MSAN flags")

add_executable(${EXECUTABLE_NAME} main.cpp)

target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_23)
target_compile_options(${EXECUTABLE_NAME} PRIVATE 
  -stdlib=libc++
  -isystem ${LIBCXX_INCLUDE_PATH}/c++/v1)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE c++ c++abi)
target_link_directories(${EXECUTABLE_NAME} PRIVATE ${LIBCXX_LIB_PATH})

if (MSAN_FLAGS) 
  target_compile_options(${EXECUTABLE_NAME} PRIVATE
    -fsanitize=memory
    -fsanitize-memory-track-origins
    -fPIE
    -pie
    -fno-omit-frame-pointer)
  target_link_options(${EXECUTABLE_NAME} PRIVATE
    -fsanitize=memory
    -fsanitize-memory-track-origins
    -fPIE
    -pie
    -fno-omit-frame-pointer)
endif()