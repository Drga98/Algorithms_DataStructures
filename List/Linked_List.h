//
// Created by Daniel on 16/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_LINKED_Linked_List_H
#define ALGORITHMS_DATASTRUCTURES_LINKED_Linked_List_H

#include <iostream>
#include "List_Node.h"

class Linked_List {

public:
    List_Node *head; // Apunta al primer elemento de la Linked_Lista
    int cant;

    Linked_List();

    ~Linked_List()= default;

    // Por defecto inserta al final de la Lista
    void insert(int value, int pos);

    void show() const;

    void find(int value) const;

    void clear();

    void deleteNode(int value);
};


#endif //ALGORITHMS_DATASTRUCTURES_LINKED_Linked_List_H
