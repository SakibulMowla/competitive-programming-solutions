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

map <string , string> mp1, mp2;
string str1, str2;

void pre () {
    mp1["AA"] = "A";
    mp1["AB"] = "AB";
    mp1["AO"] = "A";
    mp1["BB"] = "B";
    mp1["BO"] = "B";
    mp1["OO"] = "O";
    mp2["A"] = "AO";
    mp2["B"] = "BO";
    mp2["AB"] = "AB";
    mp2["O"] = "O";
    str1 = "ABO";
    str2 = "+-";
}

string getABO (string s) {
    s.erase(sz(s)-1);
    return mp2[s];
}

string getSign (string s) {
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '+') return "+-";
        if (s[i] == '-') return "--";
    }
}

string mergeAbo (char a, char b) {
    string s = "  ";
    s[0] = a;
    s[1] = b;
    sort(s.begin(), s.end());
    return mp1[s];
}

char mergeSign (char a, char b) {
    if (a == '+' || b == '+') return '+';
    return '-';
}

void doit (vector <string> &ans, char a, char b) {
    vector <string> ans1;
    string ans2 = "";
    if (a == 'A') {
        ans1.pb("A");
        ans1.pb("AB");
    } else if (a == 'B') {
        ans1.pb("B");
        ans1.pb("AB");
    } else {
        ans1.pb("A");
        ans1.pb("B");
        ans1.pb("O");
    }
    if (b == '+') {
        ans2 += "+";
    } else {
        ans2 += "+-";
    }
    for (int i = 0; i < sz(ans1); i++) {
        for (int j = 0; j < sz(ans2); j++) {
            ans.pb(ans1[i]+ans2[j]);
        }
    }
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    pre();

    int Test = 0;
    string a, b, c;

    while (cin >> a >> b >> c) {
        if (a == "E" && b == "N" && c == "D") break;

        cout << "Case " << ++Test << ":";

        if (c == "?") {
            string p = getABO(a);
            string q = getABO(b);
            string r = getSign(a);
            string s = getSign(b);

            vector <string> ans;

            for (int i = 0; i < sz(p); i++) {
                for (int j = 0; j < sz(q); j++) {
                    for (int k = 0; k < sz(r); k++) {
                        for (int l = 0; l < sz(s); l++) {
                            ans.pb(mergeAbo(p[i], q[j]) + mergeSign(r[k], s[l]));
                        }
                    }
                }
            }

            sort(ans.begin(), ans.end());
            Unique(ans);

            cout << ' ' << a << ' ' << b << ' ';
            if (sz(ans) == 1) {
                cout << ans[0] << '\n';
            } else {
                cout << '{';
                bool blk = 0;
                for (int i = 0; i < sz(ans); i++) {
                    if (!blk) blk = 1;
                    else cout << ' ';
                    cout << ans[i];
                    if (i != sz(ans)-1) cout << ',';
                }
                cout << '}' << '\n';
            }
        } else {
            bool mark = 0;
            if (a == "?") {
                swap(a, b);
                mark = 1;
            }

            string p = getABO(a);
            string q = getSign(a);

            vector <string> ans;

            for (int i = 0; i < sz(p); i++) {
                for (int j = 0; j < sz(q); j++) {
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 2; l++) {
                            string tmp = mergeAbo(p[i], str1[k]) + mergeSign(q[j], str2[l]);
                            if (tmp == c) {
                                doit(ans, str1[k], str2[l]);
                            }
                        }
                    }
                }
            }

            sort(ans.begin(), ans.end());
            Unique(ans);

            if (!mark) {
                cout << ' ' << a << ' ';
                if (sz(ans)) {
                    if (sz(ans) == 1) {
                        cout << ans[0];
                    } else {
                        cout << '{';
                        bool blk = 0;
                        for (int i = 0; i < sz(ans); i++) {
                            if (!blk) blk = 1;
                            else cout << ' ';
                            cout << ans[i];
                            if (i != sz(ans)-1) cout << ',';
                        }
                        cout << '}';
                    }
                } else {
                    cout << "IMPOSSIBLE";
                }
                cout << ' ' << c << '\n';
            } else {
                cout << ' ';
                if (sz(ans)) {
                    if (sz(ans) == 1) {
                        cout << ans[0];
                    } else {
                        cout << '{';
                        bool blk = 0;
                        for (int i = 0; i < sz(ans); i++) {
                            if (!blk) blk = 1;
                            else cout << ' ';
                            cout << ans[i];
                            if (i != sz(ans)-1) cout << ',';
                        }
                        cout << '}';
                    }
                } else {
                    cout << "IMPOSSIBLE";
                }
                cout << ' ' << a << ' ' << c << '\n';
            }
        }
    }



    return 0;
}







