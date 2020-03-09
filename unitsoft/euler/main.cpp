#include <stdio.h>
int a,n,arr[1000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            arr[i]+=a;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2) cnt++;
    }
    if(cnt==0||cnt==2){
        printf("YES");
        return 0;
    }
    printf("NO");
}
