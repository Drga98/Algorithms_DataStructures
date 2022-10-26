//
// Created by Daniel on 21/10/2022.
//
#include <iostream>
#include "Stack.h"

using namespace std;

void menu(){
    Stack s;
    int option;
    int data;

    do{
        cout<<"\tMENU\n";
        cout<<"1. Insertar elemento en la Pila"<<endl;
        cout<<"2. Mostrar todos los elementos de la Pila"<<endl;
        cout<<"3. Extraer elemento en la Pila"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch(option){
            case 1:
                cout<<"Digite un numero: ";
                cin>>data;
                s.addStack(data);
                cout << endl;
                system("pause");
                break;
            case 2:
                s.showStack();
                cout << endl;
                system("pause");
                break;
            case 3:
                if(s.stack != nullptr){
                    s.getStack(data);
                    cout << "Elemento " << data << " extraido correctamente " << endl;
                }else
                    cout << "La Pila esta vacia. " << endl;
                cout << endl;
                system("pause");
                break;
            case 4:
                break;
        }
        system("cls"); //limpiar pantalla
    }while(option != 4);
}

int main(){

    menu();
    return 0;
}