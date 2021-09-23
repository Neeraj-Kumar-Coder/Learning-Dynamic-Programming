#include <iostream>
#include <unordered_map>

using namespace std;

bool solve(string, string);
bool Solve(string, string);

unordered_map<string, bool> memory;

int main(void)
{
    string s1, s2;
    cout << "Enter the strings which you want to check for scramble: ";
    cin >> s1 >> s2;

    if (s1.length() != s2.length())
    {
        cout << "The strings are not scrambled!" << '\n';
        return 0;
    }
    if (s1.length() == 0 && s2.length() == 0)
    {
        cout << "The strings are scrambled!" << '\n';
        return 0;
    }

    cout << "Both strings are scrambled?: " << solve(s1, s2) << '\n';
    cout << "Both strings are scrambled?: " << Solve(s1, s2) << '\n';
    return 0;
}

bool solve(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    if (memory.find(a + b) != memory.end())
    {
        return memory[a + '-' + b];
    }

    int n = a.length();

    for (int k = 1; k < n; k++)
    {
        bool condition1 = solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k, n - k), b.substr(k, n - k));     // No swap
        bool condition2 = solve(a.substr(0, k), b.substr(n - k, k)) && solve(a.substr(k, n - k), b.substr(0, n - k)); // Swap
        if (condition1 || condition2)
        {
            return memory[a + '-' + b] = true;
        }
    }
    return memory[a + '-' + b] = false;
}

bool Solve(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }

    int n = a.length();

    for (int k = 1; k < n; k++)
    {
        bool condition1 = solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k, n - k), b.substr(k, n - k));     // No swap
        bool condition2 = solve(a.substr(0, k), b.substr(n - k, k)) && solve(a.substr(k, n - k), b.substr(0, n - k)); // Swap
        if (condition1 || condition2)
        {
            return true;
        }
    }
    return false;
}