#include <stdio.h>

int n,m,k;
int a[100][2];
int arr[100001];
int any[2][100001];
int flag[100001];
int tmp;
int ans=1;
int what=1;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int recur(int m,int n){
    flag[m]=1;
    if(arr[m]==n) return 1;
    else return recur(arr[m],n)+1;
}

int main()
{
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int j=0;j<m;j++){
        for(int i=a[j][0];2*i<=a[j][1]+a[j][0];i++){
            tmp=arr[i];
            arr[i]=arr[a[j][1]+a[j][0]-i];
            arr[a[j][1]+a[j][0]-i]=tmp;
        }
    }






    for(int i=1;i<=n;i++){
        if(flag[i]) continue;
        int abc=recur(i,i);
        ans=lcm(abc,ans);
    }
    for(int i=1;i<=n;i++){
        any[0][i]=i;
    }
    k=k%ans;
    for(int j=0;j<k;j++){
        for(int i=1;i<=n;i++){
            any[what][i]=any[!what][arr[i]];
        }
        what=!what;
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",any[!what][i]);
    }
    return 0;
}
