cmake_minimum_required(VERSION 3.16)
project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-12")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)

function(getstdmodule name)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      # using GCC
      execute_process(COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header ${name})
    elseif (NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      # not using GCC
      message(STATUS "Unable to compile standard modules... not using GCC.")
    endif()
endfunction()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  add_compile_options(-std=c++2a -fmodules-ts)

  getstdmodule(iostream)
  getstdmodule(string)

  add_library(m_helloworld_impl OBJECT src/m_helloworld_impl.cc)
  add_library(m_helloworld STATIC $<TARGET_OBJECTS:m_helloworld_impl> src/m_helloworld.cc)

  add_executable(${PROJECT_NAME} src/main.cpp)
  target_link_libraries(${PROJECT_NAME} m_helloworld)

elseif (NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # not using GCC
  message(STATUS "not using GCC")
endif()