#include <stdio.h>
#include <queue>

using namespace std;

queue<int> que;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        que.push(i);
    }
    int flag=1;
    for(;que.size()>1;){
        if(flag){
            que.pop();
            flag=0;
        }
        else{
            que.push(que.front());
            que.pop();
            flag=1;
        }
    }
    printf("%d",que.front());
    return 0;
}
