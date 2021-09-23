#include <iostream>

#define MAX_LENGTH 1000

using namespace std;

bool isPalindrome(string, int, int);
int solve(string, int, int);
int Solve(string, int, int);

int memory[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
    string key;
    cout << "Enter the string to check for partition count: ";
    cin >> key;

    for (int i = 0; i < MAX_LENGTH + 1; i++)
    {
        for (int j = 0; j < MAX_LENGTH + 1; j++)
        {
            memory[i][j] = -1;
        }
    }

    cout << "Minimum number of partitions are: " << solve(key, 0, key.length() - 1) << '\n';
    cout << "Minimum number of partitions are: " << Solve(key, 0, key.length() - 1) << '\n';
    return 0;
}

bool isPalindrome(string key, int i, int j)
{
    while (i < j)
    {
        if (key[i++] != key[j--])
        {
            return false;
        }
    }
    return true;
}

int solve(string key, int start, int end)
{
    if (start >= end || isPalindrome(key, start, end))
    {
        return 0;
    }

    int minPartitions = INT_MAX;
    for (int k = start; k < end; k++)
    {
        int tempAnswer = solve(key, start, k) + solve(key, k + 1, end) + 1;
        if (tempAnswer < minPartitions)
        {
            minPartitions = tempAnswer;
        }
    }
    return minPartitions;
}

int Solve(string key, int start, int end)
{
    if (start >= end || isPalindrome(key, start, end))
    {
        return 0;
    }
    if (memory[start][end] != -1)
    {
        return memory[start][end];
    }

    int minPartitions = INT_MAX;
    for (int k = start; k < end; k++)
    {
        // Further optimization can be done here that before making the two recursive calls, we can check if the value is evaluated earlier
        int tempAnswer = solve(key, start, k) + solve(key, k + 1, end) + 1;
        if (tempAnswer < minPartitions)
        {
            minPartitions = tempAnswer;
        }
    }
    return memory[start][end] = minPartitions;
}