#include <iostream>

#define MAX_SIZE 1000

using namespace std;

int solve(int *, int, int);
int Solve(int *, int, int);

int memory[MAX_SIZE + 1][MAX_SIZE + 1];

int main(void)
{
    int numberOfTerms;
    cout << "Enter the number of terms: ";
    cin >> numberOfTerms;
    int *dimensionArray = new int[numberOfTerms];
    for (int i = 0; i < numberOfTerms; i++)
    {
        cout << "Enter the value: ";
        cin >> dimensionArray[i];
    }
    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        for (int j = 0; j < MAX_SIZE + 1; j++)
        {
            memory[i][j] = -1;
        }
    }

    cout << "The minimum possible cost for the multiplication is: " << solve(dimensionArray, 1, numberOfTerms - 1) << '\n';
    cout << "The minimum possible cost for the multiplication is: " << Solve(dimensionArray, 1, numberOfTerms - 1) << '\n';
    return 0;
}

int solve(int *dimension, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int minCost = INT_MAX;
    for (int k = start; k < end; k++)
    {
        int tempAnswer = solve(dimension, start, k) + solve(dimension, k + 1, end) + dimension[start - 1] * dimension[k] * dimension[end];
        if (tempAnswer < minCost)
        {
            minCost = tempAnswer;
        }
    }
    return minCost;
}

int Solve(int *dimension, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    if (memory[start][end] != -1)
    {
        return memory[start][end];
    }

    int minCost = INT_MAX;
    for (int k = start; k < end; k++)
    {
        int tempAnswer = solve(dimension, start, k) + solve(dimension, k + 1, end) + dimension[start - 1] * dimension[k] * dimension[end];
        if (tempAnswer < minCost)
        {
            minCost = tempAnswer;
        }
    }
    return memory[start][end] = minCost;
}