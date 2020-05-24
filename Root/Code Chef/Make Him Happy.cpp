#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}

#define mem(a,b) memset(a, b, sizeof(a))
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

const int inf = 1e9;

#define SZ 1000010

int arr[SZ];
int frnt[SZ], bck[SZ];

int main() {
    int n, m, i, j, k, ans;

    while(scanf("%d %d",&n,&k) == 2){
        mem(frnt, 0);
        mem(bck, 0);

        REP1(i, 1, n) RD(arr[i]);
        REP1(i, 1, n) if(frnt[arr[i]] == 0) frnt[arr[i]] = i;
        for(i=n,j=1; i>=1; i--,j++) if(bck[arr[i]] == 0) bck[arr[i]] = j;

        ans = inf;

        REP1(i, 1, n) if(k-arr[i] != arr[i] && k-arr[i] >= 0 && frnt[k-arr[i]] != 0) ans = min(ans, max(frnt[arr[i]], frnt[k-arr[i]]));
        REP1(i, 1, n) if(k-arr[i] != arr[i] && k-arr[i] >= 0 && bck[k-arr[i]] != 0) ans = min(ans, max(bck[arr[i]], bck[k-arr[i]]));
        REP1(i, 1, n) if(k-arr[i] != arr[i] && k-arr[i] >= 0 && bck[k-arr[i]] != 0) ans = min(ans, max(frnt[arr[i]], bck[k-arr[i]]));

        printf("%d\n",ans==inf?-1:ans);
    }


    return 0;
}













