#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 100010
#define SZ1 262144

int arr[SZ] , pro[SZ1];

void build(int node,int b,int e)
{
    if(b == e)
    {
        pro[node] = arr[b];
        return;
    }
    int mid = (b + e) / 2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    pro[node] = pro[2*node] * pro[2*node+1];
}

int query(int node,int b,int e,int f,int t)
{
    if(f == t) return arr[f];
    if(b > t || e < f) return 1;
    if(b >= f && e <= t) return pro[node];
    int mid = (b + e) / 2;
    return query(2*node,b,mid,f,t) * query(2*node+1,mid+1,e,f,t);
}

void update(int node,int b,int e,int indx)
{
    if(b == e)
    {
        pro[node] = arr[b];
        return;
    }
    int mid = (b + e) / 2;
    if(indx <= mid) update(2*node,b,mid,indx);
    else update(2*node+1,mid+1,e,indx);
    pro[node] = pro[2*node] * pro[2*node+1];
}

int main()
{
    int n , k , i , j;
    char ch;
    while(2 == scanf("%d %d",&n,&k))
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",arr+i);
            if(arr[i] > 0) arr[i] = 1;
            else if(arr[i] < 0) arr[i] = -1;
        }
        build(1,1,n);
        while(k--)
        {
            scanf(" %c %d %d",&ch,&i,&j);
            if(ch == 'C')
            {
                if(j > 0) j = 1;
                else if(j < 0) j = -1;
                arr[i] = j;
                update(1,1,n,i);
            }
            else
            {
                i = query(1,1,n,i,j);
                if(i > 0) printf("+");
                else if(i < 0) printf("-");
                else printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}
