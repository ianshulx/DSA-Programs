#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    int max = 1,max_i=0 ;    
    for(int i=0;i<s.size();i++)
    {
        int l=i-1;
        int r = i+1;
        while(l>=0 && r<s.length())
        {
            if(s[l]==s[r])
            {
             if(max < (r-l+1))
             {
                max = r-l+1 ;
                 max_i= l;
             }
              l--;
              r++; 
            }
            else
                break;
        }
    }  
     for(int i=0;i<s.size();i++)
    {
        int l=i;
        int r = i+1;
        while(l>=0 && r<s.size())
        {
            if(s[l]==s[r])
            {
             if(max < r-l+1)
             {
                max = r-l+1 ;
                 max_i= l;
             }
              l--;
              r++; 
            }
            else
                break;
        }
    }
   return s.substr(max_i,max);     
    }
};
int main(){
    Solution s ;
    string result= s.longestPalindrome("abababab");
     cout<<result ;
     return 0;
}