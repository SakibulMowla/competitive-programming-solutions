#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define SZ 20010

vector <int> adj[SZ];
//vector <int> point;
int distime[SZ], height[SZ];
int root, col[SZ], id;

vector <int> group[SZ];

int comp_id[SZ], comp_cnt[SZ];
int now_id, now_cnt;

void compo_dfs(int u){
    comp_id[u] = now_id;
    now_cnt++;

    int i, j, k;

    k = adj[u].size();

    for(i=0; i<k; i++){
        j = adj[u][i];
        if(comp_id[j] == 0){
            compo_dfs(j);
        }
    }
}

int art_point(int u, int par){
    int i, v, k, child=0, tmp;
    int tot=1;

    distime[u] = height[u] = id++;
    k = adj[u].size();

    for(i=0; i<k; i++){
        v = adj[u][i];
        if(v == par) continue;
        if(!distime[v]){
            child++;
            tot += (tmp=art_point(v, u));
            height[u] = min(height[u], height[v]);
            if(distime[u] <= height[v] && u!=root){
//                point.push_back(u);
                col[u] = true;
            }
            group[u].push_back(tmp);
        }
        else if(distime[u] > distime[v])
            height[u] = min(height[u], distime[v]);
    }

    if(u==root && child >= 2){
        col[u] = true;
//        point.push_back(u);
    }

    group[u].push_back(comp_cnt[ comp_id[u] ]-tot);

    return tot;
}




int main(){
    #if defined JESI
        freopen("1.txt","r",stdin);
    #endif // defined

    int test=0, t, n, m, i, j, k, p, q;
    ll res;

    scanf("%d",&t);

    while(t--){
        res = 0LL;
        scanf("%d %d",&n,&m);

        for(i=0; i<=n; i++) adj[i].clear(), group[i].clear();
        memset(distime, 0, sizeof(distime));
        memset(height, 0, sizeof(height));
        memset(col, 0, sizeof(col));

        for(i=0; i<m; i++){
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        memset(comp_cnt, 0, sizeof(comp_cnt));
        memset(comp_id, 0, sizeof(comp_id));
        now_id = 0;

        for(i=1; i<=n; i++){
            if(comp_id[i] == 0){
                ++now_id;
                now_cnt = 0;
                compo_dfs(i);
                comp_cnt[now_id] = now_cnt;
            }
        }

        id = 1;
        for(i=1; i<=n; i++){
            if(!distime[i]){
                root = i;
                art_point(i, i);
            }
        }

        for(i=1; i<=n; i++){
            if(col[i] == 1){
                k = group[i].size();
                for(p=0; p<k; p++)
                    res += (ll)group[i][p] * (ll)(comp_cnt[ comp_id[i] ]-group[i][p]-1LL);
            }
        }

//        res <<= 1LL;

        printf("Case %d: %lld\n",++test,res);
    }

    return 0;
}


