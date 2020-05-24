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

#define clr(a) (a.clear())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define pb push_back
#define sz(a) ( (int)a.size() )

const int inf = 1e9;

#define SZ  4010
#define SZ1 30
#define SZ2 55

struct data{
    int to, cost;
    char ch;
    data(){}
    data(int a, int b, char c){
        to = a;
        cost = b;
        ch = c;
    }
    bool operator < (const data &x) const{
        return cost > x.cost;
    }
};

map <string , int> mp;
vector <data> adj[SZ];
priority_queue <data> pq;
int dist[SZ][SZ1];

int dijkstra(int n, int st, int gt){
    int i, j, k, w, node;
    char ch1, ch2;
    data u;

    REP(i, n) REP(j, 26) {
        if(i == st) dist[i][j] = 0;
        else dist[i][j] = inf;
    }
    pq.push( data(st, 0, char('a'+26)) );
    dist[st][26] = 0;

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        k = sz(adj[u.to]);
        node = u.to;
        ch1 = u.ch;

        REP(i, k){
            ch2 = adj[node][i].ch;
            if(ch1 == ch2) continue;
            w = adj[node][i].cost;
            j = adj[node][i].to;
            if(dist[j][ch2-'a'] > dist[node][ch1-'a'] + w){
                dist[j][ch2-'a'] = dist[node][ch1-'a'] + w;
                pq.push( data(j, dist[j][ch2-'a'], ch2) );
            }
        }
    }

    k = inf;
    REP(i, 26)
        k = min(k, dist[gt][i]);

    return k;
}


int main(){
    int n, i, k, ver, p, q, st, gt;
    char lan1[SZ2], lan2[SZ2], word[SZ2], strt[SZ2], trgt[SZ2];

    while(scanf("%d",&n) == 1 && n){
        while(!pq.empty()) pq.pop();
        clr(mp);
        REP(i, 2*n) clr(adj[i]); /// there can be 2*n languages in n lines
        ver = 0;

        scanf("%s %s",strt,trgt);
        st = mp[strt] = ver++;
        if(mp.find(trgt) == mp.end())
            gt = mp[trgt] = ver++;
        else gt = mp[trgt];

        while(n--){
            scanf("%s %s %s",lan1,lan2,word);

            k = strlen(word);

            if(mp.find(lan1) == mp.end()) p = mp[lan1] = ver++;
            else p = mp[lan1];
            if(mp.find(lan2) == mp.end()) q = mp[lan2] = ver++;
            else q = mp[lan2];

            adj[p].pb( data( q, k, word[0]) );
            adj[q].pb( data( p, k, word[0]) );
        }

        k = dijkstra(ver, st, gt);

        k == inf ? printf("impossivel\n") : printf("%d\n",k);
    }


    return 0;
}

















