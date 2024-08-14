cmake_minimum_required(VERSION 3.10)
project(MyProject)


set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/sll)
include_directories(${PROJECT_SOURCE_DIR}/dll)
include_directories(${PROJECT_SOURCE_DIR}/hash)
include_directories(${PROJECT_SOURCE_DIR}/queue)
include_directories(${PROJECT_SOURCE_DIR}/sort)
include_directories(${PROJECT_SOURCE_DIR}/stack)
include_directories(${PROJECT_SOURCE_DIR}/tree)

add_library(sll ${PROJECT_SOURCE_DIR}/sll/sll.c)
add_library(dll ${PROJECT_SOURCE_DIR}/dll/dll.c)
add_library(hash ${PROJECT_SOURCE_DIR}/hash/hash.c)
add_library(queue ${PROJECT_SOURCE_DIR}/queue/queue.c)
add_library(sort ${PROJECT_SOURCE_DIR}/sort/sort.c)
add_library(stack ${PROJECT_SOURCE_DIR}/stack/stack.c)
add_library(tree ${PROJECT_SOURCE_DIR}/tree/tree.c)

target_link_libraries( sll dll hash queue sort stack tree)
