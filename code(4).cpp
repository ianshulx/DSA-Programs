#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    string n;
	    cin>>n;
	    long long ones=0, zeroes=0;
	    for(char ch: n){
	        if(ch=='1') ones++;
	        else zeroes++;
	    }
	    if(ones==0||zeroes==0) {cout<<0<<endl; continue;}
	    if(ones<zeroes) {cout<<ones<<endl;}
	    else if(zeroes<ones){ cout<<zeroes<<endl; continue;}
	    else{
	       // if(n[0]==n[n.size()-1]){
	       //     cout<<ones-1<<endl;
	       // }
	       // else{
	            
	       // }
	       cout<<ones-1<<endl;
	    }
	}
	return 0;
}
