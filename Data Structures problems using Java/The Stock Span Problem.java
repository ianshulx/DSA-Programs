// Problem

The Stock Span Problem

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of the stock’s price 
for all n days. The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the 
price of the stock on the current day is less than its price on the given day.
  
Example:

Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater 
than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.
  
// code
  
class GFG {
  
	static void calculateSpan(int A[],
							int n, int ans[])
	{
		ans[0] = 1;

		for (int i = 1; i < n; i++) {
			int counter = 1;
			while ((i - counter) >= 0 && A[i] >= A[i - counter]) {
				counter += ans[i - counter];
			}
			ans[i] = counter;
		}
	}

	static void printArray(int arr[], int n)
	{
		for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
	}

	public static void main(String[] args)
	{
		int price[] = { 10, 4, 5, 90, 120, 80 };
		int n = price.length;
		int S[] = new int[n];

		calculateSpan(price, n, S);

		printArray(S, n);
	}
}



