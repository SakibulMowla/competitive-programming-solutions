#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 47000
#define set(a,b) memset(a,b,sizeof(a))

bool arr[SZ];
vector <int> prime;
int cnt[SZ];

void sieve()
{
    int i,j;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

bool solve(int n,int m)
{
    int i,j,k;
    set(cnt,0);
    for(i=0;i<prime.size() && prime[i] <= n;i++)
    {
        j = n;
        while(j)
        {
            cnt[ prime[i] ] += j / prime[i];
            j /= prime[i];
        }
    }
    i = 0;
    while(prime[i] * prime[i] <= m)
    {
        while(m % prime[i] == 0)
        {
            cnt[ prime[i] ]--;
            m /= prime[i];
        }
        i++;
    }
    if(m != 1)
    {
        if(m > n) return false;
    }
    for(i=0;i<prime.size();i++)
    {
        if(cnt[i] < 0) return false;
    }
    return true;
}

int main()
{
    sieve();
    int n,m;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(m == 0 || n == 0)
        {
            printf("%d does not divide %d!\n",m,n);
            continue;
        }
        if(m <= n || m==1)
        {
            printf("%d divides %d!\n",m,n);
            continue;
        }
        if(solve(n,m)) printf("%d divides %d!\n",m,n);
        else printf("%d does not divide %d!\n",m,n);
    }

    return 0;
}
