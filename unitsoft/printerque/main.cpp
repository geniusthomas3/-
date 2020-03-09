#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;

int arr[100];

int main()
{
    int a;
    int n,m;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d %d",&n,&m);
        queue<pair<int,int>> q;
        priority_queue<int> que;
        int tmp,r=0;
        for(int j=0;j<n;j++){
            scanf("%d",&tmp);
            pair<int,int> p=make_pair(tmp,j);
            q.push(p);
            que.push(tmp);
        }
        pair<int,int> p;
        for(;!q.empty();){
            p=q.front();
            q.pop();
            if(p.first==que.top()){
                r++;
                que.pop();
                if(m==p.second){
                    printf("%d\n",r);
                    break;
                }
            }
            else{
                q.push(p);
            }
        }
    }
    return 0;
}
