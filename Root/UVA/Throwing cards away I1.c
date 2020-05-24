#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int f,i,n,m,j,k,l,c,w,arr[60];

    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        memset(arr,0,sizeof arr);
        printf("Discarded cards:");
        c=0;
        f=1;
        k=n;
        while(k>0)
        {
            if(f>n)
                f=f%n;
            if(c==0 && arr[f]==0)
            {
                k--;
                if(k==0)
                {
                    w=f;
                    printf("\n");
                    continue;
                }
                printf(" %d",f);
                if(k>1)
                    printf(",");
                arr[f]=1;
                c=1;
            }
            if(c==1)
            {
                f++;
                if(f>n)
                    f=f%n;
                if(arr[f]==0)
                {
                    c--;
                    f++;
                }
            }
            if(c==0 && arr[f]==1)
            {
                f++;
                if(f>n)
                    f=f%n;
            }
        }
        printf("Remaining card: %d\n",w);
    }

    return 0;
}
