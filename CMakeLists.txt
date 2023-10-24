cmake_minimum_required(VERSION 3.22)
project(ChanceRytter)
set(CMAKE_CXX_STANDARD 20)



if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()

set(SOURCES main.cpp)
set(TESTSOURCES test/test_main.cpp test/generaltests.h)


add_executable(standard ${SOURCES})
add_executable(tests ${TESTSOURCES})

######### FIND GOOGLE TEST #######
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
target_link_libraries(tests gtest_main)
add_test(NAME example_test COMMAND example)


######### FIND BOOST #############
set(BOOST_REQUESTED_VERSION 1.71.0)

find_package(Boost 1.74.0 COMPONENTS random)
include_directories(${BOOST_INCLUDE_DIRS})

if(Boost_FOUND)
    message("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})   
    target_link_libraries(standard ${Boost_LIBRARIES})
    target_link_libraries(tests ${Boost_LIBRARIES})
endif()

#################################






