#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k,r,c,c1;
    char arr[110][110],z;

    k=1;
    while(scanf("%d %d%c",&r,&c,&z)==3)
    {
        if(r==0 && c==0)
            break;

        for(i=0;i<r;i++)
            gets(arr[i]);
        int str[110][110]={0};
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                c1=0;
                if(arr[i][j]=='*')
                {
                    str[i-1][j-1]++;
                    str[i-1][j]++;
                    str[i-1][j+1]++;
                    str[i][j-1]++;
                    str[i][j+1]++;
                    str[i+1][j-1]++;
                    str[i+1][j]++;
                    str[i+1][j+1]++;
                }
            }
        }
        if(k>1)
            printf("\n");
        printf("Field #%d:\n",k);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]=='*')
                printf("%c",arr[i][j]);
                else
                printf("%d",str[i][j]);
            }
            printf("\n");
        }
        k++;
    }

    return 0;
}
