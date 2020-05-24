/*
 * Author:  xioumu
 * Created Time:  2012/7/30 12:17:44
 * File Name: c.cpp
 * solve: c.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define sz(v) ((lint)(v).size())
#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define repf(i, a, b) for (lint i = (a); i <= (b); ++i)
#define repd(i, a, b) for (lint i = (a); i >= (b); --i)
typedef long long lint;
const lint maxint = -1u>>1;
const double esp = 1e-8;
const lint maxn = 1007;
lint NUM = 100;
lint n, m;
vector <lint> e[maxn], d[maxn];
lint check[maxn];
lint  dis[maxn], v[maxn];
void add(lint x, lint y, lint z){
    e[x].push_back(y);
    d[x].push_back(z);
}
void gao(lint w){
    if(v[w]) return ;
    v[w] = 1;
    rep(i, sz(e[w])){
        lint j = e[w][i];
        gao(j);
    }
}
queue<lint> que;
void spfa(){

    while( !que.empty() ) que.pop();
    rep (i, n) dis[i] = 1LL << 30;
    memset(v, 0, sizeof(v));
    rep(w, n){
        v[w] = 1;
        dis[w] = 0;
        que.push(w);
    }
    while( !que.empty() ){
        lint k = que.front();
        que.pop();
        v[k] = 0;
        rep (i, sz(e[k])){
            lint j = e[k][i];
            if(dis[j] > dis[k] + d[k][i]){
                dis[j] = dis[k] + d[k][i];
                if(v[j] == 0 && check[j] <= NUM){
                    que.push(j);
                    check[j]++;
                    v[j] = 1;
                }
            }
        }
    }
}
int main() {
    lint T;
    scanf("%lld", &T);
    repf (ca, 1, T){
        scanf("%lld%lld", &n, &m);
        NUM = n;
        rep (i, n){
            e[i].clear();
            d[i].clear();
        }
        repf (i, 1, m){
            lint x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            add(y, x, z);
        }
        memset(check, 0, sizeof(check));
        memset(v, 0, sizeof(v));
        //rep (i, n)
        //if(check[i] == 0)
        spfa();
        vector<lint> ans;
        memset(v, 0, sizeof(v));
        rep (i, n)
            if(check[i] > NUM){
                ans.push_back(0);
                gao(i);
            }
        printf("Case %lld:", ca);
        if( sz(ans) == 0) printf(" impossible\n");
        else {
            rep(i, n)
                if(v[i])
                    printf(" %d", i);
            printf("\n");
        }
    }
    return 0;
}
