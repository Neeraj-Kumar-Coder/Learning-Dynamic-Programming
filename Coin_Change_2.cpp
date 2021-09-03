#include <iostream>

#define MAX_COIN MAX_SUM
#define MAX_SUM 1000

using namespace std;

int coinChange2(int *, int, int);
int CoinChange2(int *, int, int);

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
    cout << "Minimum coin required to achieve the sum is: " << coinChange2(coin, sum, numberOfCoins) << '\n';
    cout << "Minimum coin required to achieve the sum is: " << CoinChange2(coin, sum, numberOfCoins) << '\n';
    return 0;
}

int coinChange2(int *coin, int sum, int numberOfCoins)
{
    if (!numberOfCoins)
    {
        return INT_MAX - 1;
    }
    if (!sum)
    {
        return 0;
    }
    if (numberOfCoins == 1)
    {
        if (sum % coin[0] == 0)
        {
            return sum / coin[0];
        }
        else
        {
            return INT_MAX - 1;
        }
    }
    if (memory[numberOfCoins][sum] != -1)
    {
        return memory[numberOfCoins][sum];
    }

    if (coin[numberOfCoins - 1] <= sum)
    {
        int coinreq1 = coinChange2(coin, sum - coin[numberOfCoins - 1], numberOfCoins) + 1;
        int coinreq2 = coinChange2(coin, sum, numberOfCoins - 1);
        return memory[numberOfCoins][sum] = min(coinreq1, coinreq2);
    }
    return memory[numberOfCoins][sum] = coinChange2(coin, sum, numberOfCoins - 1);
}

int CoinChange2(int *coin, int sum, int numberOfCoins)
{
    for (int i = 0; i < sum + 1; i++)
    {
        Memory[0][i] = INT_MAX - 1;
    }
    for (int i = 1; i < numberOfCoins + 1; i++)
    {
        Memory[i][0] = 0;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        if (i % coin[0] == 0)
        {
            Memory[1][i] = i / coin[0];
        }
        else
        {
            Memory[1][i] = INT_MAX - 1;
        }
    }

    for (int i = 2; i < numberOfCoins + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                Memory[i][j] = min(Memory[i][j - coin[i - 1]] + 1, Memory[i - 1][j]);
            }
            else
            {
                Memory[i][j] = Memory[i - 1][j];
            }
        }
    }

    return Memory[numberOfCoins][sum];
}