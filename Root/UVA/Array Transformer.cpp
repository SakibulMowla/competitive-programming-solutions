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
#include <assert.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
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

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  300010
#define SZ1  550 //sqrt(300000) = 547.7225

int arr[SZ];
int tree[SZ1][SZ1];

void build(int n)
{
    int i, j, k;

    j = k = 0;

    REP(i, n)
    {
        RD(arr[i]);
        tree[j][k] = arr[i];
        k++;
        if(k == SZ1)
        {
            stable_sort(tree[j], tree[j]+k);
            k = 0;
            j++;
        }
    }

    for(; k<SZ1; k++)
        tree[j][k] = (1e9)+1;

    stable_sort(tree[j], tree[j]+k);

    return;
}

int b_search(int part, int lo, int hi, int val)
{
    int mid, ans=-1, left=lo;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(tree[part][mid] < val)
        {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    if(ans == -1) return 0;
    return ans-left+1;
}

int query(int l, int r, int val)
{
    int b, e, i, ans;

    b = l/SZ1;
    e = r/SZ1;

    if(b == e)
    {
        ans = 0;
        REP1(i, l, r)
            if(arr[i] < val)
                ans++;
        return ans;
    }

    ans = 0;

    REP1(i, l, SZ1*(b+1)-1)
        if(arr[i] < val)
            ans++;

    REP1(i, e*SZ1, r)
        if(arr[i] < val)
            ans++;

    REP1(i, b+1, e-1)
        ans += b_search(i, 0, SZ1-1, val);

    return ans;
}

void vaago(int indx, int val)
{
    int i, part, lo, hi, mid;

    part = indx/SZ1;
    lo = 0;
    hi = SZ1-1;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(tree[part][mid] == val)
        {
            indx = mid;
            break;
        }
        else if(tree[part][mid] > val) hi = mid - 1;
        else lo = mid + 1;
    }

    for(i=indx; i<SZ1-1; i++)
        tree[part][i] = tree[part][i+1];

    tree[part][i] = (1e9)+1;

    return;
}

void insert(int indx, int val)
{
    int i, part, lo, hi, mid;

    part = indx/SZ1;
    lo = 0;
    hi = SZ1-1;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(tree[part][mid] >= val)
        {
            indx = mid;
            hi= mid - 1;
        }
        else lo = mid + 1;
    }

    for(i=SZ1-1; i>indx; i--)
        tree[part][i] = tree[part][i-1];

    tree[part][indx] = val;

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
    #endif

    int n, m, i, j, k, l, r, v, p;
    ll u, val;

    RD(n, m);
    RD(u);

    build(n);

    while(m--)
    {
        RD(l, r);
        RD(v, p);
        l--, r--, p--;

        k = query(l, r, v);
        val = u*(ll)k/(ll)(r-l+1);

        vaago(p, arr[p]);
        insert(p, val);

        arr[p] = (int)val;
    }

    REP(i, n)
        PR(arr[i]);


    return 0;
}













