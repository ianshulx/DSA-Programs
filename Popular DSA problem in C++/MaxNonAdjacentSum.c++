#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(int n,vector<int> &nums){
    //int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1)
        take+=prev2;
        int non_take=0+prev;
        int curi=max(take,non_take);
        prev2=prev;
        prev=curi;
    }
    return prev;
}

int main(){
    vector<int> arr{4,6,7,8,3};
    int n=arr.size();
    cout<<maximumNonAdjacentSum(n,arr);

}
