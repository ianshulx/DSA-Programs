//Problem 

Maximum of all subarrays of size k

Given an array and an integer K, find the maximum for each and every contiguous subarray of size K.

Examples : 

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: Maximum of 1, 2, 3 is 3
                       Maximum of 2, 3, 1 is 3
                       Maximum of 3, 1, 4 is 4
                       Maximum of 1, 4, 5 is 5
                       Maximum of 4, 5, 2 is 5 
                       Maximum of 5, 2, 3 is 5
                       Maximum of 2, 3, 6 is 6
  
  // code
  
import java.io.*;
import java.util.*;

class GFG {
	static class node {
		public int data;
		public int maximum;
		public node(int data, int maximum)
		{
			this.data = data;
			this.maximum = maximum;
		}
	}
	static void insert(Stack<node> s2, int val)
	{

		node other = new node(0, 0);
		other.data = val;

		if (s2.size() == 0)
			other.maximum = val;
		else {
			node front = s2.peek();
			other.maximum = Math.max(val, front.maximum);
		}
		s2.add(other);
		return;
	}

	static void delete(Stack<node> s1, Stack<node> s2)
	{
		if (!s1.empty())
			s1.pop();
		else {
			while (!s2.empty()) {
				node val = s2.peek();
				insert(s1, val.data);
				s2.pop();
			}
			s1.pop();
		}
	}

	static int get_max(Stack<node> s1, Stack<node> s2)
	{
		int ans = -1;
		if (s1.size() > 0)
			ans = Math.max(ans, s1.peek().maximum);
		if (s2.size() > 0)
			ans = Math.max(ans, s2.peek().maximum);
		return ans;
	}

	static ArrayList<Integer> slidingMaximum(int a[], int b,
											int N)
	{
		ArrayList<Integer> ans = new ArrayList<>();
		Stack<node> s1 = new Stack<>(), s2 = new Stack<>();

		for (int i = 0; i < b - 1; i++)
			insert(s2, a[i]);

		for (int i = 0; i <= N - b; i++) {
			// removing the last element of previous
			// window as window has shift by one
			if (i - 1 >= 0)
				delete(s1, s2);

			insert(s2, a[i + b - 1]);

			ans.add(get_max(s1, s2));
		}
		return ans;
	}

	public static void main(String args[])
	{
		int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
		int N = arr.length;
		int K = 4;
	
		// Function call
		ArrayList<Integer> ans = slidingMaximum(arr, K, N);
		for (int x : ans) {
			System.out.printf("%d ", x);
		}
	}
}



