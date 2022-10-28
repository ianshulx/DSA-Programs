class Solution {
public:
    // int solve(vector<int>&A,int i,bool buy,vector<vector<int>>&dp)
    // {
    //     if(i==A.size())
    //         return 0;
    //     if(dp[i][buy]!=-1)
    //         return dp[i][buy];
    //     if(buy) //either buy or not buy 
    //         return dp[i][buy] = max(-A[i]+solve(A,i+1,false,dp),solve(A,i+1,true,dp));
    //     else //already holding...so sell or not sell
    //         return dp[i][buy] = max(A[i]+solve(A,i+1,true,dp),solve(A,i+1,false,dp));
    // }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2));
        // return solve(prices,0,true,dp); //0 is starting index....true is for buy
        vector<int>prev(2),curr(2);
        prev[0] = 0;
        prev[1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                    curr[buy] = max(-prices[i]+prev[0],prev[1]);
                else
                    curr[buy] = max(prices[i]+prev[1],prev[0]);
            }
            prev = curr;
        }
        return prev[1];
    }
};