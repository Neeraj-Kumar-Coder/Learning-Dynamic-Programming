#include <iostream>

#define MAX_LENGTH 1000

using namespace std;

int LongestCommonString(string, string, int, int);

int Memory[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
    string a, b;
    cout << "Enter the two string a and b: ";
    cin >> a >> b;
    cout << "The length of longest common substring is: " << LongestCommonString(a, b, a.length(), b.length()) << '\n';
    return 0;
}

int LongestCommonString(string a, string b, int m, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        Memory[0][i] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        Memory[i][0] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                Memory[i][j] = 1 + Memory[i - 1][j - 1];
            }
            else
            {
                Memory[i][j] = 0;
            }
            if (Memory[i][j] > max)
            {
                max = Memory[i][j];
            }
        }
    }
    return max;
}