#include <stdio.h>
#include <string.h>

#define inf 999999999

int matrix[305][305];
char color[305];
int dist[305];
int path[305];
int queue[305];
int list[305];
int front,rear,start,target;

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

int empty(void)
{
    return rear-front == 0 ? 1 : 0;
}

int BFS(int start,int target)
{
    int i,j,flag;
    for(i=0; i<305; i++)
    {
        color[i]='i';
        dist[i]=inf;
    }

    front=rear=0;
    dist[start]=0;
    color[start]='v';
    memset(queue,0,sizeof(queue));
    push(start);
    flag=0;

    while( !empty() )
    {
        i=queue[front];
        pop();
        for(j=0; j<305; j++)
        {
            if(matrix[i][j] == 1 && color[j] == 'i')
            {
                push(j);
                color[j]='v';
                dist[j]=dist[i]+1;
                path[j]=i;
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
    return dist[target];
}

void print(void)
{
    int i,j;
    list[dist[target]]=target;
    for(j=dist[target]-1;j>=0;j--)
    {
        list[j]=path[list[j+1]];
    }
    printf("%d",list[0]);
    for(i=1;i<=dist[target];i++)
        printf(" %d",list[i]);
    printf("\n");
    return;
}

int main()
{
    int i,j,k,p,nodes,test,len,n,num,t,flag;
    char arr[1000];
    while(scanf("%d",&nodes) == 1)
    {
        getchar();
        memset(matrix,0,sizeof(matrix));
        for(t=0; t<nodes; t++)
        {
            gets(arr);
            len=strlen(arr);
            n=0;
            for(i=0; arr[i]>='0' && arr[i] <= '9'; i++)
                n=(n*10)+(arr[i]-'0');

            for(; i<len; i++)
            {
                num=0;
                flag=0;
                while(arr[i]>='0' && arr[i]<='9')
                {
                    num=(num*10)+(arr[i]-'0');
                    i++;
                    flag=1;
                }
                if(flag==1)
                    matrix[n][num]=1;
            }
        }

        scanf("%d",&p);
        for(i=0; i<p; i++)
        {
            scanf("%d %d",&start,&target);
            len=BFS(start,target);
            if(i==0)
                printf("-----\n");

            if(len == inf)
                printf("connection impossible\n");
            else
                print();
        }
    }
    return 0;
}
