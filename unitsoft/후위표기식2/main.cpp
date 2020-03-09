#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

char cal[60];
double arr[26];
stack<double> sta;
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",cal);
    for(int i=0;i<n;i++){
        scanf("%lf",arr+i);
    }
    int k=strlen(cal);
    for(int i=0;i<k;i++){
        if(65<=int(cal[i])&&int(cal[i])<=90){
            sta.push(arr[int(cal[i])-65]);
        }
        else{
            double a,b;
            b=sta.top();
            sta.pop();
            a=sta.top();
            sta.pop();
            if(cal[i]==42){
                sta.push(a*b);
            }
            else if(cal[i]==47){
                sta.push(a/b);
            }
            else if(cal[i]==45){
                sta.push(a-b);
            }
            else if(cal[i]==43){
                sta.push(a+b);
            }
        }
    }
    printf("%.2f",sta.top());
    return 0;
}
