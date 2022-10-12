Find a triplet with the given sum in an array

Given an unsorted integer array, find a triplet with a given sum in it.
nums = [ 2, 7, 4, 0, 9, 5, 1, 3 ]
target = 6
  
//code

  class Main
{
    public static boolean isTripletExist(int[] nums, int n, int target, int count)
    {
       
        if (count == 3 && target == 0) {
            return true;
        }
 
       
        if (count == 3 || n == 0 || target < 0) {
            return false;
        }
 
        
        return isTripletExist(nums, n - 1, target - nums[n - 1], count + 1) ||
                        isTripletExist(nums, n - 1, target, count);
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 2, 7, 4, 0, 9, 5, 1, 3 };
        int target = 6;
 
        if (isTripletExist(nums, nums.length, target, 0)) {
            System.out.println("Triplet exists");
        }
        else {
            System.out.println("Triplet doesn't exist");
        }
    }
}
