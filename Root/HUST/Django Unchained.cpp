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

const int inf = 1e9;
const ll mod = 1LL;

#define SZ  1010
#define SZ1 25
#define SZ2 85

int oxygen[SZ];
int nitro[SZ];
int weight[SZ];
int dp[SZ][SZ1][SZ2];
int N;

int solve(int indx, int need_o, int need_n){
    if(need_n == 0 && need_o == 0) return 0;
    if(indx == N) return inf;

    int &ret = dp[indx][need_o][need_n];
    if(ret != -1) return ret;

    ret = inf;
    ret = min(ret, solve(indx+1, need_o, need_n));
    ret = min(ret, weight[indx] + solve(indx+1, max(0, need_o-oxygen[indx]), max(0, need_n-nitro[indx])));

    return ret;
}

int main() {
    int test, need_o, need_n, i, j, k, n;

    scanf("%d",&test);

    while(test--){
        scanf("%d %d",&need_o, &need_n);
        scanf("%d",&n);
        N = n;

        REP(i, n) scanf("%d %d %d",&oxygen[i],&nitro[i],&weight[i]);

        memset(dp, -1, sizeof(dp));

        printf("%d\n",solve(0, need_o, need_n));
    }

    return 0;
}




