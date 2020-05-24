#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"
#include "set"
#include "queue"
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

#define SZ 65

ll dp[SZ][SZ][SZ];
int N;

ll solve(int day, int half, int whol){
//    printf("%d %d %d\n",day,half,whol);
    if(day == N) return 1LL;

    ll &ret = dp[day][half][whol];
    if(ret != -1) return ret;

    ret = 0;
    if(half){
        ret += solve(day+1, half-1, whol);
    }
    if(whol){
        ret += solve(day+1, half+1, whol-1);
    }

    return ret;
}


int main(){
//    freopen("1.txt","r",stdin);

    int n, i, j, k;

    memset(dp, -1, sizeof(dp));

    while(scanf("%d",&n) == 1 && n){
        n *= 2;
        N = n;
        printf("%lld\n",solve(0, 0, n/2));
    }

    return 0;
}



