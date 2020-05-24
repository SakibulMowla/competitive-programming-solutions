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
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)


#define SZ  10010
#define SZ1 100010

struct data{
    int x, y, c;
    data(){}
    data(int a, int b, int d){
        x = a, y = b, c = d;
    }
};

bool comp(data p, data q){
    return p.c > q.c;
}

int par[SZ];
int rank[SZ];
data road[SZ1];

void init(int n){
    int i;
    REP1(i, 0, n){
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int r){
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(int a, int b){
    if(rank[a] > rank[b]) par[b] = a;
    else par[a] = b;
    if(rank[a] == rank[b]) rank[b]++;
}

int MST(int n, int m){
    sort(road, road+m, comp);

    int i, k, sum, x, y;

    for(i=0,k=0,sum=0; i<m && k<n-1; i++){
        x = find(road[i].x);
        y = find(road[i].y);
        if(x == y) continue;
        Union(x, y);
        sum += road[i].c;
        k++;
    }

    return sum;
}

int main() {
    int test, n, m, i, j, k, l, sum;

    scanf("%d",&test);
//    inp(test);

    while(test--){
        scanf("%d %d",&n,&m);
//        inp(n);
//        inp(m);
        init(n);
        sum = 0;

        REP(i, m){
            scanf("%d %d %d",&j,&k,&l);
//            inp(j);
//            inp(k);
//            inp(l);
            road[i] = data(j, k, l);
            sum += l;
        }

        printf("%d\n",sum-MST(n, m));
    }

    scanf("%d",&n);
//    inp(n);

    return 0;
}
















