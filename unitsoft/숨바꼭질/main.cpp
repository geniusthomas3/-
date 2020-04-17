#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

queue <pair<int,int>> que;

int n,k;
int flag[100001];

int main(){
    scanf("%d %d",&n,&k);
    que.push(make_pair(n,0));
    for(;;){
        pair<int,int> x=que.front();
        que.pop();
        if(x.first==k){
            printf("%d",x.second);
            break;
        }
        if(x.first<=99999&&x.first>=-1&&flag[x.first+1]==0){
            que.push(make_pair(x.first+1,x.second+1));
            flag[x.first+1]=1;
        }
        if(x.first<=100001&&x.first>=1&&flag[x.first-1]==0){
            que.push(make_pair(x.first-1,x.second+1));
            flag[x.first-1]=1;
        }
        if(2*x.first<=100000&&x.first>=0&&flag[x.first*2]==0){
            que.push(make_pair(x.first*2,x.second+1));
            flag[x.first*2]=1;
        }

    }
}
