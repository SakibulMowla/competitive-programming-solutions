#include "stdio.h"
#include "string.h"

int cnt[5][5];

int main()
{
    int i,j;
    for(i=1; i<=3; i++)
        for(j=1; j<=3; j++)
            scanf("%d",&cnt[i][j]);
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++)
            printf("%d",(cnt[i][j] + cnt[i-1][j] + cnt[i][j-1] + cnt[i+1][j] + cnt[i][j+1] + 1) % 2);
        printf("\n");
    }
    return 0;
}
