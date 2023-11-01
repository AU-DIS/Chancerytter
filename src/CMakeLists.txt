cmake_minimum_required(VERSION 3.22)
project(ChanceRytter)
set(CMAKE_CXX_STANDARD 20)



if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()

set(SOURCES experiments/experiment_runner.cpp interfaces/experiment.h)

add_library(standard)
##target_include_directories()
target_sources(standard PUBLIC ${SOURCES})
target_include_directories(standard PUBLIC ${CMAKE_CURRENT_LIST_DIR})
add_executable(build main.cpp)




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





