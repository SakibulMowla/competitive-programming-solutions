#include <stdio.h>
#include <string.h>

#define max 10010

int queue[max];
char color[max];
int matrix[max];
int rear,front;
int n,m,l;
int count;


int BFS(void)
{
    int i,j,k;
    while( rear-front !=0 )
    {
        i=queue[front];
        if(color[i] == 'i')
            count++;
        front++;
        if(matrix[i] != 0 && color[matrix[i]] == 'i')
        {
            count++;
            queue[rear++]=matrix[i];
            color[i]='v';
            color[matrix[i]]='v';
        }
    }

    return;
}

int main()
{
    int i,j,node1,node2,t,test,start;
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        memset(matrix,0,sizeof(matrix));
        scanf("%d %d %d",&n,&m,&l);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&node1,&node2);
            matrix[node1]=node2;
        }
        count=0;
        for(i=0; i<=n; i++)
            color[i]='i';

        memset(queue,0,sizeof(queue));
        front=rear=0;
        for(i=0; i<l; i++)
        {
            scanf("%d",&start);
            queue[rear++]=start;
        }
        BFS();
        printf("%d\n",count);
    }
    return 0;
}
