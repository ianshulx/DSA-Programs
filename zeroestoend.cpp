/* 30-08-2022 */
#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}

for(int i=0; i<n; i++){
int j=i;
if(arr[i]==0){
    while(arr[j]==0 && j<n-1){
        j++;
    }
arr[i] = arr[j];
arr[j] = 0;
}

}

for (int  i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}


    return 0;
}