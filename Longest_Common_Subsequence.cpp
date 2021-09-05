#include <iostream>

using namespace std;

int longestCommonSubsequence(string, string, int, int);

int main(void)
{
    string a, b;
    cout << "Enter the two string a and b: ";
    cin >> a >> b;
    cout << "The length of longest common subsequence is: " << longestCommonSubsequence(a, b, a.length(), b.length()) << '\n';
    return 0;
}

int longestCommonSubsequence(string a, string b, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (a[m - 1] == b[n - 1])
    {
        return 1 + longestCommonSubsequence(a, b, m - 1, n - 1);
    }
    else
    {
        int longest1 = longestCommonSubsequence(a, b, m, n - 1);
        int longest2 = longestCommonSubsequence(a, b, m - 1, n);
        return max(longest1, longest2);
    }
}