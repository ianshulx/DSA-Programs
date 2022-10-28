#include<iostream>
using namespace std;

int sum(int n){
    if(n==0) 
        return 0;

    return sum(n-1)+n;    
}

int Isum(int n){
    int s=0;
    for(int i=0;i<=n;i++){
        s+=i;
    }
    return s;
}

int BestApproach(int n){
    return n*(n+1)/2;
}

int main(){
    int r,num;
    cout<<"Enter Number";
    cin>>num;
    r=BestApproach(num);

    cout<<r<<" ";
    return 0;
}
