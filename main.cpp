//
// Created by Daniel on 16/10/2022.
//

#include <iostream>
#include "Linked_List.h"

void List_Menu(){
    Linked_List list;
    int option;
    int dato;
    int pos;

    do{
        std::cout<<"\tMENU\n";
        std::cout<<"1. Insertar elementos a la Lista"<<std::endl;
        std::cout<<"2. Insertar elementos en una posicion especifica"<<std::endl;
        std::cout<<"3. Mostrar todos los elementos de la Lista"<<std::endl;
        std::cout<<"4. Buscar un elemento en la Lista"<<std::endl;
        std::cout<<"5. Eliminar un elemento en la Lista"<<std::endl;
        std::cout<<"6. Eliminar todos elemento en la Lista"<<std::endl;
        std::cout<<"7. Salir"<<std::endl;
        std::cout<<"option: ";
        std::cin>>option;

        switch(option){
            case 1:
                std::cout<<"Digite un numero: ";
                std::cin>>dato;
                list.insert(dato);
                std::cout << std::endl;
                system("pause");
                break;
            case 2:
                std::cout<<"Digite un numero: ";
                std::cin>>dato;
                std::cout << "Diga la posicion " ;
                std::cin >> pos;
                list.insert(dato,pos);
                std::cout << std::endl;
                system("pause");
                break;
            case 3:
                list.show();
                std::cout << std::endl;
                system("pause");
                break;
            case 4:
                std::cout<<"Digite un numero: ";
                std::cin>>dato;
                list.find(dato);
                std::cout << std::endl;
                system("pause");
                break;
            case 5:
                if(list.head->next != nullptr){
                    std::cout << "Digite el elemento que desea eliminar: ";
                    std::cin >> dato;
                    list.deleteNode(dato);
                }else
                    std::cout << "La lista esta vacia. " << std::endl;
                std::cout << std::endl;
                system("pause");
                break;
            case 6:
                list.clear();
                std::cout << std::endl;
                system("pause");
                break;

            case 7:
                break;
        }
        system("cls"); //limpiar pantalla
    }while(option != 7);
}

int main(){

    List_Menu();
    return EXIT_SUCCESS;
}