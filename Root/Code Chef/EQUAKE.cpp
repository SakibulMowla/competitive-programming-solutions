#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}

void PR(int x) {printf("%d\n",x);}


#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ  800000+10
#define SZ1 2097152+10

int arr[SZ][12];
char s[4];
int tree[SZ1][12], lazy[SZ1];

int prep(){
    int i, k;
    char c=s[0];
    k = strlen(s);
    for(i=0; i<k-1; i++)
        s[i] = s[i+1];
    s[k-1] = c;
}

void build(int node, int b, int e){
    int i;

    if(b == e){
        REP(i, 12) tree[node][i] = arr[b][i];
        return;
    }

    int mid = (b+e) >> 1;

    build(node*2, b, mid);
    build(node*2+1, mid+1, e);

    REP(i, 12)
        tree[node][i] = max(tree[node*2][i], tree[node*2+1][i]);

    return;
}

void shift(int node, int indx){
    int i, tmp[12];
    REP(i, 12) tmp[i] = tree[node][i];
    REP(i, 12) tree[node][i] = tmp[(i+indx)%12];
    return;
}

void propagate(int node){
    int l = node*2, r = l+1;

    lazy[l] = (lazy[l] + lazy[node]) % 12;
    lazy[r] = (lazy[r] + lazy[node]) % 12;

    if(lazy[node]){
        shift(l, lazy[node]);
        shift(r, lazy[node]);
    }

    lazy[node] = 0;
    return;
}

void update(int node, int b, int e, int f, int t, int val){
    if(b>=f && e<=t){
        lazy[node] = (lazy[node] + val) % 12;
        if(val%12) shift(node, val%12);
        return;
    }

    int i, mid = (b+e) >> 1;

    propagate(node);

    if(f <= mid) update(node*2, b, mid, f, t, val);
    if(t > mid) update(node*2+1, mid+1, e, f, t, val);

    REP(i, 12)
        tree[node][i] = max(tree[node*2][i], tree[node*2+1][i]);

    return;
}

int query(int node, int b, int e, int f, int t){
    if(b>=f && e<=t)
        return tree[node][0];

    int i, mid = (b+e) >> 1, res=0;

    propagate(node);

    if(f <= mid) res = query(node*2, b, mid, f, t);
    if(t > mid) res = max(res, query(node*2+1, mid+1, e, f, t));

    return res;
}

int main() {
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
//    #endif

    int i, j, k, n, m, type;

    RD(n);
    REP1(i, 1, n){
        scanf("%s",s);
        arr[i][0] = atoi(s);
        REP1(j, 1, 11){
            prep();
            arr[i][j] = atoi(s);
        }
    }

    build(1, 1, n);

    RD(m);
    while(m--){
        RD(type);
        RD(i, j);
        i++, j++;

        if(type == 0){
            RD(k);
            update(1, 1, n, i, j, k);
        }
        else{
            PR(query(1, 1, n, i, j));
        }
    }

    return 0;
}














