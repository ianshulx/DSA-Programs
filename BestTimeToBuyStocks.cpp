class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int profit=0;
        int cost=prices[0];
        int mx=0;
        int prev=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]>=prev)
            {
                mx=max(mx,prices[i]-cost);
                // cout<<"i"<<i<<endl;
            }
            else
            {
                // cout<<"i."<<i<<endl;
                // cout<<mx<<endl;
             profit+=(mx);
                mx=0;
                cost=prices[i];
            }
            prev=prices[i];
        }
        profit+=mx;
        return profit;
    }
};
