#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 100010

int cnt[12][310][310];

int main(){
    int i, j, k, n, q, ans;
    int x1, y1, x2, y2;

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&k);
            cnt[k][i][j] = 1;
        }
    }

    for(k=1;k<=10;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cnt[k][i][j] += cnt[k][i][j-1];
            }
        }
    }

    for(k=1;k<=10;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cnt[k][j][i] += cnt[k][j-1][i];
            }
        }
    }

    scanf("%d",&q);

    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        ans = 0;

        for(k=1;k<=10;k++)
            if( (cnt[k][x2][y2]-cnt[k][x1-1][y2]) - (cnt[k][x2][y1-1]-cnt[k][x1-1][y1-1]) )
                ans++;

        printf("%d\n",ans);
    }


    return 0;
}

















