import java.io.*;
import java.util.*;
 
/* Returns the best obtainable price for a rod of length n
and price[] as prices of different pieces */
class dp10 {
  private static int cutRod(int price[], int index, int n,
                            int[][] dp)
  {
     
    // base case
    if (index == 0) {
      return n * price[0];
    }
 
    if (dp[index][n] != -1) {
      return dp[index][n];
    }
 
    // At any index we have 2 options either
    // cut the rod of this length or not cut
    // it
    int notCut = cutRod(price, index - 1, n, dp);
    int cut = Integer.MIN_VALUE;
    int rod_length = index + 1;
 
    if (rod_length <= n) {
      cut = price[index]
        + cutRod(price, index, n - rod_length,
                 dp);
    }
 
    return dp[index][n] = Math.max(cut, notCut);
  }
 
  /* Driver program to test above functions */
  public static void main(String[] args)
  {
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = arr.length;
    int dp[][] = new int[size][size + 1];
    for (int i = 0; i < size; i++) {
      Arrays.fill(dp[i], -1);
    }
    System.out.println(
      "Maximum Obtainable Value is "
      + cutRod(arr, size - 1, size, dp));
  }
}