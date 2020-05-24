#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

#define SZ 10000

char arr[SZ][SZ];
int queue[SZ];
char color[SZ];
int parent[SZ];
char list[SZ][SZ];
int matrix[SZ][SZ];
int dist[SZ];
int path[SZ];
int nodes,front,rear;

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

int BFS(int start,int target)
{
    int i,j,k,flag;
    for(i=0;i<nodes;i++)
    {
        color[i]='i';
        queue[i]=0;
        parent[i]=0;
        dist[i]=0;
    }
    flag=0;
    rear=front=0;
    push(start);
    color[start]='v';
    dist[start]=0;

    while( !empty() )
    {
        i=queue[front];
        pop();
        for(j=1;j<nodes;j++)
        {
            if(matrix[i][j] == 1 && color[j] == 'i')
            {
                push(j);
                color[j]='v';
                parent[j]=i;
                dist[j]=dist[i]+1;
                if(j==target)
                {
                    flag=1;
                    break;
                }
            }
        }
        color[i]='v';
        if(flag==1)
            break;
    }

    return flag;
}

void print(int target)
{
    int i,j,k;
    strcpy(list[dist[target]],arr[target]);
    path[dist[target]]=target;
    for(j=dist[target]-1;j>=0;j--)
    {
        path[j]=parent[path[j+1]];
        strcpy(list[j],arr[path[j]]);
    }
    for(i=0;i<dist[target];i++)
    {
        printf("%s %s\n",list[i],list[i+1]);
    }
    return;
}

int main()
{
    int test,t,start,target,len,new_line_tester;
    char node1[SZ],node2[SZ];
    new_line_tester=0;
    while(scanf("%d",&test)==1)
    {
        memset(matrix,0,sizeof(matrix));
        map <string , int> m;
        nodes=1;
        if(new_line_tester)printf("\n");
        new_line_tester=1;
        for(t=0; t<test; t++)
        {
            scanf("%s %s",node1,node2);
            if( !m[node1] )m[node1]=nodes++,strcpy(arr[nodes-1],node1);
            if( !m[node2] )m[node2]=nodes++,strcpy(arr[nodes-1],node2);
            matrix[ m[node1] ] [ m[node2] ] = matrix[ m[node2] ] [ m[node1] ] = 1;
        }
        scanf("%s %s",&node1,&node2);
        start=m[node1];
        target=m[node2];
        len=BFS(start,target);
        if(len==1)
            print(target);
        else
            printf("No route\n");
    }

    return 0;
}
