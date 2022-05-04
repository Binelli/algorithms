add_executable(tests main.cpp)

target_link_libraries(tests PUBLIC square-and-multiply)

target_include_directories(tests PUBLIC "${PROJECT_SOURCE_DIR}/square-and-multiply")