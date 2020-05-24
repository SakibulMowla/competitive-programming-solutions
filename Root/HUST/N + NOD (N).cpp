#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

#define SZ 1000010

bool arr[SZ];

vector <int> prime;

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
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int div_cnt[SZ];

void divisors()
{
    int i,j,n,cnt,div;
    for(i=1;i<SZ;i++)
    {
        n = i;
        div = 1;
        for(j=0;prime[j]<=sqrt(n) && n!=1;j++)
        {
            if(n % prime[j] == 0)
            {
                cnt = 1;
                while(n % prime[j] == 0)
                {
                    cnt++;
                    n /= prime[j];
                }
                div *= cnt;
            }
        }
        if(n != 1) div *= 2;
        div_cnt[i] = div;
    }
}

int NOD[SZ];

void n_nod()
{
    int i,j,k,num,prenum=1;
    NOD[1] = 1;
    while(num < SZ)
    {
        num = prenum + div_cnt[prenum];
        if(num >= SZ)break;
        NOD[num] = 1;
        prenum = num;
    }
    for(i=1;i<SZ;i++)
    {
        NOD[i] = NOD[i] + NOD[i-1];
    }
    printf("zed\n");
}

int main()
{
    sieve();
    divisors();
    n_nod();
    int i,num,prenum=1,test,t=0,a,b;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",++t,NOD[b]-NOD[a-1]);
    }

    return 0;
}
