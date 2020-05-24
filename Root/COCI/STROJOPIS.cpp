#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

map <char , int> mp;
int cnt[1000];

void prep () {
    mp['`'] = 1; mp['1'] = 1; mp['Q'] = 1; mp['A'] = 1; mp['Z'] = 1;
    mp['2'] = 2; mp['W'] = 2; mp['S'] = 2; mp['X'] = 2;
    mp['3'] = 3; mp['E'] = 3; mp['D'] = 3; mp['C'] = 3;
    mp['4'] = 4; mp['R'] = 4; mp['F'] = 4; mp['V'] = 4;
    mp['5'] = 4; mp['T'] = 4; mp['G'] = 4; mp['B'] = 4;
    mp['6'] = 5; mp['Y'] = 5; mp['H'] = 5; mp['N'] = 5;
    mp['7'] = 5; mp['U'] = 5; mp['J'] = 5; mp['M'] = 5;
    mp['8'] = 6; mp['I'] = 6; mp['K'] = 6; mp[','] = 6;
    mp['9'] = 7; mp['O'] = 7; mp['L'] = 7; mp['.'] = 7;
    mp['0'] = 8; mp['P'] = 8; mp[';'] = 8; mp['/'] = 8; mp['\''] = 8;
    mp['-'] = 8; mp['='] = 8; mp['['] = 8; mp[']'] = 8;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    prep();

    string s;
    cin >> s;

    for (int i = 0; i < sz(s); i++) {
        cnt[ mp[s[i]] ]++;
    }

    for (int i = 1; i <= 8; i++)
        cout << cnt[i] << '\n';

    return 0;
}







