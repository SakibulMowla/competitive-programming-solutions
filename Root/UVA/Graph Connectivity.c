#include <stdio.h>
#include <string.h>

#define max 100

int matrix[max][max];
char color[max];
int front,rear;
int queue[max];
char limit;

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

void bfs(int start)
{
    int i,j,k;
    front=rear=0;
    color[start]='v';
    push(start);

    while( !empty() )
    {
        i=queue[front];
        pop();
        for(j=0;j<=limit-'A';j++)
        {
            if(matrix[i][j] == 1 && color[j]=='i')
            {
                color[j]='v';
                push(j);
            }
        }
        color[i]='v';
    }
    return;
}

int main()
{
    int i,j,k,l,t,test,n,count;
    char node[10];
    scanf("%d",&test);
    getchar();
    getchar();
    for(t=0;t<test;t++)
    {
        memset(matrix,0,sizeof(matrix));
        for(i=0;i<max;i++)
            color[i]='i';
        scanf("%c",&limit);
        getchar();
        n=0;
        while(gets(node))
        {
            if(strlen(node) == 0)break;
            matrix[ node[0]-'A' ][ node[1]-'A' ] = matrix[ node[1]-'A' ][ node[0]-'A' ] =1;
            n++;
        }

        count=0;
        for(i=0;i<=limit-'A';i++)
        {
            if(color[i] == 'i')
            {
                count++;
                bfs(i);
            }
        }
        printf("%d\n",count);
        if(t<test-1)
            printf("\n");
    }
    return 0;
}
