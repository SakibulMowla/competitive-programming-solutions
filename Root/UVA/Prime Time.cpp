#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define max 40000

using namespace std;

bool arr[max];
int p_eular[10010],prime[12000];
int k;

void sieve(void)
{
    int i,j;
    prime[0]=2;
    arr[0]=arr[1]=1;
    k=1;
    for(i=3; i<max; i+=2)
    {
        if(arr[i]==0)
        {
            prime[k++]=i;
            for(j=i*i; j<max; j+=i*2)
                arr[j]=1;
        }
    }
    return;
}

int prime_check(int num)
{
    printf("num=%d  ",num);
    for(int i=0;prime[i]<=num && i<k;i++)
    {
       if(num%prime[i]==0)
          {printf("No\n");return 0;}
    }
    printf("yes\n");
    return 1;
}

void prime_time()
{
    int i,j,k;
    for( i=0,k=1; i<=40; i++,k++)
    {
        j=(i*i) + i + 41;
        if(prime_check(j))
            p_eular[k]=p_eular[k-1] + 1;
        else
            p_eular[k]=p_eular[k-1];
    }
    return;
}

int main()
{
    sieve();
    prime_time();
    int low,high;
    double right,total,ans;
    while(scanf("%d %d",&low,&high)==2)
    {
        ++low;
        ++high;
        total=high-low+1;
        right=p_eular[high]-p_eular[low-1];
        ans=(right/total)*100;
        printf("%.2lf\n",ans);
    }
    return 0;
}
