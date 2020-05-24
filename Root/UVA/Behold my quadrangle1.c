#include <stdio.h>
#include <math.h>
int main()
{
    long int arr[4],n,i,j,k,temp;
    scanf("%ld",&n);
    for(k=0;k<n;k++)
    {
        for(i=0;i<4;i++)
            scanf("%ld",&arr[i]);
        for(i=0;i<4-1;i++)
            for(j=i+1;j<4;j++)
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
        if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3])
            printf("square\n");
        else if(arr[0]==arr[1] && arr[2]==arr[3])
            printf("rectangle\n");
        else if(arr[0] + arr[1] + arr[2] >= arr[3])
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
    return 0;
}
