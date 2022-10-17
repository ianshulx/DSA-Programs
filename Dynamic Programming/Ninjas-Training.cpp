/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities.
(Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day.
As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
Your task is to calculate the maximum number of merit points that Ninja can earn.

If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
The first line of the input contains an integer, 'T,’ denoting the number of test cases.
The first line of each test case contains a single integer,' N’, denoting the number of days.
The next ‘N’ lines of each test case have 3 integers corresponding to POINTS[i].

For each test case, return an integer corresponding to the maximum coins  Ninja can collect.

You do not need to print anything. It has already been taken care of. Just implement the given function.

1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .
Time limit: 1 sec
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define V(a, x, n, m) vector<vector<x>> a(n, vector<x>(m))

class Solution
{
    int recuMemo(int day, int last, vector<vector<int>> points, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int i = 0; i < 3; ++i)
                if (i != last)
                    maxi = max(maxi, points[0][i]);

            return maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for (int i = 0; i < 3; ++i)
            if (i != last)
            {
                int point = points[day][i] + recuMemo(day - 1, i, points, dp);
                maxi = max(maxi, point);
            }

        return dp[day][last] = maxi;
    }

    int tabulation(int n, vector<vector<int>> points)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; ++day)
        {
            for (int last = 0; last < 4; ++last)
            {
                dp[day][last] = 0;

                for (int task = 0; last < 3; ++task)
                {
                    if(task!=last){
                        
                    }
                }
            }
        }
    }

    int ninjaTraining(int n, vector<vector<int>> points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return recuMemo(points.size() - 1, 3, points, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;

    return 0;
}
