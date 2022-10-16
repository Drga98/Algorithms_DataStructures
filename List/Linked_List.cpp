//
// Created by Daniel on 16/10/2022.
//

#include "Linked_List.h"

Linked_List::Linked_List(){
    head = new List_Node();
    cant = 0;
}

void Linked_List::insert(int value, int pos = INT_MAX){
    auto *nuevo = new List_Node(value);
    List_Node *tmp = head;
    for(int i = 0; (i < pos && tmp->next != nullptr); i++){
        tmp = tmp->next;
    }

    nuevo->next = tmp->next;
    tmp->next = nuevo;
    cant++;
    std::cout << "Elemento " << value << " insertado correctamente. " << std::endl;
}

void Linked_List::deleteNode(int value){
    List_Node *aux = head;
    List_Node *before = nullptr;

    while ((aux != nullptr) && (aux->data != value)){
        before = aux;
        aux = aux->next;
    }

    if(aux == nullptr){
        std::cout << "El elemento no existe";
        // Llego hasta el final y no encontro el elemento
    }else if(before == nullptr){ // Se elimina el primer elemento porque esto indica que no entro
        // al while porque no se cumplio la segunda condicion del while
        head = head->next;
        delete aux;
        cant--;
        std::cout << "Elemento eliminado correctamente " << std::endl;
    }else{ // si recorrio la Linked_Lista pero no es el primer nodo
        before->next = aux->next;
        delete aux;
        cant--;
        std::cout << "Elemento eliminado correctamente " << std::endl;
    }
}

void Linked_List::show() const{
    if(head->next == nullptr){
        std::cout << "La Linked_Lista esta vacia. " << std::endl;
    }else{
        std::cout << "Cantidad de Nodos: " << cant << std::endl;
        List_Node *tmp = head->next;
        while (tmp != nullptr){
            std::cout << tmp->data << " -> " ;
            tmp = tmp->next;
        }
    }
}

void Linked_List::find(int value) const{
    bool flag = false;
    int pos = 0;
    List_Node *tmp = head->next;

    while(tmp != nullptr){
        if(tmp->data == value){
            flag = true;
            break;
        }
        tmp = tmp->next;
        pos++;
    }

    if (!flag) {
        std::cout << "Elemento " << value << " no ha sido encontrado en la Linked_Lista " << std::endl;
        std::cout << "Su posicion es la #: " << pos << std::endl;
    } else {
        std::cout << "Elemento " << value << " ha sido encontrado en la Linked_Lista " << std::endl;
        std::cout << "Su posicion es la #: " << pos << std::endl;
    }
}

void Linked_List::clear(){
    if(head == nullptr){
        std::cout << "La Linked_Lista esta vacia" << std::endl;
    }else{
        std::cout << "Vaciando Linked_Lista ..." << std::endl;
        List_Node *aux = head;
        List_Node *borrar;
        while (aux->next != nullptr){
            borrar = aux;
            std::cout << " entre " << aux->data  << "next " << aux->next << std::endl;
            aux = aux->next;
            delete borrar;
        }
        head = new List_Node();
        system("pause");
    }
}