cmake_minimum_required(VERSION 3.22)
project(Algorithms_DataStructures)

set(CMAKE_CXX_STANDARD 20)


add_executable(Graph Graph/graph.cpp)
target_include_directories(Graph PUBLIC Graph/)

add_library(List STATIC
        List/Linked_List.cpp List/Linked_List.h
        List/List_Node.cpp List/List_Node.h)
target_include_directories(List PUBLIC List/)

add_executable(Recursion
        Recursion/recursion.cpp)
target_include_directories(Recursion PUBLIC Recursion/)

add_executable(Searches
        Searches/searches.cpp)
target_include_directories(Searches PUBLIC Searches/)

add_executable(Sorting
        Sorting/sorting.cpp)
target_include_directories(Sorting PUBLIC Sorting/)

add_executable(Stack
        Stack/stack.cpp)
target_include_directories(Stack PUBLIC Stack/)

add_executable(Trees
        Trees/trees.cpp)
target_include_directories(Trees PUBLIC Trees/)

add_executable(DataStructures main.cpp)
target_link_libraries(DataStructures PRIVATE List)