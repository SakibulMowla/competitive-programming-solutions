#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"
#include "set"
#include "queue"
#include "stack"
#include "map"
#include "stdlib.h"
#include "assert.h"
#include "deque"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 1e9;
const int mod = 1;

#define REP(i, n) for(i=0;i<(int)n;i++)
#define REP1(i, a, b) for(i=(int)a;i<=(int)b;i++)
#define REP2(i, a, b) for(i=(int)a;i>=(int)b;i--)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define MP(a, b) make_pair(a, b)
#define mem(a, b) memset(a, b, sizeof(a))

#define SZ 10010

vector <int> adj[SZ];
int distime[SZ], low[SZ], id, tmp;
bool col[SZ], color[SZ];
stack <pii> S;

void bcc(int u, int par){
    distime[u] = low[u] = id++;
    int v, i, k, us, vs, cnt;
    k = sz(adj[u]);

    for(i=0;i<k;i++){
        v = adj[u][i];
        if(v == par) continue;

        if(!distime[v]){
            S.push(MP(u, v));
            bcc(v, u);
            low[u] = min(low[u], low[v]);
            if(distime[u] <= low[v]){
                cnt = 0;
                while(!S.empty()){
                    us = S.top().first;
                    vs = S.top().second;
                    S.pop();
                    cnt++;
                    if(cnt == 1 && u==us && v==vs) break;
                    else if(u==us && v==vs){
                        col[u] = col[v]= true;
                        break;
                    }
                    else{
                        col[us] = col[vs] = true;
                    }
                }
            }
        }

        else if(distime[u] > distime[v])
            low[u] = min(low[u], distime[v]);
    }
}

void dfs(int u, int par){
    color[u] = true;
    tmp++;

    int i, k, v;
    k = sz(adj[u]);

    for(i=0;i<k;i++){
        v = adj[u][i];
        if(v == par) continue;
        if(!color[v] && !col[v]){
            dfs(v, u);
        }
    }

    return;
}


int main(){
//    freopen("1.txt","r",stdin);

    int test=0, t, n, m, u, v, i, j, k, ans;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        id = tmp = ans = 0;
        REP1(i, 0, n) clr(adj[i]), distime[i] = low[i] = col[i] = color[i] = 0;
        while(!S.empty()) S.pop();

        REP(i, m){
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        REP1(i, 1, n) if(!distime[i]) bcc(i, i);
        REP1(i, 1, n){
            if(!col[i] && !color[i]){
                tmp = 0;
                dfs(i, i);
                ans += ((tmp*(tmp-1))/2);
            }
        }

        printf("Case #%d: %d\n",++test,ans);
    }


    return 0;
}



