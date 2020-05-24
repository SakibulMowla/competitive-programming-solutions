#include <stdio.h>
#include <string.h>
#include <math.h>

int matrix[100][100];
int color[100];
int queue[100];
int level[100];
int rong[100][100];
int pp,d,rear,m,front;

void push(int item)
{
    queue[rear++]=item;
    return;
}

int empty(int f,int r)
{
    return (r-f);
}

int BFS(int p,int q)
{
    if(p==q && p!=0)
        return 0;
    front=rear=0;
    push(p);
    int i,j,ans,flag=0;
    for(i=queue[front]; empty(front,rear); i=queue[front+1],front++)
    {
        for(j=1; j<=m ; j++)
        {
            if(matrix[i][j]==1 && color[j]!=1 && rong[i][j]!=1 && rong[j][i]!=1)
            {
                if(j==q)
                {
                    ans=level[i]+1;
                    return ans;
                }
                push(j);
                level[j]=front+1;
                rong[i][j]=1;
                color[j]=1;
            }
        }
        color[i]=1;
    }
    if(!empty(front,rear))
        return -1;
}

int main()
{
    int test,n,i,j,k,l,p,p1,q,shipment,len,temp,ans,t;
    char arr[100][100],ds1[100],ds2[100];
    scanf("%d",&test);
    printf("SHIPPING ROUTES OUTPUT\n");
    for(t=0; t<test; t++)
    {
        scanf("%d %d %d",&m,&n,&p1);
        for(i=1; i<=m; i++)
            scanf("%s",&arr[i]);
        for(i=1; i<=n; i++)
        {
            scanf("%s %s",&ds1,&ds2);
            for(j=1; j<=m; j++)
            {
                if(strcmp(arr[j],ds1)==0)p=j;
                if(strcmp(arr[j],ds2)==0)q=j;
            }
            matrix[p][q]=1;
            matrix[q][p]=1;
        }
        for(i=1; i<=p1; i++)
        {
            memset(color,0,sizeof(color));
            memset(queue,0,sizeof(queue));
            memset(level,0,sizeof(level));
            memset(rong,0,sizeof(rong));
            scanf("%d %s %s",&shipment,&ds1,&ds2);
            pp=d=temp=0;
            for(j=1; j<=m; j++)
            {
                if(strcmp(arr[j],ds1)==0)pp=j;
                if(strcmp(arr[j],ds2)==0)d=j;
            }
            if(pp>d)
            {
                temp=pp;
                pp=d;
                d=temp;
            }

            len=BFS(pp,d);
            if(len!=-1)
                ans=len*100*shipment;

            if(i==1)
                printf("\nDATA SET  %d\n\n",t+1);
            if(len!=-1)
                printf("$%d\n",ans);
            else
                printf("NO SHIPMENT POSSIBLE\n");

        }
        memset(matrix,0,sizeof(matrix));
    }
    printf("\nEND OF OUTPUT\n");

    return 0;
}
