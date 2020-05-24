#include "bits/stdc++.h"

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

string HexToBin (char c) {
    string s;

    if (c == '0') s = "0000";
    else if (c == '1') s = "0001";
    else if (c == '2') s = "0010";
    else if (c == '3') s = "0011";
    else if (c == '4') s = "0100";
    else if (c == '5') s = "0101";
    else if (c == '6') s = "0110";
    else if (c == '7') s = "0111";
    else if (c == '8') s = "1000";
    else if (c == '9') s = "1001";
    else if (c == 'A') s = "1010";
    else if (c == 'B') s = "1011";
    else if (c == 'C') s = "1100";
    else if (c == 'D') s = "1101";
    else if (c == 'E') s = "1110";
    else if (c == 'F') s = "1111";

    return s;
}

string shiftLeft (string &a) {
    char c = a[0];
    a.erase(0, 1);
    a = a + c;
    return a;
}

string shiftRight (string &a) {
    char c = a[31];
    a.erase(31, 1);
    a = c + a;
    return a;
}

int leftCnt (string a, string b) {
    if (a == b) return 0;
    for (int i = 1; i <= 32; i++) {
        if (shiftLeft(a) == b)
            return i;
    }
    return -1;
}

int rightCnt (string a, string b) {
    if (a == b) return 0;
    for (int i = 1; i <= 32; i++) {
        if (shiftRight(a) == b)
            return i;
    }
    return -1;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string ta, tb;
        cin >> ta >> tb;

        string a, b;
        a = "";
        b = "";

        for (int i = 0; i < sz(ta); i++)
            a += HexToBin(ta[i]);
        for (int i = 0; i < sz(tb); i++)
            b += HexToBin(tb[i]);

        a = string(32-sz(a), '0') + a;
        b = string(32-sz(b), '0') + b;

        int ans1 = leftCnt(a, b);
        int ans2 = rightCnt(a, b);

        cout << "Case #" << cs+1 << ": ";

        if (ans1 == -1 && ans2 == -1) cout << "Not possible" << '\n';
        else if (ans1 > ans2) cout << ans2 << " Right" << '\n';
        else if (ans2 > ans1) cout << ans1 << " Left" << '\n';
        else cout << ans1 << " Any" << '\n';

//        cout << a << '\n';
//        cout << b << '\n';
    }

    return 0;
}






