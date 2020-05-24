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
#define RUN_FORREST_RUN ios_base::sync_with_stdio(0);cin.tie(0);

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

#define SZ 110

int par[SZ];
string s1, s2, pat;

void pre_process()
{
    int i, k, n;

    n = sz(pat);
    k = 0;
    par[0] = 0;

    for(i=1; i<n; i++)
    {
        while(k>0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }

    return ;
}

int dp[SZ][SZ][SZ], len1, len2, M;
int dp_kmp[SZ][210];

int kmp_solve(int len,int now)
{
    int &ret = dp_kmp[len][now];
    if(ret!=-1) return ret;
    while(len>0 && pat[len] != now)
        len = par[len-1];
    if(pat[len] == now) len++;
    return ret = len;
}

int solve(int indx1, int indx2, int match)
{
    int &ret = dp[indx1][indx2][match];
        if(~ret) return ret;

    if(indx1 == len1 || indx2 == len2)
        return ret = 0;

    ret = solve(indx1+1, indx2, match);
    ret = max(ret, solve(indx1, indx2+1, match));

    if(s1[indx1] == s2[indx2])
    {
        match = kmp_solve(match, s1[indx1]);
        if(match < M)
            ret = max(ret, 1+solve(indx1+1, indx2+1, match));
    }

    return ret;
}

void path(int indx1, int indx2, int match)
{
    if(indx1 >= len1 || indx2 >= len2)
    {
        printf("\n");
        return;
    }

    int k = dp[indx1][indx2][match];

    if(k == dp[indx1+1][indx2][match]) return path(indx1+1, indx2, match);
    if(k == dp[indx1][indx2+1][match]) return path(indx1, indx2+1, match);
    printf("%c",s1[indx1]);
    return path(indx1+1, indx2+1, kmp_solve(match, s1[indx1]));
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    RUN_FORREST_RUN
    int k;

    while(cin >> s1 >> s2 >> pat){
        len1 = sz(s1);
        len2 = sz(s2);
        M = sz(pat);

        mem(dp, -1);
        mem(dp_kmp, -1);
        pre_process();

        k = solve(0, 0, 0);
        if(!k) PR(k);
        else path(0, 0, 0);
    }

    return 0;
}

/*
BGIIURZTEUJJULBWKHDQBRFGEUOMQSREOTILICRSBUHBGTSRDHKVDDEBVHGMHXUVFJURSMFDJOOOWCYPJDVRVKLDHICPNKTBFXDJ
XOADNTKNILGNHHBNFYNDWUNXBGDFUKUVHLPDOGOYRMOTAQELLRMHFAQEOXFWGAQUROVUSWOAWFRVIRJQVXPCXLSCQLCUWKBZUFQP
YVF

out:
ILBWKHDGOMQELRHEGUVUSOWVRVLCKBF
ans:
TLBWKHDGOROTLRMHXFUROOWVRVLCKBFJ
*/

