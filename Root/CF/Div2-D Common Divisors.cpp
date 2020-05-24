#include <iostream>
#include <vector>
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
const ll mod1 = 1824259937;
const ll mod2 = 179424499;
const ll mod3 = 776529599;


#define SZ 100010

ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while (P > 0) {
        if(P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}


struct data {
    ll a, b, c;
    data() {
        a = 0, b = 0, c = 0;
    }
};

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;

    vector <data> ten(100002);
    ten[0].a = 1;
    ten[0].b = 1;
    ten[0].c = 1;
    for (int i = 1; i <= 100000; i++) {
        ten[i].a = (ten[i-1].a * 10) % mod1;
        ten[i].b = (ten[i-1].b * 10) % mod2;
        ten[i].c = (ten[i-1].c * 10) % mod3;
    }

    int l1 = s1.size(), l2 = s2.size(), ans = 0;

    data fin1;
    for (int i = 0; i < l1; i++) {
        fin1.a = (fin1.a * 10 + s1[i] - 'a' + 1) % mod1;
        fin1.b = (fin1.b * 10 + s1[i] - 'a' + 1) % mod2;
        fin1.c = (fin1.c * 10 + s1[i] - 'a' + 1) % mod3;
    }
    data fin2;
    for (int i = 0; i < l2; i++) {
        fin2.a = (fin2.a * 10 + s2[i] - 'a' + 1) % mod1;
        fin2.b = (fin2.b * 10 + s2[i] - 'a' + 1) % mod2;
        fin2.c = (fin2.c * 10 + s2[i] - 'a' + 1) % mod3;
    }

    data block;
    for (int i = 0; i < min(l1, l2); i++) {
        if (s1[i] != s2[i]) break;
        block.a = (block.a * 10 + s1[i] - 'a' + 1) % mod1;
        block.b = (block.b * 10 + s1[i] - 'a' + 1) % mod2;
        block.c = (block.c * 10 + s1[i] - 'a' + 1) % mod3;
        if (l1 % (i + 1) == 0 && l2 % (i + 1) == 0) {
            data r = ten[i+1];
            r.a = (r.a - 1 + mod1) % mod1;
            r.b = (r.b - 1 + mod2) % mod2;
            r.c = (r.c - 1 + mod3) % mod3;
            r.a = BigMod(r.a, mod1 - 2, mod1);
            r.b = BigMod(r.b, mod2 - 2, mod2);
            r.c = BigMod(r.c, mod3 - 2, mod3);

            if ((((block.a * (ten[l1].a - 1 + mod1) % mod1) % mod1) * r.a) % mod1 == fin1.a &&
                (((block.b * (ten[l1].b - 1 + mod2) % mod2) % mod2) * r.b) % mod2 == fin1.b &&
                (((block.c * (ten[l1].c - 1 + mod3) % mod3) % mod3) * r.c) % mod3 == fin1.c &&
                (((block.a * (ten[l2].a - 1 + mod1) % mod1) % mod1) * r.a) % mod1 == fin2.a &&
                (((block.b * (ten[l2].b - 1 + mod2) % mod2) % mod2) * r.b) % mod2 == fin2.b &&
                (((block.c * (ten[l2].c - 1 + mod3) % mod3) % mod3) * r.c) % mod3 == fin2.c)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}





