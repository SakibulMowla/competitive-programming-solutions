#include <bits/stdc++.h>

using namespace  std;


void RD(int &x){scanf("%d",&x);}

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}
//

#define mem(a, b) memset(a, b, sizeof(a))
#define REP1(i, a, b) for((i)=a;(i)<=(int)(b);(i)++)

const int mod = 1000000007;

#define SZ  100010
#define SZ1 262150

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

struct data{
    int val;
    int indx;
};

data arr[SZ];

int tree[SZ1];

int query(int node, int b, int e, int to){
    if(e <= to)
        return tree[node];
    int mid = (b + e) >> 1, ret=0;
    ret = query(left, to);
    if(to > mid) ret = (ret + query(riht, to)) % mod;
    return ret;
}

void update(int node, int b, int e, int indx, int val){
    if(b == e){
        tree[node] = (tree[node] + val) % mod;
        return;
    }
    int mid = (b + e) >> 1;
    if(indx <= mid) update(left, indx, val);
    else            update(riht, indx, val);

    tree[node] = (tree[node<<1] + tree[(node<<1)|1]) % mod;
}

bool comp(data a, data b){
    if(a.val == b.val)
        return a.indx > b.indx;
    return a.val < b.val;
}

int main() {
    int test=0, t, n, i, k;

    RD(t);
//    inp(t);

    while(t--){
        RD(n);
//        inp(n);
        mem(tree, 0);

        REP1(i, 1, n){
            RD(arr[i].val);
//            inp(arr[i].val);
            arr[i].indx = i;
        }

        stable_sort(arr+1, arr+n+1, comp);

        REP1(i, 1, n){
            k = query(1, 0, n, arr[i].indx-1) + 1;
            update(1, 0, n, arr[i].indx, k);
        }

        printf("Case %d: %d\n",++test,tree[1]);
    }


    return 0;
}

