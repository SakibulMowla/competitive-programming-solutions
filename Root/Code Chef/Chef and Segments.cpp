#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

ll BIGMOD(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 100010

int arr[SZ][28];
bool col[110];
vector <ll> prime;

void sieve_of_erastothenes(){int i, j;for(i=3; i<=10; i+=2)if(!col[i])for(j=i*i; j<=100; j+=i+i)col[j] = 1;prime.push_back(2LL);for(i=3; i<100; i+=2)if(!col[i])prime.push_back(i);}

int tmp[110][30];

int main()
{
    sieve_of_erastothenes();

    int n, i, j, k, l, t;
    ll answer;

    for(i=1; i<=100; i++)
    {
        j = i;
        for(k=0; k<25; k++)
        {
            if(j % prime[k] == 0)
            {
                l = 0;
                while(j % prime[k] == 0)
                {
                    j /= prime[k];
                    l++;
                }
                tmp[i][k] += l;
            }
        }
    }

    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&j);
        for(k=0; k<25; k++)
            arr[i][k] = arr[i-1][k] + tmp[j][k];
    }

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&i);scanf("%d",&j);scanf("%d",&k);
        answer = 1LL;

        for(l=0; l<25; l++)
            answer = ( answer * BIGMOD( prime[l], (ll)(arr[j][l] - arr[i-1][l]), (ll)k ) ) % (ll)k;

        printf("%lld\n",answer);
    }

    return 0;
}
