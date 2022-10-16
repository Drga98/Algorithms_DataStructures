#include <iostream>
#include <conio.h>

using namespace std;

void mostrar(int array[], int tam) {
    int i = 0;
    for (; tam - 1 > i; i++) {
        cout << array[i] << "->";
    }
    cout << array[tam - 1];
    cout << endl;
}

void insercion(int array[], int tam) {
    int nuevo, pos;
    // Desde el segundo elemento hasta el ultimo
    for (int i = 1; i < tam; i++) {
        nuevo = array[i];
        pos = 0;
        while ((pos < i) && (array[pos] < nuevo)) {
            pos++;
        }
        // pos: indice del primer mayor;(es i si no lo hay)
        for (int j = i; j > pos; j--) {
            array[j] = array[j - 1];
        }
        array[pos] = nuevo;
    }
    mostrar(array, tam);
}

void insercion_intercambio(int array[], int tam) {
    int tmp, pos;
    // Desde el segundo elemento hasta el ultimo
    for (int i = 1; i < tam; i++) {
        pos = i;
        while ((pos > 0) && (array[pos - 1] > array[pos])) {
            tmp = array[pos];
            array[pos] = array[pos - 1];
            array[pos - 1] = tmp;
            pos--; // Posicion anterior
        }
    }
    mostrar(array, tam);
}

void seleccion_directa(int array[], int tam) {
    // Desde el primer elemento hasta el penultimo
    for (int i = 0; i < tam - 1; i++) {
        int menor = i;
        // Desde i+1 hasta el final
        for (int j = i + 1; j < tam; j++) {
            if (array[j] < array[menor])
                menor = j;
        }
        if (menor > i) {
            int tmp = array[i];
            array[i] = array[menor];
            array[menor] = tmp;

        }
    }
    mostrar(array, tam);
}

void burbuja(int array[], int tam) {
    int tmp;
    // Desde el primer elemento hasta el penultimo
    for (int i = 0; i < tam - 1; i++) {
        // Desde el ultimo hasta el siguiente a i
        for (int j = tam - 1; j > i; j--) {
            if (array[j] < array[j - 1]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
   
    mostrar(array, tam);
}

int divideSortPivot(int arr[], int left, int right){
    int pivotUnsorted = ((right-left)/2)+left;
    int pivot = arr[pivotUnsorted];//pivot from middle of array; right - left gives us the range, divide than range in half, then add that to the start position(left)
    int i=-1;
    for (int j=left;j<=right;++j){//loop finds true index of pivot to use for comparison in next loop(left/right comparison swaps) - affects time complexity as entire data structure must be iterated through
        if(arr[j]<=pivot){
            ++i;
        }
    }
    int pivotIndex = i+left;//amount of elements less than/equal to pivot, plus index of where we began searching
    i=left-1;
    for(int j=left;j<=right;++j){
        if(arr[j]<=pivot){
            ++i;
            if(j==pivotUnsorted)
                pivotUnsorted=i;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[pivotIndex],arr[pivotUnsorted]);
    return (pivotIndex);
}

void quicksort(int arr[], int left, int right){
    if(left >= right)//base case: if leftmost index of "sub" array we are recursively sorting is greater than rightmost, then return.
        return;

    int pivot = divideSortPivot(arr, left, right);

    quicksort(arr, left, pivot-1);
    quicksort(arr, pivot+1, right);
}

void quicksort(int arr[],int arrLength){
    quicksort(arr, 0, arrLength-1);
}

void menu() {
    int list[20];
    int tam = sizeof(list)/sizeof(list[0]);
    for (int i = 0; i < tam; i++) { list[i] = 1 + rand() % 100; }

    int opcion;


    do {
        cout << "\tMENU\n";
        cout << "1. Sorting por insercion" << endl;
        cout << "2. Sorting por insercion con intercambios" << endl;
        cout << "3. Sorting por seleccion directa" << endl;
        cout << "4. Sorting por el metodo de la burbuja" << endl;
        cout << "5. Sorting por el metodo quicksort" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Lista sin ordenar: ";
                mostrar(list, tam);
                cout << "\nLista ordenada por insercion: ";
                insercion(list, tam);
                cout << endl;
                getch();
                break;
            case 2:
                cout << "Lista sin ordenar: ";
                mostrar(list, tam);
                cout << "\nLista ordenada por insercion con intercambios: ";
                insercion_intercambio(list, tam);
                cout << endl;
                getch();
                break;
            case 3:
                cout << "Lista sin ordenar: ";
                mostrar(list, tam);
                cout << "\nLista ordenada por seleccion directa: ";
                seleccion_directa(list, tam);
                cout << endl;
                getch();
                break;
            case 4:
                cout << "Lista sin ordenar: ";
                mostrar(list, tam);
                cout << "\nLista ordenada por burbuja: ";
                burbuja(list, tam);
                cout << endl;
                getch();
                break;
            case 5:
                cout << "Lista sin ordenar: ";
                mostrar(list, tam);
                cout << "\nLista ordenada por quicksort: ";
                quicksort(list, 0, tam-1);
                mostrar(list, tam);
                cout << endl;
                getch();
                break;
            case 6:
                break;
        }
        getch(); //limpiar pantalla
    } while (opcion != 6);
}

int main() {

    menu();
    return 0;
}