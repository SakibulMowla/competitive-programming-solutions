#include <stdio.h>
#include <string.h>

#define max 2510
#define inf 999999999

char color[max];
int queue[max];
int matrix[max][max];
int dist[max];

int rear,front,max_boom,t,day,boom,first_boom,predist;

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

int BFS(int start)
{
    int i,j,k,flag;

    for(i=0;i<=t;i++)
    {
        color[i]='i';
        queue[i]=0;
        dist[i]=inf;
    }
    front=rear=0;
    color[start]='v';
    dist[start]=0;
    push(start);
    flag=0;
    max_boom=0;
    first_boom=0;
    predist=0;
    boom=0;

    while( !empty() )
    {
        i=queue[front];
        pop();
        if(dist[queue[front-2]] != dist[i] || dist[i]==0)
        {
            if(max_boom<boom)
                max_boom=boom,first_boom=predist;
            boom=0;
        }
        for(j=0;j<t;j++)
        {
            if(matrix[i][j] == 1 && color[j]=='i')
            {
                flag=1;
                color[j]='v';
                dist[j]=dist[i]+1;
                predist=dist[j];
                boom++;
                push(j);
            }
        }
        color[i]='v';
    }

    return flag;
}

int main()
{
    int i,j,k,l,node,p,start,ind;
    scanf("%d",&t);
    memset(matrix,0,sizeof(matrix));
    for(i=0;i<t;i++)
    {
        scanf("%d",&j);
        for(k=0;k<j;k++)
        {
            scanf("%d",&node);
            matrix[i][node]=1;
        }
    }

    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        scanf("%d",&start);
        ind=BFS(start);
        if(ind==0)
            printf("0\n");
        else
            printf("%d %d\n",max_boom,first_boom);
    }

    return 0;
}
