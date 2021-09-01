// Target Sum question is of this type only, the mode of delivering the question is different
#include <iostream>

#define MAX_ELEMENT MAX_SUM
#define MAX_SUM 100

using namespace std;

int memory[MAX_ELEMENT + 1][MAX_SUM + 1];

int numberOfSubsetWithGivenDifference(int *, int, int);
int countOfSubset(int *, int, int);

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
    int givenDifference;
    cout << "Enter the difference you want to find for: ";
    cin >> givenDifference;
    cout << "The number of possible partitions are: " << numberOfSubsetWithGivenDifference(array, givenDifference, numberOfElements) << '\n';
    return 0;
}

int numberOfSubsetWithGivenDifference(int *array, int givenDifference, int numberOfElements)
{
    int range = 0;
    for (int i = 0; i < numberOfElements; i++)
    {
        range += array[i];
    }
    return countOfSubset(array, (range + givenDifference) / 2, numberOfElements);
}

int countOfSubset(int *array, int sum, int numberOfElements)
{
    // (Initialization) Base Case
    for (int i = 0; i < numberOfElements; i++)
    {
        memory[i][0] = 1;
    }
    for (int i = 1; i < sum; i++)
    {
        memory[0][i] = 0;
    }

    // Choice (Recursive Part)
    for (int i = 1; i < numberOfElements + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (array[i - 1] <= j)
            {
                memory[i][j] = memory[i - 1][j - array[i - 1]] + memory[i - 1][j];
            }
            else
            {
                memory[i][j] = memory[i - 1][j];
            }
        }
    }
    return memory[numberOfElements][sum];
}