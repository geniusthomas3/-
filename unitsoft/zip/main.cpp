#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main(){
    char n[52];
    scanf("%s",&n);
    int len=strlen(n);
    int p,q;
    stack<char> sta;
    for(int i=0;i<len;i++){
        if(n[i]=='('){
            sta.push(n[i]);
        }
        else if(n[i]==')'){
            int j;
            for(j=0;sta.top()!='(';j++){
                sta.pop();
            }
            sta.pop();
            q=sta.top()-'0';
            sta.pop();
            for(int k=0;k<j*q;k++){
                sta.push('0');
            }
        }
        else{
            sta.push(n[i]);
        }
    }
    printf("%d",sta.size());
}
