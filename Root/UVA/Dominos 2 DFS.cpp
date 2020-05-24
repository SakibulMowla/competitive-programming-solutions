#include <stdio.h>
#include <string.h>

#define SZ 10010

int matrix[SZ][SZ];
int queue[SZ];
int limit[SZ];
bool color[SZ];

int front,rear;
int n,m,l;
int count;

void BFS(void)
{
    int i,j,k;
    while( front != rear )
    {
        i=queue[front];
        if(color[i] == 0)
        {
            count++;
            color[i] = 1;
        }

        front++;
        for(j=0; j<limit[i]; j++)
        {
            if(color[matrix[i][j]] == 0)
            {
                count++;
                color[matrix[i][j]]=1;
                queue[rear++]=matrix[i][j];
            }
        }
        color[i] = 1;
    }

    return;
}

int main()
{
    int t,test,i,node1,node2,kicker;
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        scanf("%d %d %d",&n,&m,&l);
        memset(limit,0,sizeof(limit));
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&node1,&node2);
            matrix[node1][limit[node1]++] = node2;
        }
        memset(color,0,sizeof(color));
        front=rear=0;
        count=0;
        for(i=0; i<l; i++)
        {
            scanf("%d",&kicker);
            queue[rear++]=kicker;
        }
        BFS();
        printf("%d\n",count);
    }

    return 0;
}
