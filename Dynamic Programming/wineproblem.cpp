#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int topdown(int *wine, int day, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // recursive case
    int op1, op2;
    op1 = op2 = INT_MIN;
    op1 = wine[i] * day + topdown(wine, day + 1, i + 1, j, dp);
    op2 = wine[j] * day + topdown(wine, day + 1, i, j - 1, dp);
    return dp[i][j] = max(op1, op2);
}
int bottoms_up(int *wine, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = wine[i] * n;
            }
            else
            {   
                int day = n - (j - i);
                int op1 = wine[i] * day + dp[i + 1][j];
                int op2 = wine[j] * day + dp[i][j - 1];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n - 1];
}
int main()
{
    int wine[] = {2, 3, 5, 1, 4};
    int n = sizeof(wine) / sizeof(int);
    vector<vector<int>> dp(100, vector<int>(100, -1));
    cout << topdown(wine, 1, 0, n - 1, dp) << endl;
    cout << bottoms_up(wine, 5) << endl;
    return 0;
}