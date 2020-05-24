#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

#define SZ 55
char arr[SZ][SZ] , s[SZ];
int r, c;

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

bool check(int n,int m)
{
    int i,j,p,q,l;

    l = strlen(s+1);

    for(i=0;i<8;i++)
    {
        for(j=0;j<l;j++)
        {
            p = n + j * x[i];
            q = m + j * y[i];
            if(arr[p][q] != s[j+1])
                break;
        }
        if(j == l) return true;
    }

    return false;
}

int main()
{
    int t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
            {
                scanf(" %c",&arr[i][j]);
                arr[i][j] = tolower(arr[i][j]);
            }

        scanf("%d",&k);

        while(k--)
        {
            scanf(" %s",s+1);
            for(i=1;s[i];i++)
                s[i] = tolower(s[i]);
            for(i=1;i<=r;i++)
                for(j=0;j<=c;j++)
                    if(arr[i][j] == s[1] && check(i,j))
                        goto step;
            step: printf("%d %d\n",i,j);
        }

        if(t) printf("\n");
    }

    return 0;
}
