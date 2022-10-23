static bool comp(pair<int,int>a, pair<int,int>b)
    {
        if(a.first > b.first)
            return false;
        if(a.first == b.first and a.second > b.second)
            return false;
        
        return true;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       vector<pair<int,int>> vp;
        
        for(int i=0;i<nums.size();i++)
        {
            vp.push_back(make_pair(nums[i],i));
        }
        
        sort(vp.begin(),vp.end(),comp);
       
        for(int i=0;i<vp.size()-1;i++)
        {
            if(vp[i].first == vp[i+1].first)
                if(abs(vp[i].second - vp[i+1].second) <= k)
                    return true;
        }
        
        return false;
    }
