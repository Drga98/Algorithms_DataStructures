cmake_minimum_required(VERSION 3.22)
project(Algorithms_DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(List
        List/mainList.cpp
        List/Linked_List.cpp
        List/List_Node.cpp)
target_include_directories(List PUBLIC List/)

add_executable(Graph
        Graph/graph.cpp)
target_include_directories(Graph PUBLIC Graph/)

# Example for adding libraries and running mainFunction In DataStructures.
#add_library(List STATIC
#        List/Linked_List.cpp List/Linked_List.h
#        List/List_Node.cpp List/List_Node.h)
#target_include_directories(List PUBLIC List/)

#add_executable(DataStructures main.cpp) THIS LAST TWO AT THE END
#target_link_libraries(DataStructures PRIVATE List)

add_executable(Recursion
        Recursion/mainRecur.cpp
        )
target_include_directories(Recursion PUBLIC Recursion/)

add_executable(Stack
        Stack/mainStack.cpp
        Stack/Stack.cpp
        Stack/Stack_Node.cpp)
target_include_directories(Stack PUBLIC Stack/)

add_executable(Searches
        Searches/searches.cpp)
target_include_directories(Searches PUBLIC Searches/)

add_executable(Sorting
        Sorting/sorting.cpp)
target_include_directories(Sorting PUBLIC Sorting/)

add_executable(Trees
        Trees/trees.cpp)
target_include_directories(Trees PUBLIC Trees/)
