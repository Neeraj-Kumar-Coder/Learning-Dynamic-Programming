#include <iostream>

#define MAX_ITEMS MAX_WEIGHT
#define MAX_WEIGHT 100

using namespace std;

int knapsack(int *, int *, int, int);
int Knapsack(int *, int *, int, int);

int memory[MAX_WEIGHT + 1][MAX_ITEMS + 1];
int Memory[MAX_WEIGHT + 1][MAX_ITEMS + 1];

int main(void)
{
    int numberOfItems, capacity;
    cout << "Enter the number of items: ";
    cin >> numberOfItems;
    int *weight = new int[numberOfItems];
    int *value = new int[numberOfItems];
    for (int item = 0; item < numberOfItems; item++)
    {
        cout << "Enter the weight and the value of the item: ";
        cin >> weight[item] >> value[item];
    }
    for (int i = 0; i < MAX_ITEMS + 1; i++)
    {
        for (int j = 0; j < MAX_ITEMS + 1; j++)
        {
            memory[i][j] = -1;
        }
    }

    cout << "Enter the capacity of your knapsack: ";
    cin >> capacity;
    cout << "The maximum profit we can get is : " << knapsack(weight, value, capacity, numberOfItems) << '\n';
    cout << "The maximum profit we can get is : " << Knapsack(weight, value, capacity, numberOfItems) << '\n';
    return 0;
}

// Top Down
int knapsack(int *weight, int *value, int capacity, int numberOfItems)
{
    if (!capacity || !numberOfItems)
    {
        return 0;
    }

    if (memory[capacity][numberOfItems] != -1)
    {
        return memory[capacity][numberOfItems];
    }

    if (weight[numberOfItems - 1] <= capacity)
    {
        int profit1 = value[numberOfItems - 1] + knapsack(weight, value, capacity - weight[numberOfItems - 1], numberOfItems - 1);
        int profit2 = knapsack(weight, value, capacity, numberOfItems - 1);
        return memory[capacity][numberOfItems] = profit1 > profit2 ? profit1 : profit2;
    }

    return memory[capacity][numberOfItems] = knapsack(weight, value, capacity, numberOfItems - 1);
}

// Bottom Up
int Knapsack(int *weight, int *value, int capacity, int numberOfItems)
{
    // Initialization (Base condition)
    for (int i = 0; i < numberOfItems + 1; i++)
    {
        Memory[0][i] = 0;
    }
    for (int i = 0; i < capacity + 1; i++)
    {
        Memory[i][0] = 0;
    }

    // Choice (Recursive part)
    for (int i = 1; i < capacity + 1; i++)
    {
        for (int j = 1; j < numberOfItems + 1; j++)
        {
            if (weight[j - 1] <= i)
            {
                int profit1 = value[j - 1] + Memory[i - weight[j - 1]][j - 1];
                int profit2 = Memory[i][j - 1];
                Memory[i][j] = profit1 > profit2 ? profit1 : profit2;
            }
            else
            {
                Memory[i][j] = Memory[i][j - 1];
            }
        }
    }
    return Memory[capacity][numberOfItems];
}