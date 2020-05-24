#include<stdio.h>
#include<stdlib.h>

int dif[4000];
int main()
{
    int n,i,j,k,c;
    while(scanf("%d",&n)==1)
    {
        scanf("%d",&j);
        for(i=0; i<n-1; i++)
        {
            scanf("%d",&k);
            dif[abs(j-k)]=1;
            j=k;
        }
        if(n==1)
        {
            printf("Jolly\n");
            continue;
        }
        if(n==0)
            continue;
        c=0;
        for(i=1;i<n;i++)
        {
            if(dif[i]!=1)
            c++;
        }
        if(c==0)
        printf("Jolly\n");
        else
        printf("Not jolly\n");
        for(i=0;i<=4000;i++)
        dif[i]=0;
    }

    return 0;
}
