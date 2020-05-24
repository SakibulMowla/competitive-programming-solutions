#include <stdio.h>
#include <string.h>
#include <math.h>

#define max 23200
#define ll long long

ll arr[max],prime[10000];
ll k;
void sieve(void)
{
    ll i,j;
    prime[0]=2;
    k=1;
    for(i=3; i<max; i++)
    {
        if(arr[i]==0)
        {
            prime[k++]=i;
            for(j=i*i; j<max; j+=i+i)
            {
                arr[j]=1;
            }
        }
    }
    arr[0]=arr[1]=1;
    for(i=4;i<50;i+=2)
        arr[i]=1;
    return;
}

int main()
{
    sieve();
    ll n,m,i,flag1,flag2,j,val;
    char line[100],z;
    scanf("%lld",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld%c",&m,&z);
        flag1=0;
        flag2=1;
        if(arr[m]==0)
        {
            flag1=1;
            val=pow(2,m)-1;

            for(j=0;j<k && prime[j]<val;j++)
            {
                if(val % prime[j] == 0)
                {
                    flag2=0;
                    break;
                }
            }
        }
        if(flag1==1 && flag2==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
