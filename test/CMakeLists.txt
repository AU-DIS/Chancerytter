

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

set(TESTSOURCES test_main.cpp)

add_executable(unit_tests test_main.cpp)

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
target_link_libraries(unit_tests gtest_main standard)
#add_test(NAME example_test COMMAND example)


######### FIND BOOST #############
set(BOOST_REQUESTED_VERSION 1.74.0)

find_package(Boost 1.74.0 COMPONENTS random)
include_directories(${BOOST_INCLUDE_DIRS})

if(Boost_FOUND)
    message("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})   
    target_link_libraries(unit_tests  ${Boost_LIBRARIES})
endif()


######## automatic discovery of unit tests #########
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )

