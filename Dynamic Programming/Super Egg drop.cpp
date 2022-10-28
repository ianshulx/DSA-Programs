class Solution {
public:
    int t[101][10001];
    int solve(int k,int n)
    {
        if(n==0||n==1)
            return n;
        if(k==1)
            return n;
        if(t[k][n]!=-1)
            return t[k][n];
        int mn=INT_MAX,low=1,high=n;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int left = solve(k-1,mid-1);
            int right = solve(k,n-mid);
            int temp = 1+max(left,right);
            mn = min(temp,mn);
            if(left<right)
                low = mid+1;
            else
                high = mid-1;
        }
        return t[k][n]=mn;
    }
    int superEggDrop(int k, int n) 
    {
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }
};