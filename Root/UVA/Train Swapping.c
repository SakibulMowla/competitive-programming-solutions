#include<stdio.h>

int main()
{
    int n,i,j,k,l,m,c,arr[1000];
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        for(k=0;k<j;k++)
        {
            scanf("%d",&arr[k]);
        }
        c=0;
        for(l=0;l<j-1;l++)
        {
            for(m=l+1;m<j;m++)
            {
                if(arr[l]>arr[m])
                {
                    c++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",c);
    }

    return 0;
}
