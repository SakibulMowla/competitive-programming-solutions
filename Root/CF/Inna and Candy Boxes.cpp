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

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

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

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

char s[SZ];
int arr[SZ];
int cum[12][SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, n, m, q, p, l, r, lim, ans, seg, one, left, riht, lo, hi, mid, zero, range;

    while(scanf("%d %d %d",&n,&k,&q) == 3){
        scanf("%s",s+1);
        REP1(i, 1, n) arr[i] = (s[i]-'0');

        REP1(i, 1, k) {
            p = 1;
            for(j=i;j<=n;j+=k)
                cum[i][p] = cum[i][p-1] + arr[j], p++;
        }

        while(q--){
            ans = 0;
            RD(l, r);
            if(l == r){
                if(arr[l] != 0) printf("1\n");
                else printf("0\n");
                continue;
            }
            lim = l + k - 1;

//            if(arr[l] != 0) ans++;

            seg = r%k;
            if(seg == 0) seg = k;

            if(lim <= r){
//                seg = lim%k;
//                if(seg == 0) seg = k;

                lo = 0;
                hi = 100000;
                while(lo<=hi){
                    mid = (lo + hi) >> 1;
                    if(mid*k + seg >= lim) {
                        left = mid;
                        hi = mid - 1;
                    }
                    else
                        lo = mid + 1;
                }
                left++;

                lo = 0;
                hi = 100000;
                while(lo<=hi){
                    mid = (lo + hi) >> 1;
                    if(mid*k + seg <= r) {
                        riht = mid;
                        lo = mid + 1;
                    }
                    else
                        hi = mid - 1;
                }
                riht++;

//                printf("s %d lr %d %d\n",seg,left,riht);
                range = riht-left+1;
                one = cum[seg][riht] - cum[seg][left-1];
                zero = range - (cum[seg][riht] - cum[seg][left-1]);
//                printf("r %d one %d zero = %d\n",range,one, zero);
                ans += zero;
            }

//            printf("ans = %d seg = %d\n",ans,seg);

            for(i=1;i<=k;i++){
                if(i == seg) continue;
//            printf("i = %d\n",i);
                lo = 0;
                hi = 100000;
                while(lo<=hi){
                    mid = (lo + hi) >> 1;
                    if(mid*k + i >= l) {
                        left = mid;
                        hi = mid - 1;
                    }
                    else
                        lo = mid + 1;
                }
                left++;

                lo = 0;
                hi = 100000;
                while(lo<=hi){
                    mid = (lo + hi) >> 1;
                    if(mid*k + i <= r) {
                        riht = mid;
                        lo = mid + 1;
                    }
                    else
                        hi = mid - 1;
                }
                riht++;

                range = riht-left+1;
                one = cum[i][riht] - cum[i][left-1];
                zero = range - (cum[i][riht] - cum[i][left-1]);
//                printf("i %d %d %d %d\n",i,one,left,riht);
                ans += one;
            }

            PR(ans);
        }
    }



    return 0;
}















