#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 510
#define SZ1 1024

struct data
{
    int mx , mn;
}info[SZ][SZ1];

int max(int a,int b) { return a > b ? a : b; }
int min(int a,int b) { return a < b ? a : b; }

int input[SZ][SZ] , maxim , minim;
const int inf = 1<<28;

void build(int row,int node,int b,int e)
{
    if(b == e)
    {
        info[row][node].mn = input[row][b];
        info[row][node].mx = input[row][b];
        return;
    }
    int mid = (b + e) / 2;
    build(row, 2*node, b, mid);
    build(row, 2*node+1, mid+1, e);
    info[row][node].mx = max(info[row][2*node].mx , info[row][2*node+1].mx);
    info[row][node].mn = min(info[row][2*node].mn , info[row][2*node+1].mn);
}

void query(int row,int node,int b,int e,int f,int t)
{
    if(b > t || e < f) return;
    if(b >= f && e <= t)
    {
        maxim  = max(maxim , info[row][node].mx);
        minim  = min(minim , info[row][node].mn);
        return;
    }
    int mid = (b + e) / 2;
    query(row, 2*node, b, mid, f, t);
    query(row, 2*node+1, mid+1, e, f, t);
}

void update(int row,int col,int node,int b,int e)
{
    if(b == e)
    {
        info[row][node].mx = input[row][col];
        info[row][node].mn = input[row][col];
        return;
    }
    int mid = (b + e) / 2;
    if(col <= mid) update(row, col, 2*node, b, mid);
    else update(row, col, 2*node+1, mid+1, e);
    info[row][node].mx = max(info[row][2*node].mx , info[row][2*node+1].mx);
    info[row][node].mn = min(info[row][2*node].mn , info[row][2*node+1].mn);
}

int main()
{
    int i,j,n,q,a,b,c,d;
    char ch;
    scanf("%d %d",&n,&n);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&input[i][j]);
    for(i=1;i<=n;i++)
    {
        build(i,1,1,n);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %c",&ch);
        if(ch == 'q')
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            maxim = -inf;
            minim = inf;
            for(i=a;i<=c;i++)
            {
                query(i,1,1,n,b,d);
            }
            printf("%d %d\n",maxim,minim);
        }
        else if(ch == 'c')
        {
            scanf("%d %d %d",&a,&b,&c);
            input[a][b] = c;
            update(a,b,1,1,n);
        }
    }

    return 0;
}
