#include <iostream>

#define MAX_LENGTH 1000

using namespace std;

int solve(int e, int f);
int Solve(int e, int f);

int memory[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
    int eggs, floors;
    cout << "Enter the number of eggs and floor: ";
    cin >> eggs >> floors;
    for (int i = 0; i < MAX_LENGTH + 1; i++)
    {
        for (int j = 0; j < MAX_LENGTH + 1; j++)
        {
            memory[i][j] = -1;
        }
    }
    cout << "The minimum number of attempts in the worst case is: " << solve(eggs, floors) << '\n';
    cout << "The minimum number of attempts in the worst case is: " << Solve(eggs, floors) << '\n';
    return 0;
}

int solve(int e, int f)
{
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }

    int minAttempts = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        if (temp < minAttempts)
        {
            minAttempts = temp;
        }
    }
    return minAttempts;
}

int Solve(int e, int f)
{
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }
    if (memory[e][f] != -1)
    {
        return memory[e][f];
    }

    int minAttempts = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int way1, way2;
        way1 = memory[e - 1][k - 1] != -1 ? memory[e - 1][k - 1] : memory[e - 1][k - 1] = solve(e - 1, k - 1); // More optimization
        way2 = memory[e][f - k] != -1 ? memory[e][f - k] : memory[e][f - k] = solve(e, f - k);                 // More optimization
        int temp = 1 + max(way1, way2);
        if (temp < minAttempts)
        {
            minAttempts = temp;
        }
    }
    return memory[e][f] = minAttempts;
}