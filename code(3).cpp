#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    if(n%7==0){cout<<n<<endl; continue;}
	    int rem=n/10;
	    rem*=10;
	    for(int i=0;i<10;i++){
	        if((rem+i)%7==0) {cout<<rem+i<<endl; break;}
	        
	    }
	}
	return 0;
}
