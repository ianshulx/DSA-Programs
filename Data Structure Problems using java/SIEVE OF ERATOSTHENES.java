SIEVE OF ERATOSTHENES

//code 

class Solution {
  public static void printPrimes(int n) {

    if (n <= 2) return;
    boolean prime[] = new boolean[n];

    Arrays.fill(prime, true);

    for (int i = 2; i * i < n; i++) {
      if (prime[i]) {

        for (int j = i; j * i < n; j++) {
          prime[j * i] = false;
        }

      }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
      if (prime[i])
        System.out.print(i + "  ");
      count++;
      if (count % 10 == 0)
        System.out.println();
    }
  }
  public static void main(String args[]) {
    printPrimes(100);
  }
}
