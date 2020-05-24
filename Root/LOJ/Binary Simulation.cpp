#include "stdio.h"
#include "string.h"

#define SZ1 100010
#define SZ2 3*100010

int arr[SZ1], lazy[SZ2];

inline void read (int &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

void build(int b,int e,int node)
{
//    printf("node = %d b = %d e = %d\n",node,b,e);
    if(b == e)
    {
        lazy[node] = 0;
        return;
    }

    int mid = (b+e) >> 1, left = node<<1, right = left+1;

    build(b, mid, left);
    build(mid+1, e, right);

    lazy[node] = 0;
}

void update(int b,int e,int node,int f,int t)
{
//    printf("node = %d b = %d e = %d\n",node,b,e);
    if(f>e || t<b) return;

    if(b >= f && e <= t)
    {
        lazy[node]++;
//        lazy[node] %= 2;
        return;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left+1;

    lazy[left] = (lazy[left] + lazy[node]) % 2;
    lazy[right] = (lazy[right] + lazy[node]) % 2;

    lazy[node] = 0;

    if(f <= mid) update(b, mid, left, f, t);
    if(t > mid) update(mid+1, e, right, f, t);
}

int query(int b,int e,int node,int indx)
{
    if(b == e)
    {
//        printf("b=%d e=%d indx=%d node=%d lazy=%d arr=%d\n",b,e,indx,node,lazy[node],arr[indx]);
        return (arr[indx] + lazy[node]) % 2;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left + 1;

    lazy[left] = (lazy[left] + lazy[node]) % 2;
    lazy[right] = (lazy[right] + lazy[node]) % 2;

    lazy[node] = 0;

    if(indx <= mid) return query(b, mid, left, indx);
    else return query(mid+1, e, right, indx);
}

int main()
{
//    freopen("1.txt","r",stdin);
    char ch, s[SZ1];
    int t=0, test, i, j, k, n, q;

    read(test);

    while(test--)
    {
        scanf("%s",s+1);
        for(i=1;s[i];i++)   arr[i] = s[i] - '0';
        n = i-1;
        build(1, n, 1);

        read(q);

        printf("Case %d:\n",++t);

        while(q--)
        {
            scanf(" %c",&ch);
            if(ch == 'I')
            {
                read(i);
                read(j);
                update(1, n, 1, i, j);
            }
            else
            {
                read(i);
                printf("%d\n",query(1, n, 1, i));
            }
        }
    }

    return 0;
}
