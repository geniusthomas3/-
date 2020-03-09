#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    cin>>str;
    stack<char> st;
    int result=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(') st.push(str[i]);
        else{
            st.pop();
            if(str[i-1]=='(') result+=st.size();
            else result++;
        }
    }
    printf("%d",result);
    return 0;
}
