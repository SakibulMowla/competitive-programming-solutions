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
#define mem(a, b) memset(a, b, sizeof(a))

#define SZ 1010

struct data{
    char ss[110];
    int ddl, tym;
};

data arr[20];

int dp[(1<<15)+10];
int path[(1<<15)+10];
int take[(1<<15)+10];
int N;

int solve(int mask, int day){
    int &ret = dp[mask];
    if(!mask)
        return ret = 0;
    if(ret != -1) return ret;

    int i, tmp;
    ret = inf;

    REP(i, N) if(mask&(1<<i)){
        if(day+arr[i].tym > arr[i].ddl) tmp = day+arr[i].tym - arr[i].ddl;
        else tmp = 0;
        tmp += solve(mask&~(1<<i), day+arr[i].tym);
        if(tmp < ret){
            ret = tmp;
            path[mask] = mask&~(1<<i);
            take[mask] = i;
        }
    }

    return ret;
}

void path_print(int mask){
    if(!mask) return;
    printf("%s\n",arr[ take[mask] ].ss);
    return path_print(path[mask]);
}

int main(){
//    freopen("1.txt","r",stdin);

    int t, n, m, i, j, k;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        N = n;
        REP(i, n){
            scanf("%s %d %d",arr[i].ss,&arr[i].ddl,&arr[i].tym);
        }
        k = (1<<n)-1;
        mem(dp, -1);
        printf("%d\n",solve(k, 0));
        path_print(k);
    }


    return 0;
}




