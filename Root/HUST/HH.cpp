#include "bits/stdc++.h"

using namespace std;


const int INF = 2000000000;
const int MOD = 1000000007;

#define REP(i,a,b)  for(int i=a; i<=b; ++i)
const double eps = 1e-9;

struct point
{
    long long x, y;
    point() {}
    point(long long a, long long b) : x(a), y(b) {}
    bool operator < (const point &p) const
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

long long dist2(point &a, point &b)
{
    long long x = a.x - b.x, y = a.y - b.y;
    return (x * x + y * y);
}

bool check(vector<point> &p, long long now, int s, long long d)
{
    vector<point> duration(p.size());
    for (int i = 0; i < p.size(); ++i)
    {
        long long h = p[i].y - now;
        if (h > d)
            return false;
        long long delta = sqrt(1.0 * d * d - 1.0 * h * h);
        duration[i] = point(p[i].x + delta, p[i].x - delta);
    }
    sort(duration.begin(), duration.end());
    int cnt = 0, i = 0;
    while (i < p.size())
    {
        long long now = duration[i].x;
        while (duration[i].y <= now && i < p.size())
            i++;

        cnt++;
        if (cnt > s)
            return false;
    }
    return cnt <= s;
}

void solve()
{
    long long k, n, s, d;
    cin >> k >> n >> s >> d;
    vector<point> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    sort(p.begin(), p.end());

    if (!check(p, k, s, d))
    {
        puts("IMPOSSIBLE");
        return;
    }
    long long lo = k - d - 10, hi = k;
    while (lo < hi)
    {
        if (lo + 1 == hi)
        {
            if (check(p, lo, s, d))
                hi = lo;
            break;
        }
        long long mid = (lo + hi) >> 1;
        if (check(p, mid, s, d))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    printf("%lld\n", k - hi);
}

int main()
{
    int Test;
    cin>>Test;
    REP(cs,1,Test)
    {
        cout<<"Case "<<cs<<": ";
        solve();
    }
    return 0;
}



