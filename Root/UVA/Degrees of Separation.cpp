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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ  55

bool col[SZ];
int dep[SZ];
int adj[SZ][SZ];
map <string , int> mp;
int cnt, N;

void dfs(int u){
    col[u] = 1;
    cnt++;
    int i;
    for(i=1;i<=N;i++)
        if(adj[u][i] == 1 && col[i] == 0)
            dfs(i);
    return;
}

queue <int> Q;

int bfs(int u){
    while(!Q.empty()) Q.pop();
    int i, v, k;
    REP1(i, 1, N) col[i] = 0, dep[i] = 0;
    Q.push(u);
    col[u] = 1;

    while(!Q.empty()){
        v = Q.front(), Q.pop();
        for(i=1;i<=N;i++){
            if(adj[v][i] == 1 && col[i] == 0){
                col[i] = 1;
                Q.push(i);
                dep[i] = dep[v] + 1;
                k = dep[i];
            }
        }
    }

    return k;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, i, j, k, test=0;
    string s1, s2;

    while(scanf("%d %d",&n,&m) == 2){
        if(n==0 && m==0) break;
        N = n;
        clr(mp);
        mem(adj, 0);
        k = 0;
        REP(i, m){
            cin >> s1 >> s2;
            if(mp.find(s1) == mp.end()) mp[s1] = ++k;
            if(mp.find(s2) == mp.end()) mp[s2] = ++k;
            adj[ mp[s1] ][ mp[s2] ] = 1;
            adj[ mp[s2] ][ mp[s1] ] = 1;
        }
        mem(col, 0);
        cnt = 0;
        dfs(1);
        if(cnt != n){
            printf("Network %d: DISCONNECTED\n\n",++test);
            continue;
        }
        k = 0;
        REP1(i, 1, n)
            k = max(k, bfs(i));
        printf("Network %d: %d\n\n",++test,k);
    }


    return 0;
}


