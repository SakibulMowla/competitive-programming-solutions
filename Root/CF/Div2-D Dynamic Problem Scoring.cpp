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


#define SZ 100010

int findScore (int num, int denum) {
    if (num * 2 > denum) return 500;
    if (num * 4 > denum) return 1000;
    if (num * 8 > denum) return 1500;
    if (num * 16 > denum) return 2000;
    if (num * 32 > denum) return 2500;
    return 3000;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector < vector <int> > a(n, vector <int> (5));
    vector <int> cnt(5, 0);

    for (auto &x: a) {
        for (int i = 0; i < 5; i++) {
            cin >> x[i];
            if (x[i] != -1) cnt[i]++;
        }
    }

    int ans = -1;

    for (int fake = 0; fake < 10057; fake++) {
        int vasya = 0, petya = 0;
        for (int i = 0; i < 5; i++) {
            int denum = n + fake;
            int num = cnt[i];
            if (a[0][i] != -1 && (a[1][i] != -1 && a[0][i] > a[1][i])) num += fake;
            int score = findScore(num, denum);
            if (a[0][i] != -1) vasya += (score / 250) * (250 - a[0][i]);
            if (a[1][i] != -1) petya += (score / 250) * (250 - a[1][i]);
        }
        if (vasya > petya) {
            ans = fake;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}


