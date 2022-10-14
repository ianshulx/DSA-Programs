// Longest Common Subsequence All Approaches
// Given two strings text1 and text2, return the length of their longest common subsequence.
// If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some
// characters(can be none) deleted without changing the relative order of the remaining characters.
// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// #Leetcode Medium
#include <bits/stdc++.h>
using namespace std;

// Bottom Up Tabulation Space Optimized DP Approach
// Shifting of Index
// Time Complexity : O(N * M) [N and M are lengths of s1 and s2 strings]
// Space Complexity : O(M)
// Auxiliary Space Complexity : O(1) [As no recursion involved]
int lcsBUSO(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}

// Printing the Longest Common Subsequence
// Bottom Up Tabulation DP Approach
// Shifting of Index
// Time Complexity : O(N * M) + O(N + M) [N and M are lengths of s1 and s2 strings]
// Space Complexity : O(N * M)
// Auxiliary Space Complexity : O(1) [As no recursion involved]
int lcsBUPrint(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[n][m];
    string s = "";
    for (int i = 0; i < len; i++)
        s += '$';
    int ind = len - 1;
    int i = n, j = m;
    //  At max it can go till O(N + M)
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s[ind--] = s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << "Longest Common Subsequence : " << s << endl;
    return len;
}

// Bottom Up Tabulation DP Approach
// Shifting of Index
// Time Complexity : O(N * M) [N and M are lengths of s1 and s2 strings]
// Space Complexity : O(N * M)
// Auxiliary Space Complexity : O(1) [As no recursion involved]
int lcsBU(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Top Down Memoization DP Approach
// Time Complexity : O(N * M) [N and M are lengths of s1 and s2 strings]
// Space Complexity : O(N * M)
// Auxiliary Space Complexity : O(N + M)
int lcsTDf(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // Match case
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsTDf(i - 1, j - 1, s1, s2, dp);
    // Not match case
    return dp[i][j] = max(lcsTDf(i - 1, j, s1, s2, dp), lcsTDf(i, j - 1, s1, s2, dp));
}
int lcsTD(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsTDf(n - 1, m - 1, s1, s2, dp);
}

// Recursive Approach
// Time Complexity : O(2^N * 2^M) [N and M are lengths of s1 and s2 strings]
// Space Complexity : O(1)
// Auxiliary Space Complexity : O(N + M)
int lcsRecf(int i, int j, string &s1, string &s2)
{
    if (i < 0 or j < 0)
        return 0;
    // Match case
    if (s1[i] == s2[j])
        return 1 + lcsRecf(i - 1, j - 1, s1, s2);
    // Not match case
    return max(lcsRecf(i - 1, j, s1, s2), lcsRecf(i, j - 1, s1, s2));
}
int lcsRec(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    return lcsRecf(n - 1, m - 1, s1, s2);
}

// Main method
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << "String 1 : " << s1 << endl;
    cout << "String 2 : " << s2 << endl;
    cout << lcsBUSO(s1, s2) << endl;
    return 0;
}