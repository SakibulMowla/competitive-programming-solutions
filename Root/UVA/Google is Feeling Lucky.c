#include <stdio.h>
#include <string.h>

typedef struct{
    char web[105];
    int hit;
}data;
int main()
{
    data arr[10];
    int i,j,n,max;
    char z;
    scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {
        max=0;
        for(j=0;j<10;j++)
        {
            scanf("%s %d",arr[j].web,&arr[j].hit);
            if(arr[j].hit>max)
                max=arr[j].hit;
        }
        printf("Case #%d:\n",i+1);
        for(j=0;j<10;j++)
            if(arr[j].hit==max)
                printf("%s\n",arr[j].web);
    }
    return 0;
}
