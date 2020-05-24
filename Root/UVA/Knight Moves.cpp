#include <stdio.h>
#include <string.h>

#define inf 999999999

int dist[100];
char color[100];
int queue[100];
int arr[10];
int rear,front;

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
    for(i=0;i<100;i++)
    {
        color[i]='i';
        dist[i]=inf;
        queue[i]=0;
    }
    front=rear=0;
    dist[start]=0;
    color[start]='v';
    push(start);
    flag=0;

    while( !empty() )
    {
        i=queue[front];
        pop();
        k=0;
        if((i/10)+2 <= 8)
        {
            if((i%10)-1 >= 1)
                arr[k++]=i+20-1;
            if((i%10)+1 <= 8)
                arr[k++]=i+20+1;
        }

        if((i/10)-2 >= 1)
        {
            if((i%10)-1 >= 1)
                arr[k++]=i-20-1;
            if((i%10)+1 <= 8)
                arr[k++]=i-20+1;
        }
        if((i%10)-2 >=1)
        {
            if((i/10)-1 >= 1)
                arr[k++]=i-2-10;
            if((i/10)+1 <= 8)
                arr[k++]=i-2+10;
        }
        if((i%10)+2 <=8)
        {
            if((i/10)-1 >=1)
                arr[k++]=i+2-10;
            if((i/10)+1 <=8)
                arr[k++]=i+2+10;
        }

        for(j=0;j<k;j++)
        {
            if(arr[j]>=11 && arr[j]<=88 && color[arr[j]] == 'i')
            {
                push(arr[j]);
                color[arr[j]]='v';
                dist[arr[j]]=dist[i]+1;
                if(arr[j]==target)
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

int main()
{
    int len,start,target;
    char node1[10],node2[10];
    while(scanf("%s %s",node1,node2)==2)
    {
        start=(node1[0]-96)*10+node1[1]-'0';
        target=(node2[0]-96)*10+node2[1]-'0';
        len=BFS(start,target);
        printf("To get from %s to %s takes %d knight moves.\n",node1,node2,len);
    }
    return 0;
}
