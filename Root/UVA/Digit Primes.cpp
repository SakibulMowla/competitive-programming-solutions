#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int arr[1000010],dp[1000010];
int digit_prime(int n)
{
    int i,len,sum;
    char p[100];
    len=sprintf(p,"%d",n);
    sum=0;
    for(i=0;i<len;i++)
        sum+=p[i]-'0';
    if(arr[sum])
        return 0;
    else
        return 1;
}
int main(void)
{
    int n,i,j,k,c;
    arr[0]=arr[1]=1;
    for(i=4;i<1000010;i+=2)
        arr[i]=1;
    for(i=3;i<=sqrt(1000010);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<1000010;j+=i*2)
                arr[j]=1;
        }
    }

    for(i=1;i<1000010;i++)
    {
        if(arr[i]==0 && digit_prime(i))
            dp[i]=dp[i-1]+1;
        else
            dp[i]=dp[i-1];
    }

    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        scanf("%d %d",&i,&j);
        c=dp[j]-dp[i-1];
        printf("%d\n",c);
    }

    return 0;
}
