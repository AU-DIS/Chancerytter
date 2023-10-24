cmake_minimum_required(VERSION 3.22)
project(ChanceRytter)
set(CMAKE_CXX_STANDARD 20)



if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()

set(SOURCES main.cpp)

add_library(standard ${SOURCES})
add_executable(build ${SOURCES})




######### FIND BOOST #############
set(BOOST_REQUESTED_VERSION 1.74.0)

find_package(Boost 1.74.0 COMPONENTS random)
include_directories(${BOOST_INCLUDE_DIRS})

if(Boost_FOUND)
    message("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})   
    target_link_libraries(standard ${Boost_LIBRARIES})
endif()

############# CODE COVERAGE ###############
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(standard
    PUBLIC
      "--coverage"
    )
  target_link_options(standard
    INTERFACE
      "--coverage"
    )
endif()





