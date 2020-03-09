#include <stdio.h>
#include <vector>
#include <algorithm>

int arr[1000][1000];
int n,m;
int a,b;

using namespace std;

vector<int> v[1000];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        v[a-1].push_back(b);
        if(a==b)continue;
        v[b-1].push_back(a);
    }
    for(int i=0;i<n;i++){
        printf("%d",i+1);
        sort(v[i].begin(),v[i].end());
        for(auto x: v[i]){
            printf(" - %d",x);
        }
        printf("\n");
    }
}
