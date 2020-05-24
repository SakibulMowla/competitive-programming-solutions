#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}

void PR(int x) {printf("%d\n",x);}


#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ  1002
#define SZ1 2050

bool arr[SZ][SZ];
int tree[SZ1][SZ1];

void update_1D(int node_2D, int node_1D, int colb, int cole, int col){
    tree[node_2D][node_1D]++;
    if(colb == cole) return;

    int mid = (colb + cole) >> 1;

    if(col <= mid) update_1D(node_2D, node_1D<<1, colb, mid, col);
    else           update_1D(node_2D, (node_1D<<1)|1, mid+1, cole, col);
}


void update_2D(int node_2D, int rowb, int rowe, int row, int col){
    update_1D(node_2D, 1, 0, 1000, col);
    if(rowb == rowe) return;

    int mid = (rowb + rowe) >> 1;

    if(row <= mid) update_2D(node_2D<<1, rowb, mid, row, col);
    else           update_2D((node_2D<<1)|1, mid+1, rowe, row, col);
}


int query_1D(int node_2D, int node_1D, int colb, int cole, int colf, int colt){
    if(colb >= colf && cole <= colt)
        return tree[node_2D][node_1D];

    int mid = (colb + cole) >> 1, ret = 0;

    if(colf <= mid) ret = query_1D(node_2D, node_1D<<1, colb, mid, colf, colt);
    if(colt > mid) ret += query_1D(node_2D, (node_1D<<1)|1, mid+1, cole, colf, colt);

    return ret;
}


int query_2D(int node_2D, int rowb, int rowe, int rowf, int rowt, int colf, int colt){
    if(rowb >= rowf && rowe <= rowt)
        return query_1D(node_2D, 1, 0, 1000, colf, colt);

    int mid = (rowb + rowe) >> 1, ret = 0;

    if(rowf <= mid) ret = query_2D(node_2D<<1, rowb, mid, rowf, rowt, colf, colt);
    if(rowt > mid) ret += query_2D((node_2D<<1)|1, mid+1, rowe, rowf, rowt, colf, colt);

    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt","r",stdin);
        freopen("3.txt","w",stdout);
    #endif // defined

    int test=0, t, q, k, r, c, ux, uy, lx, ly;

    RD(t);

    while(t--){
        mem(arr, 0);
        mem(tree, 0);
        RD(q);

        printf("Case %d:\n",++test);

        while(q--){
            RD(k);
            if(k == 0){
                RD(r, c);
                if(arr[r][c]) continue;
                update_2D(1, 0, 1000, r, c);
                arr[r][c] = 1;
            }
            else{
                RD(ux, uy);
                RD(lx, ly);
                PR(query_2D(1, 0, 1000, ux, lx, uy, ly));
            }
        }
    }


    return 0;
}












