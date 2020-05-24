#include<stdio.h>

int main()
{
    int flag,n,i,j,arr[100];

    scanf("%d",&n);
    printf("Lumberjacks:\n");
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<10;j++)
        {
            scanf("%d",&arr[j]);
        }
        if(arr[0]>arr[1])
        {
            for(j=0;j<9;j++)
            {
                if(arr[j]<arr[j+1])
                    flag++;
            }
            if(flag==0)
                printf("Ordered\n");
            else
                printf("Unordered\n");
        }
        else if(arr[0]<arr[1])
        {
            for(j=0;j<9;j++)
            {
                if(arr[j]>arr[j+1])
                    flag++;
            }
            if(flag==0)
                printf("Ordered\n");
            else
                printf("Unordered\n");
        }
    }

    return 0;
}
