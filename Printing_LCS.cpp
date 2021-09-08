#include <iostream>
#include <algorithm>

using namespace std;

string printLCS(string, string);

int main(void)
{
    string a, b;
    cout << "Enter the two strings: ";
    cin >> a >> b;
    cout << "The LCS is: " << printLCS(a, b) << '\n';
    return 0;
}

string printLCS(string a, string b)
{
    string lcs;
    int m = a.length(), n = b.length();
    int **memory = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        memory[i] = new int[n + 1];
    }

    // Normal LCS method

    for (int i = 0; i < n + 1; i++)
    {
        memory[0][i] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        memory[i][0] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                memory[i][j] = 1 + memory[i - 1][j - 1];
                // lcs.push_back(a[i - 1]); // No need to reverse the string if we use this
            }
            else
            {
                memory[i][j] = max(memory[i][j - 1], memory[i - 1][j]);
            }
        }
    }

    int i = m, j = n;
    string lcs;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            i--, j--;
        }
        else
        {
            if (memory[i][j - 1] > memory[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    return lcs;
}