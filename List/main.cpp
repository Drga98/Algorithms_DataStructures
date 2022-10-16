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

class List{

public:
    Node *head; // Apunta al primer elemento de la lista
    int cant;

    List(){
        head = new Node();
        cant = 0;
    }

    ~List(){}

    // Por defecto inserta al final de la lista
    void insert(int value, int pos = INT_MAX){
        Node *nuevo = new Node(value);
        Node *tmp = head;
        for(int i = 0; (i < pos && tmp->next != NULL); i++){
            tmp = tmp->next;
        }
        
        nuevo->next = tmp->next;
        tmp->next = nuevo;
        cant++;
        cout << "Elemento " << value << " insertado correctamente. " << endl;
    }

    void deleteNode(int value){
        Node *aux = head;
        Node *before = NULL;

        while ((aux != NULL) && (aux->data != value)){
            before = aux;
            aux = aux->next;
        }
            
        if(aux == NULL){
            cout << "El elemento no existe"; 
            // Llego hasta el final y no encontro el elemento
        }else if(before == NULL){ // Se elimina el primer elemento porque esto indica que no entro
                                  // al while porque no se cumplio la segunda condicion del while
            head = head->next;
            delete aux;
            cant--;
            cout << "Elemento eliminado correctamente " << endl;
        }else{ // si recorrio la lista pero no es el primer nodo
            before->next = aux->next;
            delete aux;
            cant--;
            cout << "Elemento eliminado correctamente " << endl;
        }
    }

    void show(){
        if(head->next == NULL){
            cout << "La Lista esta vacia. " << endl;
        }else{
            cout << "Cantidad de Nodos: " << cant << endl;
            Node *tmp = head->next;
            while (tmp != NULL){
                cout << tmp->data << " -> " ;
                tmp = tmp->next;
            }
        }
    }

    void find(int value){
        bool flag = false;
        int pos = 0;
        Node *tmp = head->next;

        while(tmp != NULL){
            if(tmp->data == value){
                flag = true;
                break;
            }
            tmp = tmp->next;
            pos++;
        }

        if (!flag) {
            cout << "Elemento " << value << " no ha sido encontrado en la Lista " << endl;
            cout << "Su posicion es la #: " << pos << endl;
        } else {
            cout << "Elemento " << value << " ha sido encontrado en la Lista " << endl;
            cout << "Su posicion es la #: " << pos << endl;
        }
    }

    void clear(){
        if(head == NULL){
            cout << "La lista esta vacia" << endl;
        }else{
            cout << "Vaciando lista ..." << endl;
            Node *aux = head;
            Node *borrar;
            while (aux->next != NULL){
                borrar = aux;
                cout << " entre " << aux->data  << "next " << aux->next << endl;
                aux = aux->next;
                delete borrar; 
            }
            head = new Node();
            system("pause");
        }
    } 

};

void menu(){
	List list;
	int opcion;
	int dato;
    int pos;
	
	do{
		cout<<"\tMENU\n";
		cout<<"1. Insertar elementos a la lista"<<endl;
        cout<<"2. Insertar elementos en una posicion especifica"<<endl;
        cout<<"3. Mostrar todos los elementos de la Lista"<<endl;
		cout<<"4. Buscar un elemento en la Lista"<<endl;
        cout<<"5. Eliminar un elemento en la Lista"<<endl;
        cout<<"6. Eliminar todos elemento en la Lista"<<endl;
        cout<<"7. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: 
                    cout<<"Digite un numero: ";
					cin>>dato;
					list.insert(dato);
                    cout << endl;
                    system("pause");
					break;
            case 2: 
                    cout<<"Digite un numero: ";
					cin>>dato;
                    cout << "Diga la posicion " ;
                    cin >> pos;
					list.insert(dato,pos);
                    cout << endl;
                    system("pause");
					break;
            case 3: 
					list.show();
                    cout << endl;
                    system("pause");
					break;
            case 4: 
                    cout<<"Digite un numero: ";
					cin>>dato;
					list.find(dato);
                    cout << endl;
                    system("pause");
					break;
            case 5: 
                    if(list.head->next != NULL){
                        cout << "Digite el elemento que desea eliminar: ";
                        cin >> dato;
                        list.deleteNode(dato);
                    }else
                        cout << "La lista esta vacia. " << endl;
                    cout << endl;
                    system("pause");
                    break;
            case 6: 
                    list.clear();
                    cout << endl;
                    system("pause");
                    break;
            
            case 7: 
                    break;
		}
		system("cls"); //limpiar pantalla
	}while(opcion != 7);	
}

int main(){
    
    menu();
    return 0;
}