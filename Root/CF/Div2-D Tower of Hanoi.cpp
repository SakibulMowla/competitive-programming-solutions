#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}

#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int cost[4][4];
ll dp[42][3][3][3];

ll solve(int n, int beg, int mid, int end){
    if(n == 1) return min(cost[beg][end], cost[beg][mid]+cost[mid][end]);

    ll &ret = dp[n][beg][mid][end];
    if(ret != -1) return ret;

    ret = solve(n-1, beg, end, mid) + cost[beg][end] + solve(n-1, mid, beg, end);
    ret = min(ret, solve(n-1, beg, mid, end) + cost[beg][mid] + solve(n-1, end, mid, beg) + cost[mid][end] + solve(n-1, beg, mid, end));

    return ret;
}

int main() {
    int i, j, n, k=0;

    REP(i, 3) REP(j, 3) RD(cost[i][j]);
    RD(n);
    mem(dp, -1);
    PR(solve(n, 0, 1, 2));

    return 0;
}















