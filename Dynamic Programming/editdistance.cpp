#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int editdistance(char *s1, char *s2, int i, int j, int dp[][100])
{
    // base case
    if (i == 0)
    {
        return j;
    }
    if (j == 0) return i;

    // recursive case
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i - 1] == s2[j - 1])
    {
        return editdistance(s1, s2, i - 1, j - 1, dp);
    }
    else
    {
        return dp[i][j] = min(
                              editdistance(s1, s2, i - 1, j, dp),         // deletion
                              min(editdistance(s1, s2, i, j - 1, dp),     // insertion
                                  editdistance(s1, s2, i - 1, j - 1, dp)) // replace
                              ) +
                          1;
    }
}
int bottoms_up(char *s1, char *s2)
{
    int n = strlen(s1);
    int m = strlen(s2);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 and j == 0){
                dp[i][j] = 0;
                }
            else if (i == 0) dp[i][j] = j;
            else if (j == 0)  dp[i][j] = i;
            else
            {
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                    continue;
                }
                int op1 = dp[i - 1][j];
                int op2 = dp[i][j - 1];
                int op3 = dp[i - 1][j - 1];
                dp[i][j] = min(op1, min(op2, op3)) + 1;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][m];
}
int main()
{
    char s1[] = "abcd";
    char s2[] = "acc";
    int dp[100][100];
    memset(dp, -1, sizeof dp);
    cout << editdistance(s1, s2, strlen(s1), strlen(s2), dp) << endl;
    cout << bottoms_up(s1, s2) << endl;
    return 0;
}