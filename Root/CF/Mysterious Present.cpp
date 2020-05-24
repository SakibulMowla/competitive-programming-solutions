#include "stdio.h"
#include "string.h"

#define SZ 5010

int w[SZ] , h[SZ] , box[SZ] , to[SZ] , n;

int dfs(int p)
{
    if(box[p]) return box[p];
    int i;
    for(i=0;i<=n;i++)
        if(w[i] > w[p] && h[i] > h[p])
            if(dfs(i) + 1 > box[p])
                box[p] = dfs(i) + 1 , to[p] = i;
    return box[p];
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d %d",w+i,h+i);
        to[i] = -1;
    }

    printf("%d\n",dfs(0));

    for(i=to[0];i!=-1;i=to[i])
        printf("%d ",i);

    return 0;
}
