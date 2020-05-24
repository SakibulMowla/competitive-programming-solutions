#include <bits/stdc++.h>
using namespace  std;
#define SZ 110

int arr[SZ], n;
bool mark[SZ];

int cal(int p,int q)
{
    int i, cnt;

    memset(mark, 0, sizeof(mark));
    cnt = 0;

    for(i=1;i<=n;i++)
    {
        if(arr[i] >= p && arr[i] <= q)
        {
            if(!mark[ arr[i]-1 ])
                cnt++;
            mark[ arr[i] ] = 1;
        }
    }

    return cnt;
}

int main()
{
    int q, i, j, k;

    while(scanf("%d",&n) == 1)
    {
        for(i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        cin >> q;
        while(q--)
        {
            scanf("%d %d %d",&k,&i,&j);
            if(k == 2)
                swap(arr[i], arr[j]);
            else
                printf("%d\n",cal(i,j));
        }
    }

    return 0;
}
