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
#define sz(x) (int)x.size()
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define pb push_back


const int inf = 1e8;

#define SZ 110

int three[12];
int cost[SZ];
vector <int> sub[SZ];
int N, S;
int dp[SZ][7000];

int check(int mask, int pos){
    return (mask/three[pos]) % 3;
}

int Set(int mask, int pos, int val){
    mask -= (val-1) * three[pos];
    mask += val * three[pos];
    return mask;
}

void init(){
    three[0] = 1;
    int i;
    for(i=1;i<=10;i++) three[i] = 3 * three[i-1];
}

int solve(int indx, int mask){
    if(indx == N){
        if(mask == three[S]-1) return 0;
        return inf;
    }

    int &ret = dp[indx][mask];
    if(ret != -1) return ret;

    int tmp, i, k, j, bit;

    ret = solve(indx+1, mask);

    tmp = mask;
    k = sz(sub[indx]);
    REP(i, k){
        j = sub[indx][i];
        bit = check(mask, j);
        if(bit == 0) tmp = Set(tmp, j, 1);
        else if(bit == 1) tmp = Set(tmp, j, 2);
    }

    ret = min(ret, cost[indx] + solve(indx+1, tmp));

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    init();

    int s, m, n, i, j, k, ans, mask;
    char arr[10000], *ss;

    while(scanf("%d %d %d",&s,&m,&n) == 3){
        if(s==0) break;

        ans = 0;
        mask = 0;
        N = n;
        S = s;

        REP(i, m){
            scanf(" %[^\n]",arr);
            ss = strtok(arr," ");
            ans += atoi(ss);
            ss = strtok(NULL, " ");
            while(ss != NULL){
                j = atoi(ss) - 1;
                k = check(mask, j);
                if(k == 0) mask = Set(mask, j, 1);
                else if(k == 1) mask = Set(mask, j, 2);
                ss = strtok(NULL, " ");
            }
        }

        REP(i, n) clr(sub[i]);

        REP(i, n){
            scanf(" %[^\n]",arr);
            ss = strtok(arr," ");
            cost[i] = atoi(ss);
            ss = strtok(NULL, " ");
            while(ss != NULL){
                sub[i].pb( atoi(ss) - 1 );
                ss = strtok(NULL, " ");
            }
        }

        REP1(i, 0, n) REP1(j, 0, three[s]) dp[i][j] = -1;

        printf("%d\n",ans+solve(0, mask));
    }


    return 0;
}

















