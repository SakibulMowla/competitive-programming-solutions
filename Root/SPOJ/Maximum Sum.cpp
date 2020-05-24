#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 100010
#define SZ1 262145

int order[4] , input[SZ];
struct data{int mx1,mx2;};
data seg[SZ1];

void build(int node,int b,int e)
{
    if(b == e)
    {
        seg[node].mx1 = input[b];
        seg[node].mx2 = -1;
        return;
    }
    int mid = (b + e) / 2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    order[0] = seg[2*node].mx1 , order[1] = seg[2*node].mx2 , order[2] = seg[2*node+1].mx1 , order[3] = seg[2*node+1].mx2;
    sort(order,order+4);
    seg[node].mx1 = order[2] , seg[node].mx2 = order[3];
    return;
}

void update(int node,int b,int e,int indx)
{
    if(b == e)
    {
        seg[node].mx1 = input[b];
        seg[node].mx2 = -1;
        return;
    }
    int mid = (b + e) / 2;
    if(indx <= mid) update(2*node,b,mid,indx);
    else update(2*node+1,mid+1,e,indx);
    order[0] = seg[2*node].mx1 , order[1] = seg[2*node].mx2 , order[2] = seg[2*node+1].mx1 , order[3] = seg[2*node+1].mx2;
    sort(order,order+4);
    seg[node].mx1 = order[2] , seg[node].mx2 = order[3];
    return;
}

data query(int node,int b,int e,int f,int t)
{
    data tmp,tmp1,tmp2;
    if(b > t || e < f)
    {
        tmp.mx1 = -1;
        tmp.mx2 = -1;
        return tmp;
    }
    if(b >= f && e <= t) {return seg[node];}
    int mid = (b + e) / 2;
    tmp1 = query(2*node,b,mid,f,t);
    tmp2 = query(2*node+1,mid+1,e,f,t);
    order[0] = tmp1.mx1 , order[1] = tmp1.mx2 , order[2] = tmp2.mx1 , order[3] = tmp2.mx2;
    sort(order,order+4);
    tmp.mx1 = order[2] , tmp.mx2 = order[3];
    return tmp;
}

int main()
{
    int n,q,i,j,k;
    char ch;
    data tmp;
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++) scanf("%d",&input[i]);
        build(1,1,n);
        scanf("%d",&q);
        while(q--)
        {
            scanf(" %c %d %d",&ch,&j,&k);
            if(ch == 'Q')
            {
                tmp = query(1,1,n,j,k);
                printf("%d\n",tmp.mx1+tmp.mx2);
            }
            else if(ch == 'U')
            {
                input[j] = k;
                update(1,1,n,j);
            }
        }
    }

    return 0;
}
