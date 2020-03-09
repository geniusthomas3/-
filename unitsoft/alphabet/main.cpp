#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;
char arr[1000001];

int main()
{
    scanf("%s",arr);
    stack<char> sta;
    stack<char> org;
    for(int i=strlen(arr)-1;i>=0;i--){
        org.push(arr[i]);
    }
    int flag=0;
    for(;;){
        if(sta.empty()&&!(org.empty())){
            sta.push(org.top());
            org.pop();
        }
        else if(sta.empty()&&org.empty()){
            flag=1;
            break;
        }
        else if(!(sta.empty())&&org.empty()){
            flag=0;
            break;
        }
        else if(sta.top()==org.top()){
            sta.pop();
            org.pop();
        }
        else{
            sta.push(org.top());
            org.pop();
        }
    }
    if(flag) printf("1");
    else printf("0");
    return 0;
}
