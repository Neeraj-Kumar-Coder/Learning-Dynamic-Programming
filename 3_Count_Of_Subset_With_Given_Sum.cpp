#include <iostream>

#define MAX_ELEMENT MAX_SUM
#define MAX_SUM 100

using namespace std;

int countOfSubset(int *, int, int);
int CountOfSubset(int *, int, int);

int memory[MAX_ELEMENT + 1][MAX_SUM + 1];
int Memory[MAX_ELEMENT + 1][MAX_SUM + 1];

int main(void)
{
    int numberOfElements;
    cout << "Enter the number of elements: ";
    cin >> numberOfElements;
    int *array = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << "Enter the element: ";
        cin >> array[i];
    }
    for (int i = 0; i < MAX_ELEMENT + 1; i++)
    {
        for (int j = 0; j < MAX_SUM + 1; j++)
        {
            memory[i][j] = -1;
        }
    }
    int sum;
    cout << "Enter the sum you want to search for the presence: ";
    cin >> sum;
    cout << "Number of subset with the provided sum is: " << countOfSubset(array, sum, numberOfElements) << '\n';
    cout << "Number of subset with the provided sum is: " << CountOfSubset(array, sum, numberOfElements) << '\n';
    return 0;
}

int countOfSubset(int *array, int sum, int numberOfElements)
{
    if (!sum)
    {
        return 1;
    }
    if (!numberOfElements)
    {
        return 0;
    }
    if (memory[numberOfElements][sum] != -1)
    {
        return memory[numberOfElements][sum];
    }
    if (array[numberOfElements - 1] <= sum)
    {
        return memory[numberOfElements][sum] = countOfSubset(array, sum - array[numberOfElements - 1], numberOfElements - 1) + countOfSubset(array, sum, numberOfElements - 1);
    }
    return memory[numberOfElements][sum] = countOfSubset(array, sum, numberOfElements - 1);
}

int CountOfSubset(int *array, int sum, int numberOfElements)
{
    // (Initialization) Base Case
    for (int i = 0; i < numberOfElements; i++)
    {
        Memory[i][0] = 1;
    }
    for (int i = 1; i < sum; i++)
    {
        Memory[0][i] = 0;
    }

    // Choice (Recursive Part)
    for (int i = 1; i < numberOfElements + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (array[i - 1] <= j)
            {
                Memory[i][j] = Memory[i - 1][j - array[i - 1]] + Memory[i - 1][j];
            }
            else
            {
                Memory[i][j] = Memory[i - 1][j];
            }
        }
    }
    return Memory[numberOfElements][sum];
}