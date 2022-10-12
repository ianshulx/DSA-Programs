#include<stdio.h>
int main()
{
  int n;
  printf("Enter the Value of n:");
  scanf("%d",&n);
  int prime[n+1];
  
  for(int i=1;i<=n;i++)
  {
    prime[i]=i;
  }
  
  for(int i=2;i*i<=n;i++)
  {
    if(prime[i]!=-1)
    {
      for(int j=2*i;j<=n;j+=i)
      {
        prime[j]=-1;
      }
    }
  }
  printf("Prime Numbers till n are: \n");
  for(int i=2;i<=n;i++)
  {
    if (prime[i]!=-1)
    {
      printf("%d",i);
    }
  }
}
