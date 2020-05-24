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

int cal (char c) {
    if (tolower(c) == 'q') return 9;
    if (tolower(c) == 'r') return 5;
    if (tolower(c) == 'b') return 3;
    if (tolower(c) == 'n') return 3;
    if (tolower(c) == 'p') return 1;
    return 0;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int w = 0, b = 0;

    string s;
    for (int i = 0; i < 8; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == toupper(s[j])) w += cal(s[j]);
            else b += cal(s[j]);
        }
    }

    if (w > b) cout << "White\n";
    else if (w < b) cout << "Black\n";
    else cout << "Draw\n";

    return 0;
}






