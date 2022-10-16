#include <iostream>

using namespace std;

class Node{

public:
    int data;
   	Node *next;

	Node(){
		next = NULL;
	}
	
	Node (int n){
	    data = n;
		next = NULL;
   	}
};

class Stack{

public:
    Node *stack; // Apunta al primer elemento de la Stacka
    int cant;

    Stack(){
        stack = NULL;
        cant = 0;
    }

    ~Stack(){}

    void addstack(int n){
        Node *nuevo = new Node(n);
        nuevo->next = stack;
        stack = nuevo;
        cant++;
        cout << "\nELemento " << n << " agregado a la Pila correctamente" << endl; 
    }

    void getstack(int &n){
        Node *tmp = stack;
        n = tmp->data;
        stack = tmp->next;
        delete tmp;
        cant--;
    }

    void show(){
        if(stack == NULL){
            cout << "La Pila esta vacia. " << endl;
        }else{
            cout << "Cantidad de Nodes: " << cant << endl;
            Node *tmp = stack;
            while (tmp != NULL){
                cout << tmp->data << " -> " ;
                tmp = tmp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

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
					s.addstack(data);
                    cout << endl;
                    system("pause");
					break;
            case 2: 
					s.show();
                    cout << endl;
                    system("pause");
					break;
            case 3: 
                    if(s.stack != NULL){
                        s.getstack(data);
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