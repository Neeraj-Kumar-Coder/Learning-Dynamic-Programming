#include <iostream>

#define MAX_ELEMENT MAX_SUM
#define MAX_SUM 100

using namespace std;

bool memory[MAX_ELEMENT + 1][MAX_SUM + 1];

int minimumSubsetSumDifference(int *, int);
void SubsetSum(int *, int, int);

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
    cout << "The minimum subset sum difference is: " << minimumSubsetSumDifference(array, numberOfElements) << '\n';
    return 0;
}

int minimumSubsetSumDifference(int *array, int numberOfElements)
{
    int range = 0, difference;
    for (int i = 0; i < numberOfElements; i++)
    {
        range += array[i];
    }
    subsetSum(array, range, numberOfElements);
    for (int i = range / 2; i >= 0; i--)
    {
        if (memory[numberOfElements][i])
        {
            difference = range - 2 * i;
            break;
        }
    }
    return difference;
}

void subsetSum(int *array, int sum, int numberOfElements)
{
    // (Initialization) Base Case
    for (int i = 0; i < numberOfElements; i++)
    {
        memory[i][0] = true;
    }
    for (int i = 1; i < sum; i++)
    {
        memory[0][i] = false;
    }

    // Choice (Recursive Part)
    for (int i = 1; i < numberOfElements + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (array[i - 1] <= j)
            {
                memory[i][j] = memory[i - 1][j - array[i - 1]] || memory[i - 1][j];
            }
            else
            {
                memory[i][j] = memory[i - 1][j];
            }
        }
    }
}