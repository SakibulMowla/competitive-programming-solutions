//c = ab - (a+b)/2 + 1
//c = (2ab - a - b)/2 + 1
//c = (4ab - 2a - 2b)/4 + 1/4 + 3/4
//c = (4ab - 2a - 2b + 1)/4 + 3/4
//c = (2a(2b-1) - 1(2b-1))/4 + 3/4
//c = (2b-1)(2a-1)/4 + 3/4
//c - 3/4= (2b-1)(2a-1)/4
//4c - 3 = (2b-1)(2a-1)
//
//So the number of solutions is the number of divisors of (4c-3)

#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define SZ 20000000

bool arr[SZ];
int prime[(SZ)/10];
int cnt;

void sieve(){
    int i, j, k;

    k = sqrt(SZ);

    for(i=3;i<=k;i++)
        if(!arr[i])
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;

    cnt = 0;
    prime[cnt++] = 2;

    for(i=3;i<SZ;i+=2)
        if(!arr[i])
            prime[cnt++] = i;
}

ll NOD(ll n){
    int i, j;
    ll ans;

    ans = 1LL;

    for(i=0;i<cnt && (ll)((ll)prime[i]*(ll)prime[i]) <= n;i++){
        if(n%prime[i] == 0){
            j = 1;
            while(n%prime[i] == 0){
                j++;
                n /= prime[i];
            }
            ans *= (ll)j;
        }
    }

    if(n != 1)
        ans *= 2LL;

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    sieve();
    ll n;

    while(scanf("%lld",&n)==1 && n)
        printf("%lld %lld\n",n,NOD(4LL*n-3LL));

    return 0;
}












