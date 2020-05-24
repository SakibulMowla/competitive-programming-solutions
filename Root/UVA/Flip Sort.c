#include <stdio.h>

int main(void)
{
    int n,i,j,c,arr[1010];
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        c=0;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(arr[i]>arr[j])
                    c++;
        printf("Minimum exchange operations : %d\n",c);
    }

    return 0;
}
