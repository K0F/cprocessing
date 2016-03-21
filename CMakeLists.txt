cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(cprocessing)

if($ENV{BUILD_NUMBER})
  set(BUILD_NUMBER $ENV{BUILD_NUMBER})
else()
  set(BUILD_NUMBER 0)
endif()

set(CPROCESSING_NAME "cprocessing")
set(CPROCESSING_VERSION "0.3.1.${BUILD_NUMBER}")
set(CPROCESSING_BRIEF "${CPROCESSING_NAME} originally written by Jett LaRue aka whackashoe")

# code coverage options
set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")

set(DEBUG_FLAGS "-g -O0 -Wall")
set(RELEASE_FLAGS "-O3")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_C_FLAGS ${RELEASE_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${GCOV_FLAGS})

# TODO OP check how this works on multiple configurations generators
# available configurations in multiple configurations enabled generators
set(CMAKE_CONFIGURATION_TYPES Debug Release)
#message("CMAKE_CFG_INTDIR = ${CMAKE_CFG_INTDIR}")

include(ExternalProject)

ExternalProject_Add(freeglut
  GIT_REPOSITORY "https://github.com/K0F/freeglut.git"
  GIT_TAG "master"
  PREFIX "externals"
  UPDATE_DISCONNECTED 0
  TIMEOUT 10
  ALWAYS 1
  )

SET(freeglut_INCLUDE_DIR "${CMAKE_INCLUDE_DIR}/externals/src/freeglut/include/GL")
SET(freeglut_BUILD_DIR "${CMAKE_BINARY_DIR}/externals/src/freeglut-build/lib")

# SET(GLUT_ROOT_PATH ${freeglut_INCLUDE_DIR})
MESSAGE(STATUS "ok got freeglut freeglut_INCLUDE_DIR ${freeglut_INCLUDE_DIR}")
MESSAGE(STATUS "ok got freeglut freeglut_BUILD_DIR ${freeglut_BUILD_DIR}")




find_package(OpenGL)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/include/"
  )

if(UNIX)
  include_directories(
    "${OPENGL_INCLUDE_DIR}"
    )
endif()

link_directories(
  ${freeglut_BUILD_DIR}
  )

include_directories(
  ${freeglut_INCLUDE_DIR}
  )

FILE(GLOB SRC_FILES "src/*.cpp")

add_library(cprocessing STATIC ${SRC_FILES})
add_dependencies(cprocessing freeglut)

if(UNIX)
  target_link_libraries(cprocessing
    glfw
    X11
    Xext
    Xmu
    Xxf86vm
    Xi
    Xrandr
    ${OPENGL_LIBRARIES}
    "libglut.a"
    ) 
endif()

if(WIN32)
  target_link_libraries(ccollider
  "glut.lib"
    ${OPENGL_LIBRARIES}
    )
  endif()


# target_link_libraries(cprocessing OpenGL_LIBRARIES)



#add_library(cprocessing SHARED ${SRC_FILES})




# used by doc home and in packaging
set(README_FILE ${PROJECT_SOURCE_DIR}/README.md)

# Licensing and stuff like that
set(LICENSE_FILE ${PROJECT_SOURCE_DIR}/LICENSE.md)


install(FILES LICENCE.md DESTINATION ${CMAKE_BINARY_DIR}/)

# Packaging steps
#set(CPACK_SYSTEM_NAME ${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})
#set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
#set(CPACK_PACKAGE_DESCRIPTION_FILE ${README_FILE})
#set(CPACK_RESOURCE_FILE_LICENSE ${LICENSE_FILE})
#set(CPACK_GENERATOR "ZIP") #;TGZ;STGZ")
#set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
#set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")
#set(CPACK_COMPONENTS_ALL libraries headers)
#set(CPACK_PACKAGE_NAME ${CPROCESSING_NAME})
#set(CPACK_PACKAGE_VENDOR "Acme")
#set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${CPROCESSING_NAME} - ${CPROCESSING_BRIEF}")
#set(CPACK_PACKAGE_VERSION ${CPROCESSING_VERSION})
#set(CPACK_PACKAGE_INSTALL_DIRECTORY "TODO")
# must be executed after CPACK properties definition
#include(CPack)


# TODO sonar requirements
