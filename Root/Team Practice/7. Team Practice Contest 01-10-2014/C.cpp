#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

using namespace std;

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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ  100010

int A[SZ],B[SZ],C[SZ];
vector <int> v;
set <int> ms;
vector <int> adj[SZ*6][2];
int isInRange[SZ*6];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        ms.clear();

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &A[i], &B[i], &C[i]);
            ms.insert(A[i]);
            ms.insert(B[i]);
            ms.insert(A[i]+1);
            ms.insert(B[i]+1);
            ms.insert(A[i]-1);
            ms.insert(B[i]-1);
        }
        A[m] = 1;
        B[m] = n;
        C[m] = 0;
        ms.insert(A[m]);
        ms.insert(B[m]);
        ms.insert(A[m]+1);
        ms.insert(B[m]+1);
        ms.insert(A[m]-1);
        ms.insert(B[m]-1);
        ms.insert(0);
        ms.insert(n+1);

        v.clear();
        for(set <int> ::iterator it = ms.begin(); it != ms.end(); it++) {
            v.pb(*it);
        }

        for(int i = 0; i < sz(ms); i++)
            adj[i][0].clear(), adj[i][1].clear();

        for(int i = 0; i <= m; i++) {
            int spos = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            int epos = lower_bound(v.begin(), v.end(), B[i]) - v.begin();

            adj[ spos ][0].pb(i);
            adj[ epos ][1].pb(i);
        }

        int start = 1, total = 0, ans = inf;
        mem(isInRange, 0);

        for(int i = 1; i < sz(ms)-1; i++) {
            //printf("i = %d\n", i);
            for(int j = 0; j < sz(adj[i][0]); j++) {
                if(isInRange[ adj[i][0][j] ] == 0) {
                    isInRange[ adj[i][0][j] ] = 1;
                    total += C[ adj[i][0][j] ];
                }
            }
            //printf("start %d i %d\n", start, i);
            while(v[i]- v[start+1] + 1 >= k) {
                for(int j = 0; j < sz(adj[start][1]); j++) {
                    total -= C[ adj[start][1][j] ];
                    isInRange[ adj[start][1][j] ] = 0;
                }
                start++;
            }
//            //printf("start %d i %d\n", start, i);
            if(v[i] - v[start] + 1 >= k) {
                ans = min(ans, total);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}


/*
10 3 5
1 3 2
1 4 2
7 10 5
*/




