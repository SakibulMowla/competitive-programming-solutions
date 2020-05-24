#include <stdio.h>
#include <math.h>

int arr[1000010],prime[1000010];
void sieve(void)
{
    int i,j,c;
    arr[0]=arr[1]=1;
    prime[0]=2;
    c=1;
    for(i=4;i<1000010;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(1000010);i+=2)
    {
        if(arr[i]==0)
        {
            prime[c++]=i;
            for(j=i*i;j<1000010;j+=i*2)
                arr[j]=1;
        }
    }
    for(i=sqrt(1000010);i<1000010;i++)
    {
        if(arr[i]==0)
            prime[c++]=i;
    }
    return;
}

void primary(int n)
{
    int i,j=0;
    for(i=0;prime[i]<=n/2;i++)
    {
        if(arr[n-prime[i]]==0)
        {
            j=1;
            printf("%d:\n",n);
            printf("%d+%d\n",prime[i],n-prime[i]);
            break;
        }
    }
    if(j==0)
    {
        printf("%d:\n",n);
        printf("NO WAY!\n");
    }
    return;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        primary(n);
    }
    return 0;
}
