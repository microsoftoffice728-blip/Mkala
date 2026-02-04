cmake_minimum_required(VERSION 3.10)
project(OnlineLibrary)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
    src/book.cpp
    src/user.cpp
    src/library.cpp
    src/main.cpp
)

add_executable(online_library ${SOURCE_FILES})

enable_testing()
add_subdirectory(tests)
