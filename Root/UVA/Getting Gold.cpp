#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 60


int r,c,count;
char arr[SZ][SZ];
bool color[SZ][SZ];

int x[]={-1,1,0,0};
int y[]={0,0,-1,1};

void DFS_gold(int s1,int s2)
{
    int i,j,k,l,u,v;
    if(arr[s1][s2]=='#' || color[s1][s2] == 1)
        return;

    color[s1][s2]=1;
    if(arr[s1][s2] == 'G')
        count++;

    for(i=0;i<4;i++)
    {
        u=s1+x[i];
        v=s2+y[i];
        if(arr[u][v] == 'T')
            return;
    }

    for(i=0;i<4;i++)
    {
        u=s1+x[i];
        v=s2+y[i];
        DFS_gold(u,v);
    }

    return;
}

int main()
{
    int i,j,k,l,s1,s2;

    while(scanf("%d %d",&c,&r) == 2)
    {
        for(i=0;i<r;i++)
            scanf("%s",arr[i]);

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                color[i][j]=0;
                if(arr[i][j] == 'P')
                {
                    s1=i;
                    s2=j;
                }
            }
        }

        count=0;
        DFS_gold(s1,s2);
        printf("%d\n",count);
    }

    return 0;
}
