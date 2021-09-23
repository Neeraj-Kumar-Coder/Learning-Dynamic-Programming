#include <iostream>

#define MAX_SIZE 100

using namespace std;

int solve(string, int, int, bool);
int Solve(string, int, int, bool);

int memory[MAX_SIZE + 1][MAX_SIZE + 1][2];

int main(void)
{
    string expression;
    cout << "Enter the expression to be evaluated to True: ";
    cin >> expression;

    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        for (int j = 0; j < MAX_SIZE + 1; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                memory[i][j][k] = -1;
            }
        }
    }

    cout << "Number of ways the expression is evaluated to True: " << solve(expression, 0, expression.length() - 1, true) << '\n';
    cout << "Number of ways the expression is evaluated to True: " << Solve(expression, 0, expression.length() - 1, true) << '\n';
    return 0;
}

int solve(string expr, int start, int end, bool isTrue)
{
    if (start > end)
    {
        return false;
    }
    if (start == end)
    {
        if (isTrue)
        {
            return expr[start] == 'T';
        }
        else
        {
            return expr[start] == 'F';
        }
    }

    int count = 0;
    for (int k = start + 1; k < end; k += 2)
    {
        int left_T = solve(expr, start, k - 1, true);
        int left_F = solve(expr, start, k - 1, false);
        int right_T = solve(expr, k + 1, end, true);
        int right_F = solve(expr, k + 1, end, false);

        if (expr[k] == '&')
        {
            if (isTrue)
            {
                count += left_T * right_T;
            }
            else
            {
                count += left_F * right_T + left_T * right_F + left_F * right_F;
            }
        }
        else if (expr[k] == '|')
        {
            if (isTrue)
            {
                count += left_T * right_F + left_F * right_T + left_T * right_T;
            }
            else
            {
                count += left_F * right_F;
            }
        }
        else if (expr[k] == '^')
        {
            if (isTrue)
            {
                count += left_T * right_F + left_F * right_T;
            }
            else
            {
                count += left_T * right_T + left_F * right_F;
            }
        }
    }
    return count;
}

int Solve(string expr, int start, int end, bool isTrue)
{
    if (start > end)
    {
        return false;
    }
    if (start == end)
    {
        if (isTrue)
        {
            return expr[start] == 'T';
        }
        else
        {
            return expr[start] == 'F';
        }
    }
    if (memory[start][end][isTrue] != -1)
    {
        return memory[start][end][isTrue];
    }

    int count = 0;
    for (int k = start + 1; k < end; k += 2)
    {
        int left_T = memory[start][k - 1][1] = solve(expr, start, k - 1, true);
        int left_F = memory[start][k - 1][0] = solve(expr, start, k - 1, false);
        int right_T = memory[k + 1][end][1] = solve(expr, k + 1, end, true);
        int right_F = memory[k + 1][end][0] = solve(expr, k + 1, end, false);

        if (expr[k] == '&')
        {
            if (isTrue)
            {
                count += left_T * right_T;
            }
            else
            {
                count += left_F * right_T + left_T * right_F + left_F * right_F;
            }
        }
        else if (expr[k] == '|')
        {
            if (isTrue)
            {
                count += left_T * right_F + left_F * right_T + left_T * right_T;
            }
            else
            {
                count += left_F * right_F;
            }
        }
        else if (expr[k] == '^')
        {
            if (isTrue)
            {
                count += left_T * right_F + left_F * right_T;
            }
            else
            {
                count += left_T * right_T + left_F * right_F;
            }
        }
    }
    return memory[start][end][isTrue] = count;
}