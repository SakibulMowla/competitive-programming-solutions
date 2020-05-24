#include <stdio.h>
#include <string.h>

#define SZ 40

int queue[SZ];
int dist[SZ];
int matrix[SZ][SZ];
int arr[1000000];

int rear,front,nodes;

int empty(void)
{
    return rear-front == 0 ? 1 : 0;
}

void push(int item)
{
    queue[rear++]=item;
    return;
}

void pop(void)
{
    front++;
    return;
}

void BFS(int start)
{
    int i,j,k;
    for(i=0;i<nodes;i++)
    {
        queue[i]=0;
        dist[i]=-1;
    }
    rear=front=0;
    dist[start]=0;
    push(start);

    while( !empty() )
    {
        i=queue[front];
        pop();

        for(j=1;j<nodes;j++)
        {
            if(matrix[i][j]==1 && dist[j] == -1)
            {
                dist[j]=dist[i]+1;
                push(j);
            }
        }
    }

    return;
}

void total_unreached_nodes(int count,int start,int ttl)
{
    int i,un_node;
    un_node=0;
    for(i=1;i<nodes;i++)
        if(dist[i]==-1 || dist[i]>ttl)
            un_node++;
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",count,un_node,start,ttl);
    return;
}

int main()
{
    int t,node1,node2,test,start,ttl,count;
//    freopen("1.txt","r",stdin);
//    freopen("myout.txt","w",stdout);

    count=0;
    while(scanf("%d",&test)==1 && test)
    {
        nodes=1;
        memset(arr,0,sizeof(arr));
        memset(matrix,0,sizeof(matrix));
        for(t=0;t<test;t++)
        {
            scanf("%d %d",&node1,&node2);
            if( !arr[node1] ) arr[node1] = nodes++;
            if( !arr[node2] ) arr[node2] = nodes++;
            matrix [ arr[node1] ] [ arr[node2] ] = matrix[ arr[node2] ] [ arr[node1] ] = 1;
        }

        while(scanf("%d %d",&start,&ttl) == 2)
        {
            if(start==0 && ttl == 0)break;

            BFS(arr[start]);

            total_unreached_nodes(++count,start,ttl);
        }
    }
    return 0;
}
