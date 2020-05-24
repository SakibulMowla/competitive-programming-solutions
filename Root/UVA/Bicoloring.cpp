#include <stdio.h>
#include <string.h>

#define SZ 300

int queue[SZ];
char color[SZ];
int matrix[SZ][SZ];
int front,rear,nodes;

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
    for(i=0; i<nodes; i++)
    {
        color[i]='i';
        queue[i]=0;
    }
    front=rear=0;
    flag=1;
    push(start);
    color[start]='r';

    while( !empty() )
    {
        i=queue[front];
        pop();
        for(j=0; j<nodes; j++)
        {
            if(matrix[i][j] == 1 )
            {
                if(color[i] == 'r' && color[j] == 'i')
                {
                    color[j]='b';
                    push(j);
                }
                else if(color[i] == 'b' && color[j] == 'i')
                {
                    color[j]='r';
                    push(j);
                }
                else if(color[i]=='r' && color[j] == 'r')
                {
                    flag=0;
                    break;
                }
                else if(color[i]=='b' && color[j]=='b')
                {

                    flag=0;
                    break;
                }
            }
        }
        if(flag==0)
            break;
    }

    return flag;
}

int main()
{
    int edges,i,j,k,l,node1,node2,flag,enter;
    while(scanf("%d",&nodes) == 1 && nodes)
    {
        memset(matrix,0,sizeof(matrix));
        scanf("%d",&edges);
        for(i=0; i<edges; i++)
        {
            scanf("%d %d",&node1,&node2);
            matrix[node1][node2] = matrix[node2][node1] = 1;
        }
        enter=0;
        for(i=0; i<nodes; i++)
        {
            for(j=0; j<nodes; j++)
                if(matrix[i][j] == 1)
                {
                    enter=1;
                    flag=BFS(i);
                    if(flag==1)
                        printf("BICOLORABLE.\n");
                    else if(flag==0)
                        printf("NOT BICOLORABLE.\n");
                    break;
                }
            if(enter==1)
                break;
        }
    }

    return 0;
}
