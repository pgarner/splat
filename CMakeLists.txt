#
# Copyright 2018 by Philip N. Garner
#
# See the file COPYING for the licence associated with this software.
#
# Author(s):
#   Phil Garner, October 2018
#

cmake_minimum_required(VERSION 3.0)

project(splat)
set(VERSION 0.1)

set(CMAKE_CXX_FLAGS "-Wall -Werror -std=c++14")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (NOT EXISTS "${CMAKE_MODULE_PATH}/FindLibUBE.cmake")
  message(STATUS "Downloading FindLibUBE.cmake")
  file(DOWNLOAD
    "https://github.com/pgarner/libube/raw/master/cmake/FindLibUBE.cmake"
    "${CMAKE_MODULE_PATH}/FindLibUBE.cmake"
    )
endif()

if (NOT LIBUBE_FOUND)
  find_package(LibUBE REQUIRED)
endif (NOT LIBUBE_FOUND)
include_directories(${LIBUBE_INCLUDE_DIRS})
set(TARGET_LIBS ${LIBUBE_LIBRARIES})

#add_subdirectory(ssp)

add_executable(splat splat.cpp)
target_link_libraries(splat ${TARGET_LIBS})

set(INSTALL_TARGETS
  splat
  )

install(
  TARGETS ${INSTALL_TARGETS}
  RUNTIME DESTINATION bin
  )

#enable_testing()
#add_subdirectory(test)
