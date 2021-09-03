#include <iostream>

#define MAX_COIN MAX_SUM
#define MAX_SUM 1000

using namespace std;

int coinChange1(int *, int, int);
int CoinChange1(int *, int, int);

int memory[MAX_COIN + 1][MAX_SUM + 1];
int Memory[MAX_COIN + 1][MAX_SUM + 1];

int main(void)
{
    int numberOfCoins;
    cout << "Enter the number of elements: ";
    cin >> numberOfCoins;
    int *coin = new int[numberOfCoins];
    cout << "Enter the elements: ";
    for (int i = 0; i < numberOfCoins; i++)
    {
        cin >> coin[i];
    }
    for (int i = 0; i < MAX_COIN + 1; i++)
    {
        for (int j = 0; j < MAX_SUM + 1; j++)
        {
            memory[i][j] = -1;
        }
    }
    int sum;
    cout << "Enter the sum you want: ";
    cin >> sum;
    cout << "The max number of ways to get the sum is: " << coinChange1(coin, sum, numberOfCoins) << '\n';
    cout << "The max number of ways to get the sum is: " << CoinChange1(coin, sum, numberOfCoins) << '\n';
    return 0;
}

int coinChange1(int *coin, int sum, int numberOfCoins)
{
    if (!sum)
    {
        return 1;
    }
    if (!numberOfCoins)
    {
        return 0;
    }
    if (memory[numberOfCoins][sum] != -1)
    {
        return memory[numberOfCoins][sum];
    }
    if (coin[numberOfCoins - 1] <= sum)
    {
        int way1 = coinChange1(coin, sum - coin[numberOfCoins - 1], numberOfCoins);
        int way2 = coinChange1(coin, sum, numberOfCoins - 1);
        return memory[numberOfCoins][sum] = way1 + way2;
    }
    return memory[numberOfCoins][sum] = coinChange1(coin, sum, numberOfCoins - 1);
}

int CoinChange1(int *coin, int sum, int numberOfCoins)
{
    for (int i = 0; i < numberOfCoins + 1; i++)
    {
        Memory[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        Memory[0][i] = 0;
    }

    for (int i = 1; i < numberOfCoins + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                Memory[i][j] = Memory[i][j - coin[i - 1]] + Memory[i - 1][j];
            }
            else
            {
                Memory[i][j] = Memory[i - 1][j];
            }
        }
    }
    return Memory[numberOfCoins][sum];
}