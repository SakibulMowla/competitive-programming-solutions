#include "stdio.h"
#include "stdlib.h"

int row[10] ,r ,c , soln;

bool check(int n,int m)
{
    int i;
    for(i=1;i<m;i++)
        if(n == row[i] || abs(n-row[i]) == abs(m-i))
            return false;
    return true;
}

void bctk(int col)
{
    int i;
//    printf("col = %d",col);
    if(col == 9)
    {
        printf("%2d     ",++soln);
        for(i=1;i<=8;i++)   printf(" %d",row[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=8;i++)
    {
        if(col == c && i != r) continue;
        if(check(i,col))
        {
            row[col] = i;
            bctk(col+1);
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&r,&c);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        soln = 0;
        bctk(1);
        if(test) printf("\n");
    }

    return 0;
}
