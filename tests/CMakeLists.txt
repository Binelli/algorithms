include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
    test
    test.cpp
)

target_include_directories(
    test 
    PUBLIC 
    "${PROJECT_SOURCE_DIR}/square-and-multiply"
    "${PROJECT_SOURCE_DIR}/list"
)

target_link_libraries(
    test 
    gtest_main
    square-and-multiply
    lists
)

include(GoogleTest)
gtest_discover_tests(test)
