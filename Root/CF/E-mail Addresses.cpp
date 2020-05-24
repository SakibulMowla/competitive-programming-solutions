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

#define SZ 1000010

char arr[SZ];

int cum_ch[SZ], cum_at[SZ], cum_dt[SZ], cum_us[SZ], cum_dig[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, n, m, len;
    int lo, hi, mid, ans, tmp1, tmp2;
    ll res;

    while(scanf("%s",arr+1) == 1){
        res = 0;
        len = strlen(arr+1);
        REP1(i, 1, len) {
            cum_ch[i] = cum_ch[i-1];
            if(arr[i] >= 'a' && arr[i] <= 'z') cum_ch[i]++;
        }
        REP1(i, 1, len) {
            cum_at[i] = cum_at[i-1];
            if(arr[i] == '@') cum_at[i]++;
        }
        REP1(i, 1, len) {
            cum_dt[i] = cum_dt[i-1];
            if(arr[i] == '.') cum_dt[i]++;
        }
        REP1(i, 1, len) {
            cum_us[i] = cum_us[i-1];
            if(arr[i] == '_') cum_us[i]++;
        }
        REP1(i, 1, len) {
            cum_dig[i] = cum_dig[i-1];
            if(arr[i] >= '0' && arr[i] <= '9') cum_dig[i]++;
        }

        for(i=1; i<=len; i++){
            if(arr[i] == '@'){
                for(j=i+1; j<=len; j++) if(arr[j] == '.'){
                    printf("j = %d\n",j);
                    printf("%d %d\n",cum_ch[j-1]-cum_ch[i] + cum_dig[j-1]-cum_dig[i],j-i-1);
                    if(cum_ch[j-1]-cum_ch[i] + cum_dig[j-1]-cum_dig[i] == j-i-1){
                        printf("yes\n");
                        lo = 1;
                        hi = i;
                        ans = i;
                        while(lo <= hi){
                            mid = (lo + hi) >> 1;
                            if(cum_ch[i-1]-cum_ch[mid] + cum_dig[i-1]-cum_dig[mid] + cum_us[i-1]-cum_us[mid] == i-mid-1){
                                ans = mid;
                                hi = mid - 1;
                            }
                            else
                                lo = mid + 1;
                        }
                        while(!(arr[ans] >= 'a' && arr[ans] <= 'z') && ans < i) ans++;
                        printf("ans = %d\n",ans);
                        tmp1 = ans;

                        for(tmp2=ans; tmp2<=i; tmp2++)
                            if(!(arr[tmp2] >= 'a' && arr[tmp2] <= 'z'))
                                break;

                        tmp1 = tmp2 - tmp1;

                        lo = j;
                        hi = len;
                        ans = j;
                        while(lo <= hi){
                            mid = (lo + hi) >> 1;
                            printf("           %d %d %d\n",cum_ch[mid]-cum_ch[j],mid-j, mid);
                            if(cum_ch[mid]-cum_ch[j] == mid-j){
                                ans = mid;
                                lo = mid + 1;
                            }
                            else
                                hi = mid - 1;
                        }
//                        while(!(arr[ans] >= 'a' && arr[ans] <= 'z') && ans < i) ans++;
                        printf("ans = %d\n",ans);
                        tmp2 = ans - j;

                        res += (ll)tmp1 * (ll) tmp2;
                        printf("tmp %d %d\n",tmp1, tmp2);

                        j = ans;
                    }

                    i = j;
                    break;
                }
                i = j;
            }
        }

        PR(res);
    }

    return 0;
}






