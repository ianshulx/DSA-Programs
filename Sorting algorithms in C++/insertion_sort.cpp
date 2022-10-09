#include<iostream>
using namespace std;
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertion(int a[], int n)
{
    for ( int j = 2; j < n; j++)
    {
        int key=a[j];
        int i=j-1;
        while (i>=0 && a[i]>key){
            a[i+1]=a[i];
            i=i-1;

        }
        a[i+1]=key;
        
    }
    
}

int main(){
int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertion(data, size);
  cout << "Sorted array in ascending order:\n";
  printArray(data, size);
}