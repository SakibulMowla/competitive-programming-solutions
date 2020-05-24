#include <stdio.h>
#include <string.h>

#define max 300
#define inf 999999999

int matrix[max][max];
char color[max];
int dist[max];
char path[max];
char queue[max];
char list[max];
int front,rear;

int empty(void)
{
    return rear-front == 0 ? 1 : 0;
}

void pop(void)
{
    front++;
    return;
}

void push(char item)
{
    queue[rear++]=item;
    return;
}

int BFS(char start,char target)
{
    int i,flag;
    char a;
    for(i=0;i<300;i++)
    {
        color[i]='i';
        dist[i]=inf;
        queue[i]='0';
    }

    dist[start]=0;
    color[start]='v';
    front=rear=0;
    push(start);
    flag=0;

    while( !empty() )
    {
        a=queue[front];
        pop();

        for(i=0;i<300;i++)
        {
            if(matrix[a][i] == 1 && color[i] == 'i')
            {
                color[i]='v';
                dist[i]=dist[a]+1;
                push(i);
                path[i]=a;
                if(i==target)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            break;
        color[a]='v';
    }
    return dist[target];
}

void print(char target)
{
    int i,j,k;
    char a,b,c;
    list[dist[target]]=target;
    for(i=dist[target]-1;i>=0;i--)
    {
        list[i]=path[list[i+1]];
    }
    list[i]='\0';
    printf("%s\n",list);
    memset(path,0,sizeof(path));
    memset(list,0,sizeof(list));
    return;
}

int main()
{
    int i,m,n,t,test,len;
    char node1[100],node2[100];
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d %d",&m,&n);
        memset(matrix,0,sizeof(matrix));
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&node1,&node2);
            matrix[node1[0]][node2[0]] = matrix[node2[0]][node1[0]] = 1;
        }
        for(i=0;i<n;i++)
        {
            scanf("%s %s",node1,node2);
            len=BFS(node1[0],node2[0]);
            if(len != inf)
                print(node2[0]);
        }
        if(t<test-1)
            printf("\n");
    }
    return 0;
}
