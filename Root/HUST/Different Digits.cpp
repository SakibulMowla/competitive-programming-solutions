#include "stdio.h"
#include "string.h"

bool col[12];

bool chk(int n)
{
    memset(col, 0, sizeof(col));
    while(n)
    {
        if(col[n%10])
            return 0;
        col[n%10] = 1;
        n /= 10;
    }
    return 1;
}

int main()
{
    int i, j, k, cnt, n, m;

    while(scanf("%d %d",&n,&m) == 2)
    {
        cnt = 0;
        for(i=n;i<=m;i++)
            if(chk(i))
                cnt++;
        printf("%d\n",cnt);
    }

    return 0;
}
