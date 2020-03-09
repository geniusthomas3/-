#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main(){
    int n;
    int cnt=0;
    char str[100001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        stack<char> sta;
        int len=strlen(str);
        for(int j=0;j<len;j++){
            if(!sta.empty()&&str[j]==sta.top()){
                sta.pop();
            }
            else{
                sta.push(str[j]);
            }
        }
        if(sta.empty()) cnt++;
    }
    printf("%d",cnt);
}
