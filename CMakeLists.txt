cmake_minimum_required(VERSION 3.0.0)
project(hashtable VERSION 0.1.0)

set(CMAKE_C_STANDARD         11)
set(CMAKE_C_STANDAR_REQUIRED ON)
set(CMAKE_C_EXTENSIONS       OFF)

# library
set(HASH_TABLE_LIBRARY hashtable)

include(CTest)
enable_testing()

add_library(${HASH_TABLE_LIBRARY} STATIC hashtable.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
target_include_directories(${HASH_TABLE_LIBRARY} PUBLIC
    "./")


include(CPack)
include(FetchContent)

FetchContent_Declare(
    vector
    GIT_REPOSITORY https://github.com/Seungwuk98/c-vector
    GIT_TAG v0.1.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(vector)

add_subdirectory(test)

target_link_libraries(${HASH_TABLE_LIBRARY} PUBLIC
    vector
    )
