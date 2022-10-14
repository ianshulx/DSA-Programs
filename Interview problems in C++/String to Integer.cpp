// implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// Read in and ignore any leading whitespace.
// Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// Return the integer as the final result.

class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        
        //ignoring leading white spaces
        while(i<s.length() && s[i]==' ') i++;
        
        //after ignoring the white spaces retreiving the remaining string
        s=s.substr(i);//it will go till i to i.size()
        int sign=+1;
        long ans=0;
        
        if(s[0]=='-') sign = -1;
        
        int maxi=INT_MAX, mini=INT_MIN;

        //if there is a sign at the start index will start from 1 as 0th index will be a sign and if there is no sign index will start from 0
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        
        //traversing through the remaining string
        while(i < s.length()){
            //if a space or a non digit character is encountered then break
            if(s[0] == ' ' || !isdigit(s[i])) break;
            //including the valid string chars in the ans
            ans = ans*10+s[i] - '0';
            
            if(sign == -1 && -1*ans < mini) return mini;
            if(sign == +1 && ans > maxi) return maxi;
            
            i++;
        }
        return (int)(sign*ans);
    }
};
