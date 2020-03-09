#include <iostream>
#include <algorithm>

using namespace std;

int n;
typedef pair<int,int> p;
p time[100000];

bool compare(p a,p b)
{
    return (a.second<b.second);
}

int main()
{
    scanf("%d",&n);
    int s,e;
    for(int i=0;i<n+1;i++){
        scanf("%d %d",s,e);
        time[i].first=s;
        time[i].second=e;
    }
    sort(time,time+n,compare);
    for(int i=0;)
    {
        time[i].second<
    }
    printf("%d",sum);
}
