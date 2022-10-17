#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int a[],int size)
{
    for(int i=0;i< size-1;i++)
    {
      for(int j= 0; j < size-i-1 ;j++)
      {
          if(a[j] > a[j+1])
          {
              int temp = a[j];
              a[j] = a[j+1];
              a[j+1] = temp;
          }
      }
    }
 }     
   

int main()
{
    int size,a[100];
    cin >> size;
    for(int i=0;i<size;i++) cin>> a[i];
    bubbleSort(a,size);
    for(int i=0;i<size;i++) cout<< a[i]<< " ";
    return 0;
}
