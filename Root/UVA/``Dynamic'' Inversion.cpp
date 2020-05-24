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

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}


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

#define SZ 200000+10
int SZ1;

int tree[SZ], pos[SZ], arr[SZ];
int N;

void update(int indx)
{
    while(indx <= N)
    {
        tree[indx] += 1;
        indx += (indx & -indx);
    }
    return;
}

int query(int indx)
{
    int sum = 0;
    while(indx > 0)
    {
        sum += tree[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

struct data{
    int val[450], sz;
};

data group[450];
int tot_grp;

void prepare()
{
    int i, gp, idx;

    gp = idx = 0;

    for(i=0; i<N; i++)
    {
        group[gp].val[idx++] = arr[i];
        if(idx == SZ1)
        {
            group[gp].sz = idx;
            stable_sort(group[gp].val, group[gp].val+idx);
            gp++;
            idx = 0;
        }
    }
    group[gp].sz = idx;
    stable_sort(group[gp].val, group[gp].val+idx);
    tot_grp = (N/SZ1) + 1;

    return;
}

void Delete(int val)
{
    int gp, indx, i;

    indx = pos[val];
    gp = indx/SZ1;

    arr[indx] = -1;

    int lo, hi, mid;

    lo = 0;
    hi = group[gp].sz-1;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(group[gp].val[mid] == val)
        {
            indx = mid;
            break;
        }
        else if(group[gp].val[mid] > val)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    for(i=indx+1; i<group[gp].sz; i++)
        group[gp].val[i-1] = group[gp].val[i];
    group[gp].sz--;

    return;
}

int bs_right(int gp, int val)
{
    int lo, mid, hi, ans;

    ans = -1;
    lo = 0;
    hi = group[gp].sz-1;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(group[gp].val[mid] < val)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    return ans+1;
}

int search_right(int val)
{
    int gp, indx, i, k, cnt=0;

    indx = pos[val];
    gp = indx/SZ1;

    k = min(SZ1*(gp+1), N);

    for(i=indx; i<k; i++)
        if(arr[i] != -1 && arr[i] < arr[indx])
            cnt++;

    for(i=gp+1; i<tot_grp; i++)
        cnt += bs_right(i, val);

    return cnt;
}

int bs_left(int gp, int val)
{
    int lo, mid, hi, ans;

    ans = -1;
    lo = 0;
    hi = group[gp].sz-1;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if(group[gp].val[mid] <= val)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    return (group[gp].sz-1-ans);
}

int search_left(int val)
{
    int gp, indx, i, k, cnt=0;

    indx = pos[val];
    gp = indx/SZ1;

    k = SZ1*(gp);

    for(i=indx; i>=k; i--)
        if(arr[i] != -1 && arr[i] > arr[indx])
            cnt++;

    for(i=gp-1; i>=0; i--)
        cnt += bs_left(i, val);

    return cnt;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int m, i, val;
    ll ans;

    while(scanf("%d %d",&N,&m) == 2)
    {
        memset(tree, 0, sizeof(int)*(N+5));
        ans = 0LL;

        SZ1 = sqrt(N)+2;

        for(i=0; i<N; i++)
        {
//            scanf("%d",&arr[i]);
            inp(arr[i]);
            pos[ arr[i] ] = i;
        }

        for(i=1; i<=N; i++)
        {
            ans += (ll)query(N) - (ll)query(pos[i]+1);
            update(pos[i]+1);
        }

        prepare();

        while(m--)
        {
            printf("%lld\n",ans);
//            scanf("%d",&val);
            inp(val);

            ans -= (ll)search_right(val);
            ans -= (ll)search_left(val);

            Delete(val);
        }
    }

    return 0;
}













