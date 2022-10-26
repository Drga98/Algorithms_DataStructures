//
// Created by Daniel on 20/10/2022.
//
#include <iostream>

using namespace std;

// Get the factorial of the number.
int factorial(int n)
{
    n = n == 0 ? 1 : n * factorial(n - 1);
    return n;
}

// add up all the numbers from 0 to the "n" number.
int sum(int n)
{
    n = n==1 ? 1 : n + sum(n - 1);
    return n;
}

// calculates the power of x raised to the y.
int power(int x, int y)
{
    x = y == 0 ? 1 : x * power(x, y - 1);
    return x;
}

// Return the value of the number in position "n" of the fibonacci sequence.
int fib(int n)
{
    return n < 2 ? n : fib(n - 1) + fib(n - 2);
}

/*
 * Explanation of hof Fib(5) works in debug mode.
n=5:             fib(4)[3]                  +                     [2]fib(3)   =   5
                  [3]                                                  [2]
  [2]fib(3)        +         [1]fib(2)                    [1]fib(2)     +      fib(1)[1]
     [2]                       [1]                           [1]
[1]fib(2)+fib(1)[1]     [1]fib(1)+fib(0)[0]          [1]fib(1)+fib(0)[0]
*/

int main(){
    // Factorial
    cout << "Factorial of 5: " << factorial(5) << endl;

    // Sum
    int Elements = 7;
    cout << "Sum until 7: " << sum(Elements) << endl;

    // Power
    cout << "Power of 2^10: " << power(2, 10) << endl;

    // Displays the fibonacci sequence until a limit.
    int limit = 6;
    cout << "Fib until position 6: ";
    for(int i=0; i<=limit; i++)
        cout << fib(i) << " ";
    cout << endl;

}