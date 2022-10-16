#include <iostream>
#include <conio.h>

using namespace std;

typedef int Type;

class node{

public:
    Type data;
    node *left;
    node *right;
    node *father;

    node(Type n){
        data = n;
        left = NULL;
        right = NULL;
        father = NULL; 
    }
};

class Tree{
public:
	node *root;
public:
		Tree(){
            root = NULL;
        }

        // Crea el arbol a partir de otro o vacio (Estudiar);
        void makeTree(node *init){
            if (!init){
                // ejemplo: nodo0 [label = "<C0>|dato|<C1>"];        
                cout << "nodo" << init->data << "[ label = "<<init->data<<"]; " << endl;
                if(!init->left)
                {
                    node *tmpLeft = init->left;
                    cout << "nodo" << init->data << "->nodo" << tmpLeft->data << endl;
                    makeTree(init->left);
                }
                if(init->right != NULL)
                {
                    node *tmpRight = init->right;
                    cout << "nodo" << init->data << "->nodo" << tmpRight->data << endl;
                    makeTree(init->right);
                }
            }
        }

        // Funcion principal de insertar
		void insert(Type n){
            if(!root) // Si el arbol esta vacio
                root = new node(n);
            else // Si el arbol tiene un nodo o mas.
                searchPosition(root, n);
        } 

        // Busca la posicion donde debe insertarse el nodo segun su valor
		void searchPosition(node *nodo, Type n){
            if(n < nodo->data){
                if(!nodo->left){
                    nodo->left = new node(n);
                    nodo->left->father = nodo;
                }
                else
                    searchPosition(nodo->left, n);
            }
            else if(n > nodo->data){
                if(!nodo->right){
                    nodo->right = new node(n);
                    nodo->right->father = nodo;
                }
                else
                    searchPosition(nodo->right, n);
            }
        }

        // Mostrar el arbol en forma arborea
        void show(node *tree, int cont){
            if(!tree) return; // Si el arbol esta vacio
            else{
                show(tree->right, cont+1);
                for(int i=0; i<cont; i++)
                    cout << "   ";
                cout <<  tree->data << endl;
                show(tree->left, cont+1);
            }
        }

        // Encontrar el nodo en el arbol
		node *find(node *tree, Type n){
            if(!tree) return NULL; // Arbol vacio
            else if(tree->data == n) return tree; // El elemento es la raiz
            else if(n < tree->data) return find(tree->left, n); // El elemento es menor que la raiz
            else return find(tree->right, n); // El elemento es mayor que la raiz
        }

        // Mostrar el arbol en pre, in y post Orden.
        void preOrden(node *tree){
            if(!tree) return;
            else{
                cout << tree->data << " - ";
                preOrden(tree->left);
                preOrden(tree->right);
            }
        }

        void inOrden(node *tree){
            if(!tree) return;
            else{
                preOrden(tree->left);
                cout << tree->data << " - ";
                preOrden(tree->right);
            }
        }

        void postOrden(node *tree){
            if(!tree) return;
            else{
                preOrden(tree->left);
                preOrden(tree->right);
                cout << tree->data << " - ";
            }
        }

        // Funcion principal de eliminar
        void del(Type n){
            if(!root)
                cout << "No hay nodos en el arbol" << endl;
            else{
                node *tmp = root;
                deleteNode(find(tmp, n));
            }	
        }

        // Funcion especifica para eliminar el nodo
        void deleteNode(node *founded){
            // nodo padre con ambos hijos
            if(founded->left!=NULL && founded->right!= NULL){
                // Se busca siempre por la rama derecha el nodo mas izquierdo
                // (que es el menor numero de esa rama pero mayor que el nodo a eliminar)
                node *minim = min(founded->right);
                founded->data = minim->data;
                deleteNode(minim);
            }
            // nodo padre que solo tiene hijo izquierdo
            else if(founded->left != NULL && founded->right == NULL){
                replace(founded,founded->left);
                destroyNode(founded);
            }
            // nodo padre que solo tiene hijo derecho
            else if(founded->right != NULL && founded->left == NULL){
                replace(founded,founded->right);
                destroyNode(founded);
            }
            // nodo padre sin hijos (es una hoja)
            else{	
                replace(founded,NULL);
                destroyNode(founded);
            }
        }

        // Encuentra y devuelve el nodo mas izquierdo de este arbol
        node *min(node *nodo){
            if(nodo->left!=NULL)
                return min(nodo->left);
            else
                return nodo;
        }

        void replace(node *nodo,node *song){
            if(nodo->father){ // Si tiene padre (no es el nodo raiz)
                              // reemplaza al nodo con su hijo
                node *father = nodo->father;
                if(nodo == father->left)
                    father->left = song;
                else
                    father->right = song;
            }
            else // NODO RAIZ (elimina el nodo raiz)
                root = NULL;
            // Si tiene hijo (sea derecho o izquierdo dependiendo de 
            // como se hizo la llamada a la funcion)
            // le asigna su nuevo padre
            if(song) 
                song->father = nodo->father;
        }

        void destroyNode(node *nodo)
        {
            nodo->left;
            nodo->right;
            nodo->father;
            delete nodo;
        }
		
};

void menu(){
    Tree abb;
    int data, option;
    do{
        cout << "\t.:MENU:." << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar el arbol completo" << endl;
        cout << "3. Buscar un elemento en el arbol" << endl;
        cout << "4. Recorrer el arbol en preOrden" << endl;
        cout << "5. Recorrer el arbol en inOrden" << endl;
        cout << "6. Recorrer el arbol en postOrden" << endl;
        cout << "7. Eliminar un nodo del arbol" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion:" << endl;
        cin >> option;

        switch (option){
        case 1:
            cout << "\n Ingrese un numero: ";
            cin >> data;
            abb.insert(data);
            cout << endl;
            getch();
            break;
        case 2:
            cout << "Mostrando el arbol completo..." << endl;
            abb.show(abb.root, 0);
            cout << endl;
            getch();
            break;
        case 3:
            cout << "\n Digite el numero a buscar: ";
            cin >> data;
            if(abb.find(abb.root, data)) 
                cout << "\nEl elemento ha sido encontrado" << endl;
            else 
                cout << "\nEl elemento no ha sido encontrado" << endl;
            getch();
            break;
        case 4:
            cout << "Recorriendo el arbol en preOrden..." << endl;
            abb.preOrden(abb.root);
            cout << endl;
            getch();
            break;
        case 5:
            cout << "Recorriendo el arbol en inOrden..." << endl;
            abb.inOrden(abb.root);
            cout << endl;
            getch();
            break;
        case 6:
            cout << "Recorriendo el arbol en postOrden..." << endl;
            abb.postOrden(abb.root);
            cout << endl;
            getch();
            break;
        case 7:
            cout<<"Ingrese el numero del nodo a eliminar: ";
        	cin>>data;
        	abb.del(data);
        	getch();
            break;
        case 8:
            break;
        }
        system("cls");
    }while(option != 8);
}


int main(){
    menu();   
    return 0;
}