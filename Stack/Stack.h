//
// Created by Daniel on 20/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_STACK_H
#define ALGORITHMS_DATASTRUCTURES_STACK_H

#include "Stack_Node.h"

class Stack{

public:
    Stack_Node *stack; // Point Stack first element.
    int cant;

    Stack();
    ~Stack() = default;

    void addStack(int n);

    void getStack(int &n);

    void showStack();

};


#endif //ALGORITHMS_DATASTRUCTURES_STACK_H
