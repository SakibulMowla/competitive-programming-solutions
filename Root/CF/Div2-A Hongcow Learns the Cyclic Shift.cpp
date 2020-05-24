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
const ll mod = 1E9;


#define SZ 100010


int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    map <string, int> mp;
    mp[s] = 1;

    for (int i = 0; i < 50; i++) {
        char c = s[s.size() - 1];
        s.erase(s.size() - 1);
        s = c + s;
        mp[s] = 1;
    }

    cout << mp.size() << endl;

    return 0;
}





