#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    int n,tmp;
    stack<int> sta;
    scanf("%d",&n);
    int max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        sta.push(tmp);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(max<sta.top()){
            cnt++;
            max=sta.top();
        }
        sta.pop();
    }
    printf("%d",cnt);
}
