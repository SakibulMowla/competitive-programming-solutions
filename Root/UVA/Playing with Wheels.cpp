#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SZ 10000

char color[SZ];
char queue[SZ][SZ];
int dist[SZ];
int front,rear;

int empty(void)
{
    return rear-front == 0 ? 1 : 0;
}

void push(char node[10])
{
    strcpy(queue[rear++],node);
    return;
}

void pop(void)
{
    front++;
    return;
}

int BFS(char start[10],char target[10])
{
    int i,j,k,flag,num;
    char p[10],a[10];
    for(i=0; i<SZ; i++)
    {
        queue[i][0]='\0';
        dist[i]=-1;
    }
    front=rear=0;
    flag=0;
    color[atoi(start)]='v';
    dist[atoi(start)]=0;
    push(start);

    while( !empty() )
    {
        strcpy(a,queue[front]);
        pop();
        j=0;

        for(j=-1; j<=1; j+=2)
        {
            strcpy(p,a);
            for(k=0; k<4; k++)
            {
                if(p[k]=='9' && j==1)num=0;
                else if(p[k]=='0' && j==-1)num=9;
                else num=(p[k]-'0')+j;
                p[k]=num+'0';
                if(color[atoi(p)] == 'i')
                {
                    push(p);
                    color[atoi(p)]='v';
                    dist[atoi(p)]=dist[atoi(a)]+1;
                    if(strcmp(p,target)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                strcpy(p,a);
            }
            strcpy(p,a);
            if(flag==1)
                break;
        }

        color[i]='v';
        if(flag==1)
            break;
    }

    return dist[atoi(target)];
}

int main()
{
    int t,test,n1,n2,n3,n4,num,forbid,i,len;
    char beg[10],end[10];
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
        beg[0]=n1+'0';
        beg[1]=n2+'0';
        beg[2]=n3+'0';
        beg[3]=n4+'0';
        beg[4]='\0';
        scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
        end[0]=n1+'0';
        end[1]=n2+'0';
        end[2]=n3+'0';
        end[3]=n4+'0';
        end[4]='\0';
        scanf("%d",&forbid);
        for(i=0; i<SZ; i++)
            color[i]='i';
        for(i=0; i<forbid; i++)
        {
            scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
            num=(n1*1000)+(n2*100)+(n3*10)+n4;
            color[num]='v';
        }
        len=BFS(beg,end);
        printf("%d\n",len);
    }

    return 0;
}
