if(EXISTS "/home/alan/Documents/Cours/3A/C++/selection_sys/build/test/test_sys_actor[1]_tests.cmake")
  include("/home/alan/Documents/Cours/3A/C++/selection_sys/build/test/test_sys_actor[1]_tests.cmake")
else()
  add_test(test_sys_actor_NOT_BUILT test_sys_actor_NOT_BUILT)
endif()
