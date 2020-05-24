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


#define SZ 70010

bool found[SZ];
string ans[SZ];

struct Trie {
    unordered_map<char, int> child;
    Trie() {
        child.clear();
    }
};

vector<Trie> T;
int nodes;
unordered_map<int, int> mp;

void Insert(string& s, int No) {
    int n = s.size();
    int now = 0;
    for (int i = 0; i < n; i++) {
        bool New = false;
        if (T[now].child.find(s[i]) == T[now].child.end()) {
            T.push_back(Trie());
            T[now].child[s[i]] = nodes++;
            New = true;
        }
        now = T[now].child[s[i]];
        if (New) {
            mp[now] = No;
        } else {
            if (mp[now] != No) {
                mp[now] = -1;
            }
        }
    }
    return;
}

string current;

void Find(int now) {
    if (now != 0 && mp[now] != -1) {
        if (found[mp[now]] == false || (found[mp[now]] == true && sz(ans[mp[now]]) > sz(current))) {
            ans[mp[now]] = current;
            found[mp[now]] = true;
        }
    }
    for(auto it: T[now].child) {
        current.push_back(it.X);
        Find(it.Y);
        current.pop_back();
    }
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    T.push_back(Trie());
    nodes = 1;

    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            s = a[i].substr(j);
            Insert(s, i);
        }
    }

    current = "";
    Find(0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}





