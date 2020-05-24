#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define inf 1<<29
int main()
{
    int i,j,k,l,mini,maximin,m;
    char arr[1000][1000];
    while(scanf("%d",&m) == 1)
    {
        for(i=0; i<m; i++)
            scanf("%s",arr[i]);
        maximin = 0;
        for(i=0; i<m; i++)
            for(j=0; j<m; j++)
                if(arr[i][j] == '1')
                {
                    mini = inf;
                    for(k=0; k<m; k++)
                        for(l=0; l<m; l++)
                            if(arr[k][l] == '3' && abs(i-k) + abs(j-l) < mini)
                                mini = abs(i-k) + abs(j-l);

                    if(mini > maximin)
                        maximin = mini;
                }
        printf("%d\n",maximin);
    }
    return 0;
}
