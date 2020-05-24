#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 1010

char h;
char arr[max][max];
int ans[max][max];
int col[max];
int max_col[max];
int row;
int count;

int dx[]= {-1,-1,-1,0,0,1,1,1};
int dy[]= {-1,0,1,-1,1,-1,0,1};

void dfs(int n,int  m)
{
    if(n<0 || m<0 || n>=row || m>=col[n] || arr[n][m]!=h)return;

    int i;

    arr[n][m]='0';
    ans[n][m]=count;

    for(i=0; i<8; i++)
    {
        dfs( n+dx[i] , m+dy[i] );
    }
    return;
}

int main()
{
    int n,m,i,j,k,l;
    char line[max];

    row=0;
    k=0;

    while(gets(line))
    {
        if(line[0]=='%')
        {
            count=0;

            for(i=0; i<row; i++)
            {
                for(j=0; j<col[i]; j++)
                {
                    if(arr[i][j]!='0')
                    {
                        h=arr[i][j];
                        ++count;
                        dfs(i,j);
                    }
                }
            }

            memset(max_col,0,sizeof(max_col));
            for(i=0 ; i<col[0]; i++)
            {
                for(j=0 ; j<row ; j++)
                {
                    if(ans[j][i] > max_col[i])
                        max_col[i] = ans[j][i];
                }
            }


            for(i=0; i<row; i++)
            {
                for(j=0; j<col[i]; j++)
                {
                    if(j!=0)printf(" ");
                    if(max_col[j]<10)printf("%d",ans[i][j]);
                    else if(max_col[j]<100)printf("%2d",ans[i][j]);
                    else if(max_col[j]<1000)printf("%3d",ans[i][j]);
                    else if(max_col[j]<10000)printf("%4d",ans[i][j]);
                }
                printf("\n");
            }
            printf("%%\n");
            row=0;
            k=0;
            memset(arr,0,sizeof(arr));
            memset(ans,0,sizeof(ans));
            memset(col,0,sizeof(col));

        }

        else
        {
            k=0;
            for(i=0; i<strlen(line); i++)
            {
                if(toupper(line[i]) >= 'A' && toupper(line[i]) <= 'Z')
                    arr[row][k++]=line[i],col[row]++;
            }
            row++;
        }

    }
    count=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col[i]; j++)
        {
            if(arr[i][j]!='0')
            {
                h=arr[i][j];
                ++count;
                dfs(i,j);
            }
        }
    }

    memset(max_col,0,sizeof(max_col));
    for(i=0 ; i<col[0]; i++)
    {
        for(j=0 ; j<row ; j++)
        {
            if(ans[j][i] > max_col[i])
                max_col[i] = ans[j][i];
        }
    }

    for(i=0; i<row; i++)
    {
        for(j=0; j<col[0]; j++)
        {
            if(j!=0)printf(" ");
            if(max_col[j]<10)printf("%d",ans[i][j]);
            else if(max_col[j]<100)printf("%2d",ans[i][j]);
            else if(max_col[j]<1000)printf("%3d",ans[i][j]);
            else if(max_col[j]<10000)printf("%4d",ans[i][j]);
        }
        printf("\n");
    }
    printf("%%\n");

    return 0;
}
