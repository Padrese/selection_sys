enable_testing()

add_executable(test_student test_student.cpp)
target_link_libraries(test_student student)
target_link_libraries(test_student GTest::Main)

add_executable(test_training test_training.cpp)
target_link_libraries(test_training training)
target_link_libraries(test_training GTest::Main)

add_executable(test_preference test_student.cpp)
target_link_libraries(test_preference student)
target_link_libraries(test_preference GTest::Main)

add_executable(test_selection_system test_selection_system.cpp)
target_link_libraries(test_selection_system selection_system)
target_link_libraries(test_selection_system GTest::Main)

include(GoogleTest)
gtest_discover_tests(test_student)
gtest_discover_tests(test_training)
gtest_discover_tests(test_preference)
gtest_discover_tests(test_selection_system)
