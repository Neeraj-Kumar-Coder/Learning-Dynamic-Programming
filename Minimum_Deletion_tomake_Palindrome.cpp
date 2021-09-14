// Minimum number of deletions == Minimum number of insertions, to make a string a palindrome
#include <iostream>
#include <algorithm>

#define MAX_LENGTH 1000

using namespace std;

int LongestCommonSubsequence(string, string, int, int);

int Memory[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
    string a;
    cout << "Enter the string which you want to make palindrom by deletion: ";
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    cout << "Minimum deletions: " << a.length() - LongestCommonSubsequence(a, b, a.length(), b.length()) << '\n';
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