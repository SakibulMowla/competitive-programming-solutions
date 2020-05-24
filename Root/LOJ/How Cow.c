#include <stdio.h>

int main()
{
    int x1,y1,x2,y2,x,y,i,j,k,n,m;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("Case %d:\n",i+1);
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d %d",&x,&y);
            if(x>=x1 && x<=x2 && y>=y1 && y<= y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
