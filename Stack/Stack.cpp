#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {
        cant = 0;
        stack = nullptr;
}

void Stack::addStack(int n){
    auto *nuevo = new Stack_Node(n);
    nuevo->next = stack;
    stack = nuevo;
    cant++;
    cout << "\nELemento " << n << " agregado a la Pila correctamente" << endl;
}

void Stack::getStack(int &n){
    Stack_Node *tmp = stack;
    n = tmp->data;
    stack = tmp->next;
    delete tmp;
    cant--;
}

void Stack::showStack() const{
    if(stack == nullptr){
        cout << "La Pila esta vacia. " << endl;
    }else{
        cout << "Cantidad de Nodes: " << cant << endl;
        Stack_Node *tmp = stack;
        while (tmp != nullptr){
            cout << tmp->data << " -> " ;
            tmp = tmp->next;
        }
        cout << "nullptr" << endl;
    }
}