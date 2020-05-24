#include <stdio.h>

typedef struct{
        int p1,p2;
} data;

int main()
{
    data arr[10010];
    int b[10010],n,m,i,j,k,temp,c;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        scanf("%d",&m);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(b[i]>b[j])
                {
                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
        c=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                if(b[i]+b[j]==m)
                {
                    arr[c].p1=b[i];
                    arr[c].p2=b[j];
                    c++;
                    break;
                }
            }
        k=c-1;
        printf("Peter should buy books whose prices are %d and %d.\n\n",arr[k].p1,arr[k].p2);

    }
    return 0;
}
