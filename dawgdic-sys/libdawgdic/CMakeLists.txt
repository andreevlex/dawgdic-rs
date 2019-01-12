cmake_minimum_required(VERSION 2.6)
project(LIBDAWGDIC)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
   set (CMAKE_BUILD_TYPE Release)
endif (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

include (${LIBDAWGDIC_SOURCE_DIR}/cmake/CXXFlags.cmake)

include_directories (${LIBDAWGDIC_SOURCE_DIR}/include)
include_directories (${LIBDAWGDIC_BINARY_DIR}/include)
include_directories (${LIBDAWGDIC_SOURCE_DIR}/lib)
include_directories (${LIBDAWGDIC_BINARY_DIR}/lib)

add_library(dawgdic
  src/dawg.cpp
  src/dawg-builder.cpp
  src/dawg-dictionary.cpp
  src/dawg-dictionary-builder.cpp
)

install(TARGETS dawgdic
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
  DESTINATION include/dawgdic)
