#include <stdio.h>
#include <string.h>

char arr[3][3];

int win(char ch)
{
    int i;
    for(i=0;i<3;i++)
        if(arr[i][0]==ch && arr[i][1]==ch && arr[i][2]==ch)
            return 1;
    for(i=0;i<3;i++)
        if(arr[0][i]==ch && arr[1][i]==ch && arr[2][i]==ch)
            return 1;
    if(arr[0][0]==ch && arr[1][1]==ch && arr[2][2]==ch)
        return 1;
    if(arr[0][2]==ch && arr[1][1]==ch && arr[2][0]==ch)
        return 1;
    return 0;
}

int main()
{
    int test,i,j,no,nx;
    bool x_win,o_win,ghotona;
    scanf("%d",&test);
    while(test--)
    {
        no=nx=0;
        ghotona=true;
        scanf("%s %s %s",arr[0],arr[1],arr[2]);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                if(arr[i][j] == 'O')
                    no++;
                if(arr[i][j] == 'X')
                    nx++;
            }
        x_win = win('X');
        o_win = win('O');

        if(no > nx || nx > no+1)
            ghotona=false;

        if(x_win && o_win)
            ghotona=false;

        if(x_win && nx != no+1)
            ghotona=false;

        if(o_win && no != nx)
            ghotona=false;

        if(ghotona == true)
            printf("yes\n");
        else if(ghotona == false)
            printf("no\n");
    }

    return 0;
}
