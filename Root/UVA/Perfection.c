#include<stdio.h>
#include<string.h>

int main(void)
{
    int i,j,sum;
    int arr[1000];
    for(j=0;;j++)
    {
        scanf("%d",&arr[j]);
        if(arr[j]==0)
            break;
    }

    printf("PERFECTION OUTPUT\n");

    for(j=0;;j++)
    {
        if(arr[j]==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        sum=0;
        for(i=1;i<=(arr[j]/2);i++)
        {
            if(arr[j]%i==0)
                sum+=i;
        }
        if(sum==arr[j])
            printf("%5d  PERFECT\n",arr[j]);
        else if(sum<arr[j])
            printf("%5d  DEFICIENT\n",arr[j]);
        else if(sum>arr[j])
            printf("%5d  ABUNDANT\n",arr[j]);
    }
    return 0;
}
