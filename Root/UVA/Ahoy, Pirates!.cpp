#include <bits/stdc++.h>

using namespace  std;


void RD(int &x){scanf("%d",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(char *s){scanf("%s",s);}

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)


#define SZ  1024010
#define SZ1 2097172

#define left node<<1, b, mid
#define riht node<<1|1, mid+1, e

int arr[SZ];
int tree[SZ1];
int lazy[SZ1];

struct Problem {
    int test, n, m, r, pos, i, j, k, q;
    char s[55], ch;
    Problem();
    void take_input();
    void process();
    void build(int,int,int);
    void update(int,int,int,int,int,int);
    int query(int,int,int,int,int);
    void propagate(int,int,int);
};


Problem::Problem() {
    test = 0;
}


void Problem::take_input() {
    RD(m);
    n = 0;
    while(m--){
        RD(r);
        RD(s);
        k = strlen(s);
        while(r--) REP(i, k) arr[++n] = s[i]-'0';
    }
}


void Problem::process() {
    build(1, 1, n);
    RD(q);
    int cnt = 0;

    printf("Case %d:\n",++test);

    while(q--){
        scanf(" %c %d %d",&ch,&i,&j);
        if(ch == 'F') update(1, 1, n, ++i, ++j, 1);
        else if(ch == 'E') update(1, 1, n, ++i, ++j, 0);
        else if(ch == 'I') update(1, 1, n, ++i, ++j, 2);
        else if(ch == 'S') printf("Q%d: %d\n",++cnt, query(1, 1, n, ++i, ++j));
    }
}


void Problem::build(int node, int b, int e) {
    if(b == e) {
        tree[node] = arr[b];
        lazy[node] = -1;
        return;
    }

    int mid = (b + e) >> 1;

    build(left);
    build(riht);

    tree[node] = tree[node<<1] + tree[node<<1|1];
    lazy[node] = -1;
}


void Problem::update(int node, int b, int e, int f, int t, int val) {
    if(b>=f && e<=t){
        if(val != 2){
            tree[node] = (e-b+1) * val;
            lazy[node] = val;
        }
        else {
            tree[node] = (e-b+1) - tree[node];
            if(lazy[node] == 0) lazy[node] = 1;
            else if(lazy[node] == 1) lazy[node] = 0;
            else if(lazy[node] == 2) lazy[node] = -1;
            else if(lazy[node] == -1) lazy[node] = 2;
        }
        return;
    }

    propagate(node, b, e);

    int mid = (b + e) >> 1;

    if(f <= mid) update(left, f, t, val);
    if(t > mid) update(riht, f, t, val);

    tree[node] = tree[node<<1] + tree[node<<1|1];
}


void Problem::propagate(int node, int b, int e) {
    if(lazy[node] != -1 && b!=e) {
        int mid = (b + e) >> 1;
        if(lazy[node] != 2) {
            tree[node<<1] = (mid-b+1) * lazy[node];
            tree[node<<1|1] = (e-mid) * lazy[node];

            lazy[node<<1] = lazy[node<<1|1] = lazy[node];
        }
        else {
            tree[node<<1] = (mid-b+1) - tree[node<<1];
            tree[node<<1|1] = (e-mid) - tree[node<<1|1];

            if(lazy[node<<1] == 0) lazy[node<<1] = 1;
            else if(lazy[node<<1] == 1) lazy[node<<1] = 0;
            else if(lazy[node<<1] == 2) lazy[node<<1] = -1;
            else if(lazy[node<<1] == -1) lazy[node<<1] = 2;

            if(lazy[node<<1|1] == 0) lazy[node<<1|1] = 1;
            else if(lazy[node<<1|1] == 1) lazy[node<<1|1] = 0;
            else if(lazy[node<<1|1] == 2) lazy[node<<1|1] = -1;
            else if(lazy[node<<1|1] == -1) lazy[node<<1|1] = 2;
        }
        lazy[node] = -1;
    }
}


int Problem::query(int node, int b, int e, int f, int t) {
    if(b>=f && e<=t)
        return tree[node];

    propagate(node, b, e);

    int mid = (b + e) >> 1, ret = 0;

    if(f <= mid) ret = query(left, f, t);
    if(t > mid) ret += query(riht, f, t);

    return ret;
}


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    Problem Pirates;
    int t;

    RD(t);

    while(t--){
        Pirates.take_input();
        Pirates.process();
    }


    return 0;
}













