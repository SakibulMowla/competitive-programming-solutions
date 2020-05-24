#include <stdio.h>
#include <string.h>

#define inf 1000000000
#define max 500

int matrix [max][max];
int dist[max];
char color[max];
int m,n,p,shipment;
int front,rear;
int queue[max];

int empty(void)
{
    return (rear-front==0 ? 1 : 0);
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
int BFS(int start,int target)
{
    int i,j,k;
    //initializing color && dist with i && inf
    for(i=0; i<m; i++)
    {
        color[i]='i';
        dist[i]=inf;
    }
    color[start]='v';//coloring the visited item by v
    dist[start]=0;
    memset(queue,0,sizeof(queue));
    front=rear=0;
    push(start);

    while( !empty() )
    {
        k=queue[front];
        pop();

        for(i=0; i<m; i++)
        {
            if(matrix[k][i] == 1 && color[i]=='i')
            {
                color[i]='v';//coloring the visited item by v
                dist[i]=dist[k]+1;
                push(i);
            }
        }
        color[k]='r';//coloring the visited root by r
    }
    if(dist[target] == inf)return -1;
    return dist[target];
}

int main()
{
    int i,j,start,target,test,t,path,ans;
    char arr[max][max],node1[max],node2[max];
    scanf("%d",&test);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(t=0; t<test; t++)
    {
        memset(matrix,0,sizeof(matrix));
        scanf("%d %d %d",&m,&n,&p);
        for(i=0; i<m; i++)
        {
            scanf("%s",arr[i]);
        }

        for(i=0; i<n; i++)
        {
            scanf("%s %s",node1,node2);
            for(j=0; j<m; j++)
            {
                if(strcmp(node1,arr[j]) == 0)
                {
                    start=j;
                    break;
                }
            }
            for(j=0; j<m; j++)
            {
                if(strcmp(node2,arr[j]) == 0)
                {
                    target=j;
                    break;
                }
            }
            matrix[start][target]=1;
            matrix[target][start]=1;
        }
        printf("DATA SET  %d\n\n",t+1);
        for(i=0; i<p; i++)
        {
            scanf("%d %s %s",&shipment,node1,node2);
            for(j=0; j<m; j++)
            {
                if(strcmp(node1,arr[j]) == 0)
                {
                    start=j;break;
                }
            }
            for(j=0; j<m; j++)
            {
                if(strcmp(node2,arr[j]) == 0)
                {
                    target=j;break;
                }
            }
            path=BFS(start,target);
            if(path == -1)
                printf("NO SHIPMENT POSSIBLE\n");
            else
            {
                ans=path*shipment*100;
                printf("$%d\n",ans);
            }
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
