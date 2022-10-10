Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Solution :
Time Complexity - O(logn) where n is the number of elements in the array.
  
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> res;
        int n = nums.size();
        int result = -1, low = 0, high = n-1;
        
        //finding first position
        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid] < target)
                low = mid +1;
            else
            if(nums[mid] > target)
                high = mid - 1;
			
            if(nums[mid] == target) 
            {   
                result = mid;

                // because nothing after mid can be the first occurance of target.
                // maybe mid is the first occurance , maybe not
                // so let's narrow the target for [0...mid-1] and find out
                high = mid - 1;
            }
        }
        res.push_back(result);
        result = -1, low = 0, high = n-1;
        
        //finding last position
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if (nums[mid] < target)
                low = mid +1;
            else 
            if (nums[mid] > target)
                high = mid - 1;
			
            if(nums[mid] == target) 
            {
                result = mid;
                
                // because nothing before mid can be the last occurance of target.
                // maybe mid is the last occurance , maybe not
                // so let's narrow the target for [mid+1...high]
                low = mid + 1;
            }
        }
        res.push_back(result);
        return res;
    }
};
