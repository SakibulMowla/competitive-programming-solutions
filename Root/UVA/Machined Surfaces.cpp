#include <stdio.h>

#define min(a,b) a<b?a:b

int main()
{
    int row,i,j,minimum,spaces,total,ans;
    char arr[30][30];

    while(scanf("%d",&row) == 1 && row)
    {
        getchar();
        for(i=0;i<row;i++)
            gets(arr[i]);
        total = 0;
        minimum = 1000;
        for(i=0;i<row;i++)
        {
            spaces = 0;
            for(j=0;j<25;j++)
            {
                if(arr[i][j] == ' ')
                    spaces++;
            }
            minimum = min(minimum,spaces);
            total += spaces;
        }
        ans = total - (row * minimum);
        printf("%d\n",ans);
    }

    return 0;
}
