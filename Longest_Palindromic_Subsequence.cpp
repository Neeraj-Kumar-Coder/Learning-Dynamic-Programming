#include <iostream>
#include <algorithm>

#define MAX_LENGTH 1000

using namespace std;

int LongestCommonSubsequence(string, string, int, int);

int Memory[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
    string a;
    cout << "Enter the string you want to find longest palindromic subsequence: ";
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    cout << "The lenght of longest palindromic subsequence: " << LongestCommonSubsequence(a, b, a.length(), a.length()) << '\n';
    return 0;
}

int LongestCommonSubsequence(string a, string b, int m, int n)
{
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
                Memory[i][j] = max(Memory[i][j - 1], Memory[i - 1][j]);
            }
        }
    }
    return Memory[m][n];
}