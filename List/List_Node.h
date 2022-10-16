//
// Created by Daniel on 16/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_LIST_List_Node_H
#define ALGORITHMS_DATASTRUCTURES_LIST_List_Node_H


#include <cstddef>

class List_Node {

public:
    int data;
    List_Node *next;

    List_Node()= default;

    explicit List_Node (int n);

};

#endif //ALGORITHMS_DATASTRUCTURES_LIST_List_Node_H
