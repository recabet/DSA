cmake_minimum_required(VERSION 3.28)
project(MyLibs C)

set(CMAKE_C_STANDARD 23)

# Add your library target
add_library(MyLibs STATIC Queue/queue.c
        Stack/stack.c
        "Single Linked List/sll.h"
        "Single Linked List/sll.c"
        "Double Linked List/dll.h"
        "Double Linked List/dll.h"
        "Double Linked List/dll.c"
        "Double Linked List/dll.c"
        "Double Linked List/dll.h"
        "Sorting Algorithms/sort.h"
        "Sorting Algorithms/sort.c"
)

