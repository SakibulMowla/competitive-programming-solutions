//ACed

#include <bits/stdc++.h>
using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 31622+1000

bool arr[SZ];
vector <int> prime;
ll a[SZ], b[SZ];
ll left1, left2;

//900000011

void sieve(){
    ll i, j;

    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i)
                arr[j] = 1;
    prime.push_back(2);

    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
//    REP(i, 25)
//        printf("%d\n",prime[i]);
}

void factorize1(ll n, ll mul){
    ll i, j, k;

    k = sz(prime);

    for(i=0;i<k;i++){
        if(n % prime[i] == 0){
            j = 0;
            while(n % prime[i] == 0){
                j++;
                n /= prime[i];
            }
            a[i] = j * mul;
        }
    }

    left1 = n;
}

void factorize2(ll n, ll mul){
    ll i, j, k;

    k = sz(prime);

    for(i=0;i<k;i++){
        if(n % prime[i] == 0){
            j = 0;
            while(n % prime[i] == 0){
                j++;
                n /= prime[i];
            }
            b[i] = j * mul;
        }
    }

    left2 = n;
}



class BigFatInteger2 {
public:
	string isDivisible(int A, int B, int C, int D) {
        sieve();
        mem(a, 0);
        mem(b, 0);
        factorize1((ll)A, (ll)B);
        factorize2((ll)C, (ll)D);

        int i, k, f;

        f = 0;

        k = sz(prime);

        REP(i, k){
            if(b[i] > a[i]){
//                f = 0;
                break;
            }
        }

        if(i == k){
            if(left1 == 1 && left2 == 1) f = 1;
            else if(left2 == 1) f = 1;
            else if(left1 == 1) f = 0;
            else
            {
                if((left1 % left2 == 0) && B >= D)
                    f = 1;
                else
                    f = 0;
            }
        }

//        if(left1 != 1 && left2 != 1){
//            if(left1 % left2 != 0)
//                f = 0;
//            else if((left1 % left2 == 0) && B < D)
//                f = 0;
//        }

        if(f) return "divisible";
        else return "not divisible";
	}
};
