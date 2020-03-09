#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

stack<char> brak;
int main(){
    char bracket[1000001];
    scanf("%s",bracket);
    int len=strlen(bracket);
    int flag=0,isopen=0;
    for(int i=0;i<len;i++){
        if(bracket[i]=='('){
            brak.push(bracket[i]);
        }
        if(bracket[i]=='['){
            brak.push(bracket[i]);
        }
        if(bracket[i]==')'){
            if(brak.empty()){
                flag=1;
                break;
            }
            if(brak.top()=='('){
                brak.pop();
            }
            else{
                flag=1;
                break;
            }
        }
        if(bracket[i]==']'){
            if(brak.empty()){
                flag=1;
                break;
            }
            if(brak.top()=='['){
                brak.pop();
            }
            else{
                flag=1;
                break;
            }
        }
    }
    if(flag==0&&brak.empty()) printf("YES");
    else printf("NO");
}
