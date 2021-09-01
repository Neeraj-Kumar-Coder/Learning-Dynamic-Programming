#include <iostream>

#define MAX_ELEMENT MAX_SUM
#define MAX_SUM 100

using namespace std;

bool equalSumPartition(int *, int);
bool SubsetSum(int *, int, int);

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
    cout << "Can be paritioned in equal sum?: " << boolalpha << equalSumPartition(array, numberOfElements) << noboolalpha << '\n';
    return 0;
}

bool equalSumPartition(int *array, int numberOfElements)
{
    int sum = 0;
    for (int i = 0; i < numberOfElements; i++)
    {
        sum += array[i];
    }
    if (sum & 1)
    {
        return false;
    }
    return SubsetSum(array, sum / 2, numberOfElements);
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