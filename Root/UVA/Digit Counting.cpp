#include <string.h>
#include <stdio.h>

int main()
{
    int t,test,num,i,j,len,digit[20];
    char arr[100000];
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        for(i=0;i<20;i++)
            digit[i]=0;
        scanf("%d",&num);
        for(i=1;i<=num;i++)
        {
            len=sprintf(arr,"%d",i);
            for(j=0;j<len;j++)
                digit[arr[j]-'0']++;
        }
        printf("%d",digit[0]);
        for(i=1;i<10;i++)
            printf(" %d",digit[i]);
        printf("\n");
    }
    return 0;
}
