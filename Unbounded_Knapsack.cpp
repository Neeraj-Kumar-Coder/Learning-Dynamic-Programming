// Rod cutting problem is same as this implementation
#include <iostream>

#define MAX_ITEMS MAX_CAPACITY
#define MAX_CAPACITY 1000

using namespace std;

int unboundedKnapsack(int *, int *, int, int);
int UnboundedKnapsack(int *, int *, int, int);

int memory[MAX_ITEMS + 1][MAX_CAPACITY + 1];
int Memory[MAX_ITEMS + 1][MAX_CAPACITY + 1];

int main(void)
{
    int numberOfObjects;
    cout << "Enter the number of objects: ";
    cin >> numberOfObjects;
    int *weight = new int[numberOfObjects];
    int *value = new int[numberOfObjects];
    for (int i = 0; i < numberOfObjects; i++)
    {
        cout << "Enter the weight and the value (w v): ";
        cin >> weight[i] >> value[i];
    }
    for (int i = 0; i < MAX_ITEMS + 1; i++)
    {
        for (int j = 0; j < MAX_CAPACITY + 1; j++)
        {
            memory[i][j] = -1;
        }
    }
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    cout << "The max profit is: " << unboundedKnapsack(weight, value, capacity, numberOfObjects) << '\n';
    cout << "The max profit is: " << UnboundedKnapsack(weight, value, capacity, numberOfObjects) << '\n';
    return 0;
}

int unboundedKnapsack(int *weight, int *value, int capacity, int numberOfObjects)
{
    if (!capacity || !numberOfObjects)
    {
        return 0;
    }
    if (memory[numberOfObjects][capacity] != -1)
    {
        return memory[numberOfObjects][capacity];
    }
    if (weight[numberOfObjects - 1] <= capacity)
    {
        int profit1 = value[numberOfObjects - 1] + unboundedKnapsack(weight, value, capacity - weight[numberOfObjects - 1], numberOfObjects);
        int profit2 = unboundedKnapsack(weight, value, capacity, numberOfObjects - 1);
        return memory[numberOfObjects][capacity] = max(profit1, profit2);
    }
    return memory[numberOfObjects][capacity] = unboundedKnapsack(weight, value, capacity, numberOfObjects - 1);
}

int UnboundedKnapsack(int *weight, int *value, int capacity, int numberOfObjects)
{
    for (int i = 0; i < numberOfObjects + 1; i++)
    {
        Memory[i][0] = 0;
    }
    for (int i = 0; i < capacity + 1; i++)
    {
        Memory[0][i] = 0;
    }
    for (int i = 1; i < numberOfObjects + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                Memory[i][j] = max(value[i - 1] + Memory[i][j - weight[i - 1]], Memory[i - 1][j]);
            }
            else
            {
                Memory[i][j] = Memory[i - 1][j];
            }
        }
    }
    return Memory[numberOfObjects][capacity];
}