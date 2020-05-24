#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 1010

bool arr[SZ];
int prime[SZ];
int counter[SZ];

void sieve(void)
{
    int i,j,k;
    arr[0]=1;
    for(i=3;i<=sqrt(SZ);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<SZ;j+=i*2)
                arr[j]=1;
        }
    }
    prime[1]=1;
    prime[2]=2;
    k=3;
    counter[0]=0;
    counter[1]=1;
    counter[2]=2;

    for(i=3;i<SZ;i++)
    {
        if(i%2 == 0)
            counter[i]=counter[i-1];
        else if(arr[i] == 0)
        {
            prime[k++]=i;
            counter[i]=counter[i-1]+1;
        }
        else
            counter[i]=counter[i-1];
    }
}


int main()
{
    sieve();
    int n,c,i,j,num,start,count,mc;
    while(scanf("%d %d",&n,&c) == 2)
    {
        num=counter[n];
        mc=c;
        if(num%2 == 0)
            c=2*c;
        else
            c=(2*c)-1;
        printf("%d %d:",n,mc);
        if(c>num)
        {
            for(i=1;i<=num;i++)
                printf(" %d",prime[i]);
            printf("\n\n");
        }
        else
        {
            start=((num-c)/2)+1;
            for(i=start,count=0;count<c;count++,i++)
                printf(" %d",prime[i]);
            printf("\n\n");
        }
    }

    return 0;
}
