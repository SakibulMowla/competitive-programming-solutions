#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;

double x[100], y[100];
int N;
double R;

const double pi = acos(-1.0);


typedef double T;
const T EPS = 1e-7;
struct PT {
    T x, y;
    PT() {}
    PT(T x, T y) : x(x), y(y) {}
    bool operator<(const PT &rhs) const {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
    bool operator==(const PT &rhs) const {
        return make_pair(y,x) == make_pair(rhs.y,rhs.x);
    }
};

T cross(PT p, PT q) {
    return p.x*q.y-p.y*q.x;
}

T area2(PT a, PT b, PT c) {
    return cross(a,b) + cross(b,c) + cross(c,a);
}


void ConvexHull (vector<PT> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

double border (PT a, PT b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double calc (int mask) {
    vector <PT> points;
    for (int i = 0; i < N; i++) {
        if (mask & (1<<i)) {
            PT tmp;
            tmp.x = x[i];
            tmp.y = y[i];
            points.pb(tmp);
        }
    }

    ConvexHull(points);
    int n = points.size();

    double ans = 2*acos(-1.0)*R + border(points[n-1], points[0]);

    for(int i = 1; i<n; ++i)
        ans += border(points[i-1], points[i]);

    return ans;
}

double dp[(1<<13)+10];
int col[(1<<13)+10];
int now;

double solve (int mask) {
    if (__builtin_popcount(mask) == 0) return 0.0;
    if (col[mask] == now) return dp[mask];
    col[mask] = now;

    double &ret = dp[mask];
    ret = calc(mask);

    for (int i = mask - 1; i >= 0; ) {
        int half1 = (mask & i);
        int half2 = (mask ^ half1);
        ret = min(ret, solve(half1) + solve(half2));
        i--;
        if(i >= 0)
            i &= mask;
    }

    return ret;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> N >> R;

        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y [i];
        }

        now++;


        cout << "Case " << cs + 1 << ": " << fixed << setprecision(3)<< solve((1<<N)-1) << endl;
    }


    return 0;
}





