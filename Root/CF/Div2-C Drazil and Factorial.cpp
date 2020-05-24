#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

int cal (int n, int d) {
    int x = 0;
    while (n >= d) {
        x += n / d;
        n /= d;
    }
    return x;
}

int cnt[10];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int n;
    string a;
    while (cin >> n >> a) {
        mem(cnt, 0);
        for (int i = 0; i < n; i++) {
            int x = a[i] - '0';
            if (x == 2) cnt[2]++;
            else if (x == 3) cnt[3]++;
            else if (x == 4) cnt[2]+=2, cnt[3]++;
            else if (x == 5) cnt[5]++;
            else if (x == 6) cnt[5]++, cnt[3]++;
            else if (x == 7) cnt[7]++;
            else if (x == 8) cnt[7]++, cnt[2]+=3;
            else if (x == 9) cnt[7]++, cnt[2]++, cnt[3]+=2;
        }
        for (int i = 7; i >= 2; i--) {
            while (cnt[i]) {
                cout << i;
                cnt[i]--;
            }
        }
        cout << '\n';
    }


    return 0;
}






