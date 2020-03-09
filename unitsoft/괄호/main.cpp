#include <stdio.h>
#include <stack>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char arr[52];
    for(int i=0;i<n;i++){
        scanf("%s",arr);
        stack<int> sta;
        int flag=0;
        for(int j=0;arr[j]!=NULL;j++){
            if(arr[j]=='('){
                sta.push(1);
            }
            else{
                if(sta.empty()){
                    printf("NO\n");
                    flag=1;
                    break;
                }
                sta.pop();
            }
        }
        if(flag) continue;
        if(sta.empty()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
