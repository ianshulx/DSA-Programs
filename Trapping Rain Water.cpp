class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=0;
        int right[n],left[n];
        for(int i=0;i<n;i++)
        {
            if(height[i]>l)
                l=height[i];
            left[i]=l;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>r)
                r=height[i];
            right[i]=r;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+min(right[i],left[i])-height[i];
        }
        return ans;
    }
};
