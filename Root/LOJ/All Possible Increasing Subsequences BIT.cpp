#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}
//
//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define SZ 100010

const int mod = 1000000007;

struct data{
    int val, indx;
};

data arr[SZ];

bool comp(data a, data b){
    if(a.val == b.val)
        return a.indx > b.indx;
    return a.val < b.val;
}

int n;
int tree[SZ];

void update(int indx, int val){
    while(indx <= n){
        tree[indx] += val;
        if(tree[indx] >= mod)
            tree[indx] -= mod;
        indx += (indx & -indx);
    }
}

int query(int indx){
    int sum = 0;
    while(indx > 0){
        sum += tree[indx];
        if(sum >= mod)
            sum -= mod;
        indx -= (indx & -indx);
    }
    return sum;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, i, j;

    RD(t);
//    inp(t);

    while(t--){
        RD(n);
//        inp(n);
        memset(tree, 0, sizeof(int)*(n+2));

        REP1(i, 1, n){
            RD(arr[i].val);
//            inp(arr[i].val);
            arr[i].indx = i;
        }

        stable_sort(arr+1, arr+1+n, comp);

        REP1(i, 1, n){
            j = query(arr[i].indx-1) + 1;
            update(arr[i].indx, j);
        }

        printf("Case %d: %d\n",++test,query(n));
    }


    return 0;
}

