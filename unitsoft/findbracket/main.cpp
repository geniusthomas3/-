#include <stdio.h>
#include <stack>
#include <string.h>
#include <utility>

using namespace std;

char formula[202];
int flag [202];
stack<int> brakets;

int main(){
    scanf("%s",formula);
    int len=strlen(formula);
    int cnt=1;
    for(int i=0;i<len;i++){
        if(formula[i]=='('){
            brakets.push(i);
        }
        else{
            if(brakets.empty()){
                printf("WRONG EXPRESSION");
                return 0;
            }
            flag[brakets.top()]=cnt;
            flag[i]=cnt++;
            brakets.pop();
        }
    }
    if(!brakets.empty()){
        printf("WRONG EXPRESSION");
        return 0;
    }
    for(int i=0;i<len;i++){
        printf("%d ",flag[i]);
    }
    return 0;
}
