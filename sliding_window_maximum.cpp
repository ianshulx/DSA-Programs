#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(comparator);

    int n = nums.size();
    vector<int> windowMax;

    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }
    windowMax.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {

        pq.push({nums[i], i});
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        windowMax.push_back(pq.top().first);
    }
    return windowMax;
}

int main()
{
    vector<int> arr = {1, 1, 5, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int k=4;
    vector<int> max_arr =  maxSlidingWindow(arr,k);
    for(auto e : max_arr){
        cout<<e<<" ";
    }
}
