#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 0) // caso base
        n = 1;
    else{ // caso general
        n = n * factorial(n - 1);
    }
    return n;
}

// Suma todos los numeros hasta el limite establecido
int sumar(int n){
    int suma = 0;

    if(n == 1) // caso base
        n = 1;
    else{ // caso general
        n = n + sumar(n - 1);
    }
    return n;
}

int potencia(int x, int y){
    if(y == 0) // caso base
        x = 1;
    else{ // caso general
        x = x * potencia(x, y-1);
    }
    return x;
}

int fib(int n){
    if(n<2)
        return n;
    // caso general
    return  fib(n-1) + fib(n-2);
}

/*
n=5:             fib(4)[3]                  +                     [2]fib(3)   =   5
                  [3]                                                  [2]
  [2]fib(3)        +         [1]fib(2)                    [1]fib(2)     +      fib(1)[1]
     [2]                       [1]                           [1]
[1]fib(2)+fib(1)[1]     [1]fib(1)+fib(0)[0]          [1]fib(1)+fib(0)[0]        
*/

int main(){

    // Factorial
    cout << "Factorial: " << factorial(5) << endl;

    // Suma
    int Elements = 7;
    cout << "Suma: " << sumar(Elements) << endl;

    // Potencia
    cout << "Potencia: " << potencia(2, 10) << endl;

    // Mostrar secuencia Fibonacci hasta un numero
    int lim = 6;
    cout << "Fib: ";
    for(int i=0; i<lim; i++)
        cout << fib(i) << " ";
    cout << endl;

}