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

int a[SZ];

vector <int> odd1, odd2, even;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, n, p, cnt, cnte, cnto, p1, p2, p3, k1, k2, k3, q;

    while(scanf("%d %d %d",&n,&k,&p) == 3){
        clr(even);
        clr(odd1);
        clr(odd2);

        cnt = cnte = cnto = 0;

        REP1(i, 1, n){
            RD(j);
            if(j%2 == 1 && cnt < k-p){
                cnt++;
                odd1.pb(j);
            }
            else if(j % 2 == 1){
                cnto++;
                odd2.pb(j);
            }
            else{
                cnte++;
                even.pb(j);
            }
        }

        if(cnt < k-p || cnto % 2 == 1 || cnte + (cnto/2) < p){
            printf("NO\n");
            continue;
        }

        printf("YES\n");

        k1 = sz(odd1);
        k2 = sz(odd2);
        k3 = sz(even);
        p1 = p2 = p3 = 0;

        REP1(i, 1, k){
            if(i == k){
                printf("%d ",n-p1-p2-p3);
                for(j=p1; j<k1; j++) printf("%d ",odd1[j]);
                for(j=p2; j<k2; j++) printf("%d ",odd2[j]);
                for(j=p3; j<k3; j++) printf("%d ",even[j]);
                printf("\n");
            }
            else{
                if(p1 < k1){
                    printf("1 %d\n",odd1[p1++]);
                }
                else if(p2 < k2){
                    printf("2 %d %d\n",odd2[p2],odd2[p2+1]);
                    p2 += 2;
                }
                else{
                    printf("1 %d\n",even[p3++]);
                }
            }
        }


        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}






