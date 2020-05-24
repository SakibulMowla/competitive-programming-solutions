#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define FOR(a,b) for(a=1;a<=b;a++)
#define FOR1(a,b) for(a=1;a<b;a++)

int board[9][9] , col[9];
int maxsum;

int check(int r,int c)
{
    int i;
    FOR1(i,r)
    {
        if(col[i] == c || abs(c-col[i]) == abs(r-i))
            return 0;
    }
    return 1;
}

void backtrack(int r)
{
    if(r == 9)
    {
        int i,sum = 0;
        FOR(i,8)
            sum+=board[i][col[i]];
        if(sum>maxsum)
            maxsum = sum;
        return;
    }
    int c;
    FOR(c,8)
    {
        if(check(r,c))
        {
            col[r] = c;
            backtrack(r+1);
        }
    }
}

int main()
{
    int k,i,j;
    scanf("%d",&k);
    while(k--)
    {
        FOR(i,8)FOR(j,8)scanf("%d",&board[i][j]);
        maxsum = 0 ;
        backtrack(1);
        printf("%5d\n",maxsum);
    }

    return 0;
}
