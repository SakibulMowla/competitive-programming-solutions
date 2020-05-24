#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define inf 999999999

int arr[10005];
int color[10005];
int queue[10005];
int dist[10005];
int front,rear;

void seive(void)
{
    int i,j;
    arr[0]=arr[1]=1;
    for(i=4; i<10000; i+=2)
        arr[i]=1;
    for(i=3; i<sqrt(10000); i+=2)
    {
        if(arr[i] == 0)
        {
            for(j=i*i; j<10000; j+=i*2)
                arr[j]=1;
        }
    }
    return;
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

int empty(void)
{
    return rear-front == 0 ? 1 : 0;
}

int BFS(int start,int target)
{
    char a[10],b[10];
    int i,j,k,flag;
    sprintf(a,"%d",start);
    for(i=0; i<10000; i++)
    {
        dist[i]=inf;
        color[i]=0;
        queue[i]=0;
    }
    rear=front=0;
    flag=0;
    dist[start]=0;
    color[start]=1;
    push(start);

    while( !empty() )
    {
        i=queue[front];
        pop();

        k=0;
        while(k<4)
        {
            sprintf(a,"%d",i);
            for(j=0; j<=9; j++)
            {
                if(j==0 && k==0)continue;
                a[k]=j+'0';
                if( color[atoi(a)]==0  && arr[atoi(a)]==0 )
                {
                    color[atoi(a)]=1;
                    push(atoi(a));
                    dist[atoi(a)]=dist[i]+1;

                    if(atoi(a) == target)
                    {
                        flag=1;
                        break;
                    }
                }

            }
            if(flag==1)
                break;
            k++;
        }
        color[i]=1;
        if(flag==1)
            break;

    }

    return dist[target];
}

int main()
{
    seive();
    int test,t,start,target,len;
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        scanf("%d %d",&start,&target);
        len=BFS(start,target);
        if(len == inf)
            printf("Impossible\n");
        else
            printf("%d\n",len);
    }
    return 0;
}
