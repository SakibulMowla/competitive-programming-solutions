#include <stdio.h>
#include <math.h>

#define max 1010

int arr[max],prime[max],task[100000];
int k;

void sieve(void)
{
    int i,j;
    arr[0]=arr[1]=1;

    for(i=4; i<max; i+=2)
        arr[i]=1;
    for(i=3; i<sqrt(max); i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i; j<max; j+=i+i)
                arr[j]=1;
        }
    }
    prime[0]=2;
    k=1;
    for(i=3; i<max; i+=2)
        if(arr[i]==0)
            prime[k++]=i;

    return;
}

void a_task(void)
{
    long long i,j,p,sum,power;
    for(i=1; i<max ; i++)
    {
        sum=1;
        p=i;
        for(j=0; prime[j]<=p &&p!=1 && j<k; j++)
        {
            power=1;
            if(p%prime[j]==0)
            {
                while(p%prime[j]==0)
                {
                    ++power;
                    p/=prime[j];
                }
                sum*=(pow(prime[j],power)-1)/(prime[j]-1);
            }
        }
        task[sum]=i;
    }
    return;
}

int main()
{
    sieve();
    a_task();
    int i,num;
    i=0;
    while(scanf("%d",&num)==1 && num)
    {
        if(task[num]==0)
            printf("Case %d: -1\n",++i);
        else
            printf("Case %d: %d\n",++i,task[num]);
    }
    return 0;
}
