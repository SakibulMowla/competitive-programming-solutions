#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}



#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ 45
#define SZ1 SZ*SZ

int par[SZ1];
int cnt[SZ1];
int arr[SZ][SZ];
int edge;
int node;

struct data{
    int x, y, c1, c2;
    data(){}
    data(int a, int b, int c, int d){
        x = a, y = b, c1 = c, c2 = d;
    }
};

data adj[2*SZ1];

int find(int r){
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void init(){
    int i;

    REP1(i, 0, node) par[i] = i, cnt[i] = 1;
}

int solve(int lo, int hi){
    init();

    int i, x, y, ret;

    ret = 0;

    REP(i, edge){
        if(adj[i].c1>=lo && adj[i].c1<=hi && adj[i].c2>=lo && adj[i].c2<=hi){
            x = find(adj[i].x);
            y = find(adj[i].y);
            if(x != y){
                par[y] = x;
                cnt[x] += cnt[y];
            }
            ret = max(ret, cnt[x]);
        }
    }

    return ret;
}

bool ok(int range, int k){
    int lo;

    for(lo=0;lo+range<=99;lo++)
        if(solve(lo, lo+range) >= k)
            return true;

    return false;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
    #endif // defined

    int r, c, i, j, lo, hi, mid, ans, q, k;

    scanf("%d %d",&r,&c);

    node = r * c;
    edge = 0;

    REP(i, r) REP(j, c) {
        scanf("%d",&arr[i][j]);
//        inp(arr[i][j]);
        if(i-1>=0) adj[edge++] = data(i*c+j, (i-1)*c+j, arr[i][j], arr[i-1][j]);
        if(j-1>=0) adj[edge++] = data(i*c+j, i*c+(j-1), arr[i][j], arr[i][j-1]);
    }

    scanf("%d",&q);
//    inp(q);

    while(q--){
        scanf("%d",&k);
//        inp(k);

        if(k <= 1){
            puts("0");
            continue;
        }

        lo = 0;
        hi = 99;
        ans = 99;

        while(lo <= hi){
            mid = (lo+hi) >> 1;
            if(ok(mid, k))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        printf("%d\n",ans);
    }


    return 0;
}













