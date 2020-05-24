#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}


#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ (1<<15)+5

int dp[SZ];
int arr[20];
int N;

int solve(int mask){
    if(!mask) return 0;
    int &ret = dp[mask];
    if(ret != -1) return ret;

    int i, j, k;
    ret = 0;

    REP(i, N) if(mask&(1<<i))
        REP1(j, i+1, N-1) if(mask&(1<<j))
            REP1(k, j+1, N-1) if(mask&(1<<k))
                if(arr[i]+arr[j]+arr[k] >= 20)
                    ret = max(ret, 1+solve(mask&~(1<<i)&~(1<<j)&~(1<<k)));

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, k, n, test=0;

    while(scanf("%d",&n) == 1 && n){
        REP(i, n) RD(arr[i]);

        k = 1<<n;
        N = n;
        memset(dp, -1, sizeof(int)*(k+2));

        printf("Case %d: %d\n",++test,solve(k-1));
    }


    return 0;
}













