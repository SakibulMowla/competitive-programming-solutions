#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int possible[100][10] , row[10];
int solution;

int check(int r,int c)
{
    int pos;
    for(pos=1;pos<c;pos++)
        if(row[pos] == r || abs(pos-c) == abs(r-row[pos]))
            return 0;
    return 1;
}

void backtrack(int col)
{
    int i;
    if(col == 9)
    {
        ++solution;
        for(i=1;i<=8;i++)
            possible[solution][i] = row[i];
        return;
    }
    for(i=1;i<=8;i++)
    {
        if(check(i,col))
        {
            row[col] = i;
            backtrack(col+1);
        }
    }
}

int main()
{
    solution = 0;
    backtrack(1);
    int arr[10],i,j,minimum,optimal,test;
    test = 0;
    while(scanf("%d",&arr[1]) == 1)
    {
        for(i=2;i<=8;i++)
            scanf("%d",&arr[i]);
        optimal = 1000000000;
        for(i=1;i<=92;i++)
        {
            minimum = 0;
            for(j=1;j<=8;j++)
                minimum += ( possible[i][j] - arr[j] ) ? 1 : 0 ;
            if(minimum < optimal)
                optimal = minimum;
        }
        printf("Case %d: %d\n",++test,optimal);
    }

    return 0;
}
