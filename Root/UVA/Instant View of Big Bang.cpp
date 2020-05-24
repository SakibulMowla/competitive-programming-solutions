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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back

const int inf = 1e7;

#define SZ 1010

vector <int> adj[SZ];
vector <int> cost[SZ];
int dist[SZ];
set <int> ms;
bool col[SZ];
bool vis[SZ];
int enter[SZ];
queue <int> Q;

void init(int n){
    int i;
    REP(i, n){
        clr(adj[i]);
        clr(cost[i]);
        col[i] = 0;
        enter[i] = 0;
        dist[i] = 0;
    }
    while(!Q.empty()) Q.pop();
    clr(ms);
}

void dfs(int u){
    col[u] = 1;
    ms.insert(u);

    int i, j, k;

    k = sz(adj[u]);
    REP(i, k){
        j = adj[u][i];
        if(!col[j])
            dfs(j);
    }
}

void queue_bellman(int n){
    int i, u, k, j;

    REP(i, n){
        vis[i] = 1;
        Q.push(i);
    }

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        vis[u] = 0;
        k = sz(adj[u]);

        REP(i, k){
            j = adj[u][i];
            if(dist[j] > dist[u] + cost[u][i]){
                dist[j] = dist[u] + cost[u][i];
                if(vis[j] == 0 && enter[j] <= n){
                    Q.push(j);
                    enter[j]++;
                    vis[j] = 1;
                }
            }
        }
    }
}

int main() {
    int test = 0, t, i, j, k, l, n, m;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        init(n);

        REP(i, m){
            scanf("%d %d %d",&j,&k,&l);
            adj[k].pb(j);
            cost[k].pb(l);
        }

        queue_bellman(n);

        REP(i, n)
            if(enter[i] > n)
                dfs(i);

        printf("Case %d:",++test);
        if(!sz(ms)) printf(" impossible");
        else snuke(ms, it) {printf(" %d",*it);assert(*it<n);}

        puts("");
    }


    return 0;
}













