//
// Created by Daniel on 16/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_LIST_List_Node_H
#define ALGORITHMS_DATASTRUCTURES_LIST_List_Node_H


#include <cstddef>

class Stack_Node {

public:
    int data;
    Stack_Node *next;

    Stack_Node()= default;

    explicit Stack_Node (int n);

};

#endif //ALGORITHMS_DATASTRUCTURES_LIST_List_Node_H
