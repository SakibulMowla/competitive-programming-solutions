#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#define SZ 1010

using namespace std;

int row,col;
int front,rear;
bool matrix[SZ][SZ];
int dist[SZ][SZ];


int x[]={-1,0,0,1};
int y[]={0,-1,1,0};


int BFS(int start1,int start2,int target1,int target2)
{
    int i,u,v,a,b,flag;
    queue<int>q;
    memset(dist,0,sizeof(dist));
    dist[start1][start2]=0;
    q.push(start1);
    q.push(start2);
    matrix[start1][start2]=1;
    flag=0;

    while( !q.empty() )
    {
        a=q.front();
        q.pop();
        b=q.front();
        q.pop();

        for(i=0;i<4;i++)
        {
            u=a+x[i];
            v=b+y[i];
            if(u>=0 && u<row && v>=0 && v<col && matrix[u][v]!=1)
            {
                matrix[u][v]=1;
                dist[u][v]=dist[a][b] + 1;
                q.push(u);
                q.push(v);
                if(u==target1 && v==target2)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            break;
    }

    return dist[target1][target2];
}

int main()
{
    int t,test,i,j,k,r,row_num,col_num,bom_col,start1,start2,target1,target2,len;
    while(scanf("%d %d",&row,&col) == 2 && row && col)
    {
        memset(matrix,0,sizeof(matrix));
        scanf("%d",&r);
        for(i=0;i<r;i++)
        {
            scanf("%d",&row_num);
            scanf("%d",&col_num);
            for(j=0;j<col_num;j++)
            {
                scanf("%d",&bom_col);
                matrix[row_num][bom_col] = 1;
            }
        }
        scanf("%d %d %d %d",&start1,&start2,&target1,&target2);
        len=BFS(start1,start2,target1,target2);
        printf("%d\n",len);
    }

    return 0;
}
