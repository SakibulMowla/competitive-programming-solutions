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

#define SZ 3010

int arr[SZ], tmp[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, n, m, cnt, p, x, y, z;

    while(scanf("%d",&n) == 1){

        REP1(i, 1, n){
            RD(arr[i]);
            tmp[i] = arr[i];
        }
        RD(m);

        cnt = 0;
        while(true){
            REP1(i, 1, n){
                if(tmp[i] == i) continue;
                cnt++;
                j = tmp[ tmp[i] ];
                tmp[ tmp[i] ] = tmp[i];
                tmp[i] = j;
                break;
            }
            if(i > n) break;
        }

//        printf("cnt = %d\n",cnt);
        p = abs(m-cnt);

        REP1(i, 1, n) tmp[i] = arr[i];

        if(cnt == m){
            printf("0\n");
        }
        else if(cnt > m){
            printf("%d\n",cnt-m);

            while(p--){
                REP1(i, 1, n){
                    if(tmp[i] == i) continue;
                    cnt++;
                    printf("%d %d ",i,tmp[i]);
                    j = tmp[ tmp[i] ];
                    tmp[ tmp[i] ] = tmp[i];
                    tmp[i] = j;
                    break;
                }
            }

            printf("\n");
        }
        else{
            printf("%d\n",m-cnt);

            while(p--){
                REP1(i, 1, n){
                    if(tmp[i] == i){
                        printf("%d %d ",i,i+1);
                        swap(tmp[i], tmp[i+1]);
                        break;
                    }
                    else if(i == tmp[ tmp[i] ]){
                        for(j=1; j<=n; j++){
                            if(j==i || j==tmp[i]) continue;
                            break;
                        }
                        x = i;
                        y = tmp[i];
                        z = j;
                        k = tmp[x];
                        tmp[x] = tmp[z];
                        tmp[z] = tmp[y];
                        tmp[y] = k;
                        break;
                    }
                }
            }

            printf("\n");
        }


        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}






