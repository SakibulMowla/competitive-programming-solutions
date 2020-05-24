#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sakib
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

ll p,q,n;
vector <ll> a;
vector <ll> m;

bool read()
{
    if (!(cin >> p >> q >> n)) return false;
    a.assign(n,0);
    forn(i,n)
    cin >> a[i];
    return true;
}

void calc(ll a, ll b)
{
    if (a == 0 || b == 0) return;
    ll q = a/b;
    m.pb(q);
    a -= b*q;
    calc(b,a);
}

void solve()
{
    if (n > 1 && a[n-1] == 1)
    {
        a[n-2]++;
        a.pop_back();
        n--;
    }
    m.clear();
    calc(p,q);
    bool ans = true;
    if (sz(a)!=sz(m)) ans = false;
    forn(i,min(sz(a),sz(m)))
    ans = ans && (a[i]==m[i]);
    if (ans)
        puts("YES");
    else
        puts("NO");
}

int main()
{
#ifdef sakib
    freopen("1.txt","r",stdin);
#endif
    while (read())
        solve();
    return 0;
}
