#include <iostream>

#define MAX_LENGTH 1000

using namespace std;

int longestCommonSubsequence(string, string, int, int);
int LongestCommonSubsequence(string, string, int, int);

int memory[MAX_LENGTH + 1][MAX_LENGTH + 1];
int Memory[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
    string a, b;
    cout << "Enter the two string a and b: ";
    cin >> a >> b;
    for (int i = 0; i < MAX_LENGTH + 1; i++)
    {
        for (int j = 0; j < MAX_LENGTH + 1; j++)
        {
            memory[i][j] = -1;
        }
    }
    if (longestCommonSubsequence(a, b, a.length(), b.length()) == a.length())
    {
        cout << "string \'a\' is a subsequence in \'b\'" << '\n';
    }
    else
    {
        cout << "string \'a\' is NOT a subsequence in \'b\'" << '\n';
    }
    if (LongestCommonSubsequence(a, b, a.length(), b.length()) == a.length())
    {
        cout << "string \'a\' is a subsequence in \'b\'" << '\n';
    }
    else
    {
        cout << "string \'a\' is NOT a subsequence in \'b\'" << '\n';
    }
    return 0;
}

int longestCommonSubsequence(string a, string b, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (memory[m][n] != -1)
    {
        return memory[m][n];
    }

    if (a[m - 1] == b[n - 1])
    {
        return memory[m][n] = 1 + longestCommonSubsequence(a, b, m - 1, n - 1);
    }
    else
    {
        int longest1 = longestCommonSubsequence(a, b, m, n - 1);
        int longest2 = longestCommonSubsequence(a, b, m - 1, n);
        return memory[m][n] = max(longest1, longest2);
    }
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