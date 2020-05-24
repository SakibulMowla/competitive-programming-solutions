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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

#define SZ  200010

struct data{
    int a, b;
    ll c;
};

bool comp(data p, data q){
    return p.c > q.c;
}

data info[SZ];
ll cnt[SZ], cost[SZ];
int par[SZ];

void init(int n){
    int i;
    for(i=1; i<=n; i++){
        par[i] = i;
        cnt[i] = 1;
        cost[i] = 0;
    }
}

int find(int r){
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

int main() {
    int i, n, x, y, z;

    while(scanf("%d",&n) == 1){
        init(n);

        REP(i, n-1){
            scanf("%d %d %lld",&info[i].a,&info[i].b,&info[i].c);
        }

        stable_sort(info, info+n-1, comp);

        REP(i, n-1){
            x = find(info[i].a);
            y = find(info[i].b);
            if(cost[x] + info[i].c * cnt[y] > cost[y] + info[i].c * cnt[x]){
                cost[x] += info[i].c * cnt[y];
                cnt[x] += cnt[y];
                par[y] = x;
            }
            else{
                cost[y] += info[i].c * cnt[x];
                cnt[y] += cnt[x];
                par[x] = y;
            }
        }

        x = find(1);
        printf("%lld\n",cost[x]);
    }

    return 0;
}






