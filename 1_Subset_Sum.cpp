#include <iostream>

#define MAX_ELEMENT MAX_SUM
#define MAX_SUM 100

using namespace std;

bool subsetSum(int *, int, int);
bool SubsetSum(int *, int, int);

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
            Memory[i][j] = -1;
        }
    }
    int sum;
    cout << "Enter the sum you want to search for: ";
    cin >> sum;
    cout << "Subset Sum Exist?: " << boolalpha << subsetSum(array, sum, numberOfElements) << noboolalpha << '\n';
    cout << "Subset Sum Exist?: " << boolalpha << SubsetSum(array, sum, numberOfElements) << noboolalpha << '\n';
    return 0;
}

bool subsetSum(int *array, int sum, int numberOfElements)
{
    if (!sum)
    {
        return true;
    }
    if (!numberOfElements)
    {
        return false;
    }
    if (memory[numberOfElements][sum] != -1)
    {
        return memory[numberOfElements][sum];
    }
    if (array[numberOfElements - 1] <= sum)
    {
        return (memory[numberOfElements][sum] = (subsetSum(array, sum - array[numberOfElements - 1], numberOfElements - 1) || subsetSum(array, sum, numberOfElements - 1)));
    }
    return (memory[numberOfElements][sum] = subsetSum(array, sum, numberOfElements - 1));
}

bool SubsetSum(int *array, int sum, int numberOfElements)
{
    // (Initialization) Base Case
    for (int i = 0; i < numberOfElements; i++)
    {
        Memory[i][0] = true;
    }
    for (int i = 1; i < sum; i++)
    {
        Memory[0][i] = false;
    }

    // Choice (Recursive Part)
    for (int i = 1; i < numberOfElements + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (array[i - 1] <= j)
            {
                Memory[i][j] = Memory[i - 1][j - array[i - 1]] || Memory[i - 1][j];
            }
            else
            {
                Memory[i][j] = Memory[i - 1][j];
            }
        }
    }
    return Memory[numberOfElements][sum];
}