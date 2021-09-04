// Fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
#include <iostream>

#define MAX_TERM 1000

using namespace std;

long long int fibonacci(int);

long long int memory[MAX_TERM] = {};

int main(void)
{
    int nthTerm;
    cout << "Enter the term which you want for the fibonacci series: ";
    cin >> nthTerm;
    cout << "The " << nthTerm << "th term of the fibonacci series is: " << fibonacci(nthTerm) << '\n';
    return 0;
}

long long int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (memory[n])
    {
        return memory[n];
    }
    return memory[n] = fibonacci(n - 1) + fibonacci(n - 2);
}