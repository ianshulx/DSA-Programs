class Solution {
public:
    int solve(vector<int>&A,int i,int tran,vector<vector<int>>&dp)
    {
        if(i==A.size())
            return 0;
        if(tran==4)
            return 0;
        if(dp[i][tran]!=-1)
            return dp[i][tran];
        if(tran%2==0) //even then buy
            return dp[i][tran]=max(-A[i]+solve(A,i+1,tran+1,dp),solve(A,i+1,tran,dp)); //buy or not buy
        else
            return dp[i][tran]=max(A[i]+solve(A,i+1,tran+1,dp),solve(A,i+1,tran,dp)); //sell or not sell
    }
    int maxProfit(vector<int>& A) 
    {
        int n = A.size();
        // vector<vector<int>>dp(n,vector<int>(4,-1));
        //at most 2 transactions...we don't want to have a diff variable for buy and tran
        //as it would make a 3d dp....so we will use tran only
        //we will treat each buy as well as each sell as a tran
        //so total 2*2 = 4 transactions
        // return solve(A,0,0,dp); //starting index  0 and tran 0
        
        // vector<vector<int>>dp(n+1,vector<int>(4+1));
        vector<int>prev(5,0),curr(5,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int tran=3;tran>=0;tran--)
            {
                if(tran%2==0) //even then buy
                    curr[tran]=max(-A[i]+prev[tran+1],prev[tran]);
                else
                    curr[tran]=max(A[i]+prev[tran+1],prev[tran]); 
            }
            prev = curr;
        }
        return prev[0];
    }
};