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


#define SZ 2000010
#define SZ1 10010

char arr[SZ], *s;

bool comp (pair <int, string> a, pair <int, string> b) {
    if (a.X == b.X) {
        return a.Y < b.Y;
    }
    return a.X > b.X;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int m;
    scanf("%d", &m);

    map <string, int> name, word;
    int names = 0, words = 0;
    map <int, int> cnt1;
    vector < set <int>> v;
    map <int, string> Rev;

    for (int i = 0; i < m; i++) {
        scanf(" %[^\n]", arr);
        s = strtok(arr, " ");
        bool f = false;
        int now;
        while (s != NULL) {
            if (!f) {
                f = true;
                if (name.find(s) == name.end()) {
                    name[s] = names++;
                    v.pb(set <int>());
                }
                now = name[s];
            } else {
                if (word.find(s) == word.end()) {
                    word[s] = words++;
                    cnt1[words-1] = 1;
                    Rev[words-1] = s;
                } else {
                    cnt1[word[s]]++;
                }
                v[now].insert(word[s]);
            }
            s = strtok(NULL, " ");
        }
    }

    map <int, int> cnt2;

    for (int i = 0; i < sz(v); i++) {
        for (set <int>::iterator it = v[i].begin(); it != v[i].end(); it++) {
            if (cnt2.find(*it) == cnt2.end()) {
                cnt2[*it] = 1;
            } else {
                cnt2[*it]++;
            }
        }
    }

    vector < pair <int, string>> vpis;

    for (map <int, int>::iterator it = cnt2.begin(); it != cnt2.end(); it++) {
        if (it->Y == sz(v)) {
            vpis.pb({cnt1[it->X], Rev[it->X]});
        }
    }

    sort(vpis.begin(), vpis.end(), comp);

    if (sz(vpis) == 0) {
        printf("ALL CLEAR\n");
    } else {
        for (int i = 0; i < sz(vpis); i++) {
            printf("%s\n", vpis[i].Y.c_str());
        }
    }

    return 0;
}





