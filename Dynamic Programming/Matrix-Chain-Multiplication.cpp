#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[501][501];

    int solve(int i, int j, vector<int> arr)
    {
        if (i >= j)
            return 0;

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempAns = solve(i, k, arr) + solve(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, tempAns);
        }
        return ans;
    }

    int memoRecur(int i, int j, vector<int> arr)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempAns = solve(i, k, arr) + solve(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, tempAns);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, vector<int> arr)
    {
        cout << memoRecur(1, N - 1, arr);
        return solve(1, N - 1, arr);
    }
};

int main()
{
    vector<int> nums = {40, 20, 30, 10, 30};
    Solution s;
    cout << s.matrixMultiplication(nums.size(), nums);

    return 0;
}