cmake_minimum_required (VERSION 3.16)

project(MemoryStack)

add_executable(MemoryStack "MemoryStack.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MemoryStack PROPERTY CXX_STANDARD 20)
endif()

