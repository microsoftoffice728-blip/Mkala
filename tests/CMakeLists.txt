add_executable(tests test_library.cpp)
find_package(Catch2 REQUIRED)
# If Catch2 is installed via package manager, link it. Otherwise, user must install.
# Uncomment and adjust if using FetchContent to bring Catch2.
# target_link_libraries(tests PRIVATE Catch2::Catch2)

# For now, compile tests without linking; user should adjust as needed.

target_compile_features(tests PRIVATE cxx_std_17)
target_link_libraries(tests PRIVATE ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME LibraryTests COMMAND tests)
