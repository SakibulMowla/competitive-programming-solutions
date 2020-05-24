#include "stdio.h"
#include "vector"
#include "map"
#include "iostream"
#include "math.h"

using namespace std;

#define SZ 1000010
#define sz(a) ((int)a.size())

int arr[SZ];
vector <int> prime;
map <int , int> M;
map <int , int>::iterator it;

void sieve()
{
    int i, j;
    for(i=4; i<SZ; i+=2)
        arr[i] = 1;
    arr[0] = arr[1] = 1;
    for(i=3; i<=sqrt(SZ); i+=2)
        if(!arr[i])
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3; i<SZ; i+=2)
        if(!arr[i])
            prime.push_back(i);
}

void factorize(int n)
{
    int i, j, k;
    k = sz(prime);
    for(i=0; i<k && n!=1 && prime[i]*prime[i]<=n ; i++)
    {
        if(n%prime[i] == 0)
        {
            j = 0;
            while(n%prime[i] == 0)
            {
                j++;
                n /= prime[i];
            }
            if(M.find(prime[i]) == M.end())
                M[ prime[i] ] = j;
            else
                M[ prime[i] ] += j;
        }
    }

    if(n != 1)
    {
        if(M.find(n) == M.end())
            M[n] = 1;
        else M[n]++;
    }
}

int main()
{
    sieve();

    int t, n, k;
    long long ans;

    scanf("%d",&t);

    while(t--)
    {
        M.clear();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&k);
            factorize(k);
        }

        ans = 1LL;

        for(it=M.begin(); it!=M.end(); it++)
            ans = ans * (long long) ((it->second)+1LL);

        printf("%lld\n",ans);
    }

    return 0;
}
