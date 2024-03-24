enable_testing()

add_executable(test_student test_student.cpp)
target_link_libraries(test_student student)
target_link_libraries(test_student GTest::Main)

include(GoogleTest)
gtest_discover_tests(test_student)

