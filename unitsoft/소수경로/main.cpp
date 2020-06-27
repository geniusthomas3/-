/*#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string>
using namespace std;


int check[100000];

int isprime(int a){
    for(int i=1;i*i<a;i++){
        if(!a%i) return 0;
    }
    return 1;
}

int to_int(string num){
    int ret = 0;
    for(int i=0; i<4; i++){
        ret = ret * 10 + (num[i] - '0');
    }
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        queue <int> que;
        que.push(a);
        check[a]=0;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int i=0; i<4; i++){
                string node_s = to_string(node);
                for(int j=0; j<10; j++){
                    node_s[i] = j + '0';
                    int next = to_int(node_s);
                    if(next >= 1000 && isprime(next) && check[next] == -1){
                        check[next] = check[node] + 1;
                        que.push(next);
                    }
                }
            }
        }
        if(check[b] != -1){
            printf("%d\n", check[b]);
        }
        else{
            printf("Impossible\n");
        }
    }
}*/
/*
#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std;

int check[10000];

int isprime(int a){
    for(int i=2;i*i<a;i++){
        if(a%i==0) return 0;
    }
    return 1;
}

int* ind(int a){
    static int ax[4];
    ax[0]=a/1000;
    ax[1]=a/100-ax[0]*10;
    ax[2]=(a%100-a%10)/10;
    ax[3]=a%10;
    return ax;
}

int rev(int * ax){
    return ax[0]*1000+ax[1]*100+ax[2]*10+ax[3];
}

int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        int cnt=0;
        scanf("%d %d",&a,&b);
        queue <int> que;
        que.push(a);
        check[a]=1;
        while(!que.empty()){
            int node=que.front();
            //printf("#%d#\n",node);
            que.pop();
            int *kx=ind(node);
            for(int i=0; i<4; i++){
                for(int j=0-kx[i]; j<=9-kx[i]; j++){
                    int *nx=ind(node);
                    if(j==0) continue;
                    if(i==0){
                        if(j+kx[i]==0)continue;
                    }
                    nx[i]+=j;
                    //printf("%d !!",nx[i]);
                    int next = rev(nx);
                    printf("#%d#\n",next);
                    if(isprime(next) && check[next] == 0){
                        check[next] = check[node] + 1;
                        que.push(next);
                        printf("!#%d#!\n",next);
                    }
                }
            }
        }
        if(check[b] != 0){
            printf("%d\n", check[b]);
        }
        else{
            printf("Impossible\n");
        }
    }
    return 0;
}
*/

#include <stdio.h>
#include <queue>

int isprime(int a){
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return 0;
    }
    return 1;
}

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,flag=0;
        int check[10000]={0,};
        scanf("%d %d",&a,&b);
        queue <int> que;
        que.push(a);
        check[a]=1;
        while(!que.empty()){
            int node=que.front();
            if(node==b){
                printf("%d\n",check[b]-1);
                flag=1;
                break;
            }
            int tmp;
            que.pop();
            for(int i=1;i<=9;i++){
                tmp=i*1000+node%1000;
                if(tmp==node) continue;
                ///||check[tmp]>check[node]+1)
                if(isprime(tmp)&&check[tmp]==0){
                    check[tmp]=check[node]+1;
                   /// printf("#%d, %d# ",tmp,check[node]);
                    que.push(tmp);
                }
            }
            for(int i=0;i<=9;i++){
                tmp=i*100+node%100+node/1000*1000;
                if(tmp==node) continue;
                if(isprime(tmp)&&(check[tmp]==0)){
                    check[tmp]=check[node]+1;
                    ///printf("#%d, %d# ",tmp,check[node]);
                    que.push(tmp);
                }
            }
            for(int i=0;i<=9;i++){
                tmp=i*10+node%10+node/100*100;
                if(tmp==node) continue;
                if(isprime(tmp)&&(check[tmp]==0)){
                    check[tmp]=check[node]+1;
                    ///printf("#%d, %d# ",tmp,check[node]);
                    que.push(tmp);
                }
            }
            for(int i=0;i<=9;i++){
                tmp=i+node/10*10;
                if(tmp==node) continue;
                if(isprime(tmp)&&(check[tmp]==0)){
                    check[tmp]=check[node]+1;
                    ///printf("#%d, %d# ",tmp,check[node]);
                    que.push(tmp);
                }
            }
        }
        if(!flag) printf("Impossible\n");
    }
}
