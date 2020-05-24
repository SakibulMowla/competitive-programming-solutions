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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 30

struct data
{
    int val;
    char ch;
    data(){}
    data(int a, char b)
    {
        val = a;
        ch = b;
    }
};

bool comp(data p, data q)
{
    return p.val > q.val;
}

vector <data> v;

int main()
{
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int test = 0, i, j, k, n, m, p, q, indx;
    char ch;
    string s;

    while(scanf("%d",&n) == 1 && n)
    {
        cin >> s;
        k = sz(s);
        clr(v);

        printf("Simulation %d\n",++test);

        indx = 0;
        while(k--)
        {
            ch = s[indx++];
            j = sz(v);
            if(ch >= 'A' && ch <= 'Z')
            {
                q = 1;
                for(i=0; i<j; i++)
                {
                    if(v[i].ch == ch)
                    {
                        q = 0;
                        v[i].val = 1;
                        for(p=0; p<j; p++)
                        {
                            if(p == i) continue;
                            v[p].val++;
                        }
                        break;
                    }
                }

                if(q)
                {
                    if(j < n)
                    {
                        v.pb(data(1, ch));
                        for(i=0; i<j; i++)
                            v[i].val++;
                    }
                    else
                    {
                        p = n + 1;
                        q = -1e9;
                        for(i=0; i<j; i++)
                        {
                            if(v[i].val > q)
                            {
                                q = v[i].val;
                                p = i;
                            }
                        }
                        v[p] = data(1, ch);
                        for(i=0; i<j; i++)
                        {
                            if(i == p) continue;
                            v[i].val++;
                        }
                    }
                }
            }
            else
            {
                sort(v.begin(), v.end(), comp);
                j = sz(v);
                for(i=0; i<j; i++)
                    printf("%c",v[i].ch);
                puts("");
            }
        }

    }


    return 0;
}
















