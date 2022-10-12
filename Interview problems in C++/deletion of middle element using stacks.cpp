#include <iostream>
#include <stack>
using namespace std;
void deletemiddle(stack <int> &input,int count,int size){
    if(count==size/2){
        input.pop();
        return;
    }
    int num=input.top();
    input.pop();
    deletemiddle(input,count+1,size);
    input.push(num);


}

int main()
{
    stack <int> st;

    st.push(2);
    st.push(5);
    st.push(8);
    st.push(1);
    st.push(3);
    st.push(9);
    int s=st.size();
    deletemiddle(st,0,s);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
