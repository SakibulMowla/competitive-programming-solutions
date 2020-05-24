#include "stdio.h"
#include "math.h"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 1000010
typedef long long ll;

template <class T> T GCD(T a,T b)
{
    T c;
    while(b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

template <class T> T LCM(T a,T b)
{
    return (a*b)/GCD(a,b);
}

bool arr[SZ];
vector <ll> prime;

void sieve()
{
    ll i,j,k;
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
        {
            prime.push_back(i);
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
        }
}

int main()
{
    sieve();
    ll t=0,test,a,b,c,l,l1,ans,i,cnta,cntb,cntl;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld %lld",&a,&b,&l);
        l1 = LCM(a,b);
        printf("Case %lld: ",++t);
        ans = 1;
        if(l % l1) printf("impossible\n");
        else
        {
            for(i=0;i<prime.size() && l>1;i++)
            {

                cnta = 0;
                while(a % prime[i] == 0) cnta++ , a /= prime[i];
                cntb = 0;
                while(b % prime[i] == 0) cntb++ , b /= prime[i];
                cntl = 0;
                while(l % prime[i] == 0) cntl++ , l /= prime[i];
                c = cnta > cntb ? cnta : cntb;
                if(c != cntl) ans *= pow(prime[i],cntl);
            }
            printf("%lld\n",ans);
        }
    }

    return 0;
}
