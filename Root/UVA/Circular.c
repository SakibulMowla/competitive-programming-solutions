#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[1000010],prime[1000020];
int len,count,multiplier;

void sieve(void)
{
    int i,j;
    arr[0]=arr[1]=1;
    for(i=4;i<1000010;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(1000010);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<1000010;j+=i*2)
                arr[j]=1;
        }
    }
    return;
}

void circular(int n)
{
    int i;
    i=n%10;
    n/=10;
    n=(multiplier*i)+n;
    if(arr[n]==0)
    {
        count++;
        if(count<len)
            circular(n);
    }
    return;
}
int main()
{
    sieve();
    int i,j,n,m,k;
    char p[10];
    for(i=100;i<1000001;i++)
    {
        if(arr[i]==0)
        {
            len=sprintf(p,"%d",i);
            multiplier=100;
            for(j=3;j<len;j++)
                multiplier*=10;
            count=1;
            circular(i);
            if(count==len)
                prime[i]=prime[i-1]+1;

            else
                prime[i]=prime[i-1];
        }
        else
        {
            prime[i]=prime[i-1];
        }
    }
    while(scanf("%d",&n)==1 && n!=-1)
    {
        scanf("%d",&m);
        k=prime[m]-prime[n-1];
        if(k==0)
            printf("No Circular Primes.\n");
        else if(k==1)
            printf("1 Circular Prime.\n");
        else
            printf("%d Circular Primes.\n",k);
    }

    return 0;
}
