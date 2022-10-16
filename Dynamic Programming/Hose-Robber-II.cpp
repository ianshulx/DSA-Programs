#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define V(a, x, n, m) vector<vector<x>> a(n, vector<x>(m))

class Solution
{
public:
    int subsequences(vector<int> nums, bool flag)
    {
        if (!flag)
            nums.pop_back();
        else
            nums.erase(nums.begin());

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
        return max(subsequences(nums, false), subsequences(nums, false));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
    }
    return 0;
}
