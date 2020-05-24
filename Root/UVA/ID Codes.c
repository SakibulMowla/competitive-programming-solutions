#include <stdio.h>
#include <string.h>

int main()
{
    int n,m,i,j,k,l,len,flag1,flag2;
    char arr[100],temp;
    while(scanf("%s",arr)==1)
    {
        len=strlen(arr);
        flag1=flag2=0;
        if(len==1 && arr[0]=='#')break;
        for(n=0;n<len-1;n++)
        {
            if(arr[n] < arr[n+1])
            {
                i=n;
                flag1=1;
            }
        }
        for(n=0;n<len;n++)
        {
            if(arr[n] > arr[i])
            {
                j=n;
                flag2=1;
            }
        }
        if(flag1==1 && flag2==1)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            for(n=i+1,m=len-1;n<i+1+(len-i-1)/2;n++,m--)
            {
                temp=arr[n];
                arr[n]=arr[m];
                arr[m]=temp;
            }
            printf("%s\n",arr);
        }
        else
            printf("No Successor\n");
    }
    return 0;
}
