#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int deg[210] , n , r , n1 , n2 , i , cnt;
    while(scanf("%d %d",&n,&r) == 2)
    {
        for(i=0;i<n;i++) deg[i] = 0;
        for(i=0;i<r;i++)
        {
            scanf("%d %d",&n1,&n2);
            deg[n1]++;
            deg[n2]++;
        }
        cnt = 0;
        for(i=0;i<n;i++)
        {
            if( deg[i]!=0 && !(deg[i]%2)) cnt++;
        }
        if(cnt == n) printf("Possible\n");
        else printf("Not Possible\n");
    }

    return 0;
}
