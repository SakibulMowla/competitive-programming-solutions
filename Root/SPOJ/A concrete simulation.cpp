#include "stdio.h"
#include "string.h"

#define row 1234
#define col 5678
#define FOR(a,b) for(a=1;a<=b;a++)

int arr[row+5][col+5];

int main()
{
//    freopen("1.txt","r",stdin);
    int i,j,k,n,m,tmp;
    char ch;
    k = 1;
    FOR(i,row) FOR(j,col) arr[i][j] = k++;
    while(scanf(" %c",&ch) == 1)
    {
        if(ch == 'R')
        {
            scanf("%d %d",&n,&m);
            FOR(i,col)
            {
                tmp = arr[n][i];
                arr[n][i] = arr[m][i];
                arr[m][i] = tmp;
            }
        }
        if(ch == 'C')
        {
            scanf("%d %d",&n,&m);
            FOR(i,row)
            {
                tmp = arr[i][n];
                arr[i][n] = arr[i][m];
                arr[i][m] = tmp;
            }
        }
        if(ch == 'Q')
        {
            scanf("%d %d",&n,&m);
            printf("%d\n",arr[n][m]);
        }
        if(ch == 'W')
        {
            scanf("%d",&n);
            m = 0;
            FOR(i,row)
            {
                FOR(j,col)
                {
                    if(arr[i][j] == n)
                    {
                        printf("%d %d\n",i,j);
                        m  =  1;
                        break;
                    }
                }
                if(m) break;
            }
        }
    }

    return 0;
}
