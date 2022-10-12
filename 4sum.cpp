class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    
    {
        sort(nums.begin(),nums.end());
        
    int n=nums.size();
        
        int i,j,k;
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                
              int j1=0,j2=n-1;
                
                
            while(j1<j2)
            {
                int sum=nums[i]+nums[j]+nums[j1]+nums[j2];
                if(j1==i||j1==j)
                {
                    j1++;
                }
                else if(j2==i||j2==j)
                {
                    j2--;
                }
                else if(sum>target)
                {
                    
                }
                
            }
            }
        }
    }
};
