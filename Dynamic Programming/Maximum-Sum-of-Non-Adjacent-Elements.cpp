#include <bits/stdc++.h>
using namespace std;

// House Robber Problem on Leetcode
class Solution
{
public:
    int dp[101];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }

    int recuMemo(int index, vector<int> nums)
    {
        if (index == 0)
            return nums[index];
        if (index < 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + recuMemo(index - 2, nums);
        int notpick = 0 + recuMemo(index - 1, nums);

        return dp[index] = max(pick, notpick);
        // return max(pick, notpick);
    }

    int tabulation(vector<int> nums)
    {
        int len = nums.size();
        int t[len], pick = INT_MIN, notpick;
        t[0] = nums[0]; // <----- This is the base case as nums[index]

        for (int i = 1; i < len; i++)
        {
            notpick = 0 + t[i - 1];
            pick = nums[i];

            if (i > 1)
                pick += t[i - 2];

            t[i] = max(pick, notpick);
        }
        cout << "Tabulation : " << t[len - 1] << "\n";
        return 1;
    }

    int spaceOptimization(vector<int> nums)
    {
        int prev = nums[0], prev2 = 0, len = nums.size();
        int pick = INT_MIN, notpick;

        for (int i = 1; i < len; i++)
        {
            notpick = 0 + prev;
            pick = nums[i];

            if (i > 1)
                pick += prev2;

            int curi = max(pick, notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        tabulation(nums);
        return recuMemo(n - 1, nums);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {9, 8, 3, 5, 9, 3, 2, 6, 5, 6, 5, 4, 3, 2, 6, 7};
    int num = s.rob(nums);
    cout << num << endl;

    return 0;
}