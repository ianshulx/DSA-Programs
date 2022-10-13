// Maximum Product Subarray in an Array
// Given an integer array nums, find a contiguous non-empty subarray within the array
// that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// A subarray is a contiguous subsequence of the array.
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// #Leetcode Medium Problem
#include <bits/stdc++.h>
using namespace std;

// Extended Kadane’s Algorithm
// Time Complexity : O(N)
// Space Complexity : O(1)
int maxProductSubArrayOpt(vector<int> &nums)
{
    int n = nums.size(), pdt1 = nums[0], pdt2 = nums[0], maxi = nums[0];
    for (int i = 1; i < n; i++)
    {
        // finding maximum for pdt1
        int temp = max({nums[i], pdt1 * nums[i], pdt2 * nums[i]});
        // finding maximum for ptd2
        pdt2 = min({nums[i], pdt1 * nums[i], pdt2 * nums[i]});
        pdt1 = temp;
        // max value stored in res
        maxi = max(maxi, pdt1);
    }
    return maxi;
}

// Two Traversal method
// Time Complexity : O(N)
// Space Complexity : O(1)
int maxProductSubArrayTwoTraversals(vector<int> &nums)
{
    int n = nums.size(), pdt = 1, maxleft = nums[0], maxright = nums[0];
    bool zeroPresent = false;
    for (auto x : nums)
    {
        pdt *= x;
        // check for zero presence from left side
        if (x == 0)
        {
            pdt = 1;
            zeroPresent = true;
            continue;
        }
        // finding left maximum
        maxleft = max(maxleft, pdt);
    }
    pdt = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        pdt *= nums[i];
        // check for zero presence from right side
        if (nums[i] == 0)
        {
            pdt = 1;
            zeroPresent = true;
            continue;
        }
        // finding right maximum
        maxright = max(maxright, pdt);
    }
    // returning result
    if (zeroPresent)
        return max(max(maxleft, maxright), 0);
    return max(maxleft, maxright);
}

// TimE Complexity : O(N^2)
// Space Complexity : O(1)
int maxProductSubArrayBruteOpt(vector<int> &nums)
{
    int pdt, n = nums.size(), maxi = nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        pdt = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            // finding max of pdt and maxi, then updating pdt
            maxi = max(maxi, pdt);
            pdt *= nums[j];
        }
        maxi = max(pdt, maxi);
    }
    return maxi;
}

// TimE Complexity : O(N^3)
// Space Complexity : O(1)
int maxProductSubArrayBrute(vector<int> &nums)
{
    int pdt, n = nums.size(), maxi = INT_MIN;
    // Using 3 nested loops to find maximum product
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pdt = 1;
            for (int k = i; k <= j; k++)
                pdt = pdt * nums[k];
            maxi = max(maxi, pdt);
        }
    }
    return maxi;
}

// main method
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    // taking user input
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Printing max product output
    cout << maxProductSubArrayOpt(arr) << endl;
    return 0;
}