#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FOR(a,b) for(a=1;a<=b;a++)
#define FOR1(a,b) for(a=1;a<b;a++)

int row[9];
int solution,rr,cc;

bool check(int r,int c)
{
    int pos;
    FOR1(pos,c)
        if(row[pos] == r || abs(c-pos) == abs(r-row[pos]))
            return false;

    return true;
}

void backtrack(int col)
{
    int i;
    if(col == 9)
    {
        printf("%2d     ",++solution);
        FOR(i,8)
            printf(" %d",row[i]);
        printf("\n");
        return;
    }
    FOR(i,8)
    {
        if(col == cc && i != rr)
            continue;
        if(check(i,col))
        {
            row[col] = i;
            backtrack(col+1);
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&rr,&cc);
        solution = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1);
        if(test)printf("\n");
    }
    return 0;
}
