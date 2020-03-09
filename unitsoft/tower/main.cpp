#include <stdio.h>
#include <stack>
#define MAX (100000000)

using namespace std;

stack<int> ind;
stack<int> height;

int main()
{
    int n;
    scanf("%d",&n);
    ind.push(0);
    height.push(MAX);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        while(height.top()<t){
            height.pop();
            ind.pop();
        }
        printf("%d ",ind.top());
        height.push(t);
        ind.push(i);
    }
    return 0;
}
