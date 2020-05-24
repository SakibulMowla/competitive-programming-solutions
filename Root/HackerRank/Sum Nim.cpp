#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

map <pii, ll> mp;

ll solve (vector <int> &a, int pos, int Xor) {
    if (pos == -1) {
        return (Xor == 0);
    }
    if (mp.find({pos, Xor}) != mp.end()) {
        return mp[{pos, Xor}];
    } else {
        mp[{pos, Xor}] = 0;
        int sum = 0;
        for (int i = pos; i >= 0; i--) {
            sum += a[i];
            mp[{pos, Xor}] += solve(a, i - 1, Xor ^ sum);
        }
        return mp[{pos, Xor}];
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector <int> a(n);

    for (int &x: a) {
        cin >> x;
    }

    cout << solve(a, n - 1, 0) << endl;


    return 0;
}



