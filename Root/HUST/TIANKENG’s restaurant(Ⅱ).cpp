#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "string"
#include "string.h"
#include "map"
#include "vector"
#include "assert.h"

using namespace  std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

#define SZ 1000010

int nxt[SZ+SZ][8];

char s[SZ];
int n;
int node;

void Insert (int strt) {
    int now = 0;
    for (int i = strt; i < strt + 7 && i < n; i++) {
        if (nxt[now][s[i]-'A'] == -1) {
            nxt[now][s[i]-'A'] = node++;
        }
        now = nxt[now][s[i]-'A'];
    }
    return;
}

string stk;
string ans;
int len;

void bctk (int now, int dep) {
    if (dep >= len) return;

    for (int i = 0; i < 8; i++) {
        if (nxt[now][i] == -1) {
            if (dep + 1 < len) {
                len = dep + 1;
                ans = stk + (char)(i + 'A');
                return;
            }
        } else {
            stk.push_back((char)(i + 'A'));
            bctk(nxt[now][i], dep + 1);
            stk.pop_back();
        }
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%s", s);
        n = strlen(s);

        mem(nxt, -1);
        node = 1;

        for (int i = 0; i < n; i++) {
            Insert(i);
        }

        stk = "";
        len = 100;

        bctk(0, 0);

        printf("%s\n", ans.c_str());
    }


    return 0;
}







