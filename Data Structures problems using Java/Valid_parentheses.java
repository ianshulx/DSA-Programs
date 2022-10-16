/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
   An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
 
    Example 1:
    Input: s = "()"
    Output: true
    
    Example 2:
    Input: s = "(]"
    Output: false*/

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st=new Stack<>();
        for(int i=0;i<s.length();i++)
        {
            char c=s.charAt(i);
            if(!st.isEmpty() && (st.peek()==c-1 || st.peek()==c-2)) // check ascii diff. =1or 2
                st.pop();
            else st.push(c);
        }
        if(st.isEmpty()) return true; // valid parenthesis
        return false;
    }
}
