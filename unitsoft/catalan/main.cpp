#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    int n;
    int arr[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    stack<int> sta;
    int max=0;
    for(int i=0;i<n;i++){
        if(!sta.empty()&&arr[i]==sta.top()){
            sta.pop();
        }
        else if(arr[i]>max){
            for(int j=max+1;j<=arr[i];j++){
                sta.push(j);
            }
            sta.pop();
        }
        else if(arr[i]<max){
            printf("NO");
            return 0;
        }
        if(arr[i]>max) max=arr[i];
    }
    printf("YES");
}
