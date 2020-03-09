#include <stdio.h>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

stack<int> sta;
vector<pair<int,int>> cor;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

int main()
{
    int n;
    int cnt=0;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        cor.push_back(make_pair(a,b));
    }
    sort(cor.begin(),cor.end(),compare);
    cor.push_back(make_pair(0,0));
    for(int i=0;i<=n;i++){
        if(sta.empty()||sta.top()<cor[i].second){
            sta.push(cor[i].second);
        }
        else{
            while(!sta.empty()&&sta.top()>cor[i].second){
                sta.pop();
                cnt++;
            }
            if(!sta.empty()&&sta.top()==cor[i].second){
                sta.pop();
            }
            sta.push(cor[i].second);
        }
    }
    printf("%d",cnt);
    return 0;
}
