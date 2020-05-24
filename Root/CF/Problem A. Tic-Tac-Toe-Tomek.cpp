#include "stdio.h"
#include "string.h"

char arr[6][6];

int xwin()
{
    int i,j,t,x;
    for(i=0; i<4; i++)
    {
        x = t = 0;
        for(j=0; j<4; j++)
        {
            if(arr[j][i] == 'X') x++;
            else if(arr[j][i] == 'T') t++;
        }
        if(x == 4 || (x == 3 && t == 1)) return 1;
    }
    for(i=0; i<4; i++)
    {
        x = t = 0;
        for(j=0; j<4; j++)
        {
            if(arr[i][j] == 'X') x++;
            else if(arr[i][j] == 'T') t++;
        }
        if(x == 4 || (x == 3 && t == 1)) return 1;
    }
    x = t = 0;
    if(arr[0][0] == 'X') x++;
    else if(arr[0][0] == 'T') t++;
    if(arr[1][1] == 'X') x++;
    else if(arr[1][1] == 'T') t++;
    if(arr[2][2] == 'X') x++;
    else if(arr[2][2] == 'T') t++;
    if(arr[3][3] == 'X') x++;
    else if(arr[3][3] == 'T') t++;
    if(x == 4 || (x == 3 && t == 1)) return 1;

    x = t = 0;
    if(arr[0][3] == 'X') x++;
    else if(arr[0][3] == 'T') t++;
    if(arr[1][2] == 'X') x++;
    else if(arr[1][2] == 'T') t++;
    if(arr[2][1] == 'X') x++;
    else if(arr[2][1] == 'T') t++;
    if(arr[3][0] == 'X') x++;
    else if(arr[3][0] == 'T') t++;
    if(x == 4 || (x == 3 && t == 1)) return 1;

    return 0;
}

int owin()
{
    int i,j,t,x;
    for(i=0; i<4; i++)
    {
        x = t = 0;
        for(j=0; j<4; j++)
        {
            if(arr[j][i] == 'O') x++;
            else if(arr[j][i] == 'T') t++;
        }
        if(x == 4 || (x == 3 && t == 1)) return 1;
    }
    for(i=0; i<4; i++)
    {
        x = t = 0;
        for(j=0; j<4; j++)
        {
            if(arr[i][j] == 'O') x++;
            else if(arr[i][j] == 'T') t++;
        }
        if(x == 4 || (x == 3 && t == 1)) return 1;
    }
    x = t = 0;
    if(arr[0][0] == 'O') x++;
    else if(arr[0][0] == 'T') t++;
    if(arr[1][1] == 'O') x++;
    else if(arr[1][1] == 'T') t++;
    if(arr[2][2] == 'O') x++;
    else if(arr[2][2] == 'T') t++;
    if(arr[3][3] == 'O') x++;
    else if(arr[3][3] == 'T') t++;
    if(x == 4 || (x == 3 && t == 1)) return 1;

    x = t = 0;
    if(arr[0][3] == 'O') x++;
    else if(arr[0][3] == 'T') t++;
    if(arr[1][2] == 'O') x++;
    else if(arr[1][2] == 'T') t++;
    if(arr[2][1] == 'O') x++;
    else if(arr[2][1] == 'T') t++;
    if(arr[3][0] == 'O') x++;
    else if(arr[3][0] == 'T') t++;
    if(x == 4 || (x == 3 && t == 1)) return 1;

    return 0;
}

int main()
{
    int t=0,test,i,j,empty;
    scanf("%d",&test);
    while(test--)
    {
        empty = 0;
        for(i=0; i<4; i++) for(j=0; j<4; j++)
            {
                scanf(" %c",&arr[i][j]) ;
                if(arr[i][j] == '.') empty = 1;
            }
        printf("Case #%d: ",++t);
        if(xwin()) printf("X won\n");
        else if(owin()) printf("O won\n");
        else if(empty) printf("Game has not completed\n");
        else printf("Draw\n");
    }

    return 0;
}
