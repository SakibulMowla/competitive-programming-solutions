#include <stdio.h>

int circle[30010];
int parent[30010];

int find(int r)
{
    if(r != parent[r])
        parent[r]=find(parent[r]);
    return parent[r];
}

void Union(int a,int b)
{
    if(circle[a] < circle[b])
        parent[b] = a, circle[a] += circle[b];
    else
        parent[a] = b, circle[b] += circle[a];
    return;
}

void make_parent(int n)
{
    int i;
    for(i=1;i<=n;i++)
        parent[i] = i , circle[i] = 1;
    return;
}

int main()
{
    int test,n,m,i,max,x,y;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        make_parent(n);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            x=find(x);
            y=find(y);
            if(x != y)
                Union(x,y);
        }
        max=0;
        for(i=1;i<=n;i++)
        {
            max=circle[i]>max?circle[i]:max;
        }
        printf("%d\n",max);
    }

    return 0;
}
