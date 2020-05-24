#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x) {
    scanf("%d",&x);
}
void RD(ll &x) {
    scanf("%I64d",&x);
}
void RD(double &x) {
    scanf("%lf",&x);
}
void RD(int &x,int &y) {
    scanf("%d%d",&x,&y);
}
void RD(ll &x,ll &y) {
    scanf("%I64d%I64d",&x,&y);
}
void RD(double &x,double &y) {
    scanf("%lf%lf",&x,&y);
}
void RD(char *s) {
    scanf("%s",s);
}
void RD(char &s) {
    scanf("%c",&s);
}
void RD(string &s) {
    cin>>s;
}

void PR(int x) {
    printf("%d\n",x);
}
void PR(int x,int y) {
    printf("%d %d\n",x,y);
}
void PR(ll x) {
    printf("%I64d\n",x);
}
void PR(char x) {
    printf("%c\n",x);
}
void PR(char *x) {
    printf("%s\n",x);
}
void PR(string x) {
    cout<<x<<endl;
}

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

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

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 1010

bool arr[SZ];
vector <int> prime;

void sieve() {
    int i, j, k;

    k = sqrt(1000);

    for(i=3;i<=k;i++)
        if(!arr[i])
            for(j=i*i;j<1001;j+=i)
                arr[j] = 1;
    prime.push_back(2);

    for(i=3;i<1001;i+=2)
        if(!arr[i])
            prime.push_back(i);
}

int cnt[45][170];

int main() {
    sieve();
    int t, n, a, b, i, j, k;

    RD(t);

    k = sz(prime);

    while(t--) {
        RD(n);
        RD(a);
        RD(b);
//        PR(a, b);
        for(i=0;i<=n;i++)
            mem(cnt[i], 0);

        for(i=0;i<k;i++){
            if(a%prime[i] == 0){
                j = 0;
                while(a%prime[i] == 0){
                    a /= prime[i];
                    j++;
                }
//                printf("a %d\n",prime[i]);
                cnt[0][i] = j;
            }

            if(b%prime[i] == 0){
                j = 0;
//                printf("b = %d\n",b);
                while(b%prime[i] == 0){
                    b /= prime[i];
                    j++;
                }
//                printf("b %d %d\n", b, prime[i]);
                cnt[1][i] = j;
            }
            if(a == 1 && b == 1) break;
        }

        for(i=2;i<=n;i++)
            for(j=0;j<168;j++)
                cnt[i][j] = cnt[i-1][j] + cnt[i-2][j];

        REP(i, 168)
            if(cnt[n][i])
                PR(prime[i], cnt[n][i]);
        puts("");
    }


    return 0;
}















