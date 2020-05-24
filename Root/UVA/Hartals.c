#include <stdio.h>
#include <string.h>

int hartal[4000];
int main()
{
    int h[100+10],t,i,n,p,j,k,l,count;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        scanf("%d",&p);
        for(j=0;j<p;j++)
            scanf("%d",&h[j]);
        for(j=0;j<4000;j++)
            hartal[j]=0;
        for(j=0;j<p;j++)
        {
            l=1;
            for(k=h[j]*l;k<=n;k=h[j]*l)
            {
                hartal[k]=1;
                l++;
            }
        }
        for(j=1,k=7*j;k-1<=n;j++,k=7*j)
            hartal[k]=hartal[k-1]=0;
        count=0;
        for(j=1;j<=n;j++)
            if(hartal[j])
                count++;
        printf("%d\n",count);
    }
    return 0;
}
