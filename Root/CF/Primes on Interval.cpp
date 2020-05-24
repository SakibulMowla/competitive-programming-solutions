#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 1000010

int arr[SZ];

void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=4;i<SZ;i+=2)
        arr[i] = 1;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;

    return;
}

int main()
{
    sieve();
    int i,j,k,l,a,b,x,y,flag,primes,ans;
    while(scanf("%d %d %d",&a,&b,&k) == 3)
    {
        ans = -1;
        flag = 0;
        for(l=1;l<=b-a+1;l++)
        {

            for(x=a;x<=b-l+1;x++)
            {
                primes = 0;
                for(y=x;y<x+l;y++)
                    if(arr[y] == 0)
                        primes++;
                if(primes >= k)
                {
                    flag = 1;
                    ans = l;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
