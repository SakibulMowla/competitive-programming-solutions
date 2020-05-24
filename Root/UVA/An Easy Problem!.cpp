#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int i,len,maxim,sum,flag;
    char arr[5100];
//    freopen("1.txt","r",stdin);
    while(gets(arr))
    {
        maxim = 0;
        sum = 0;
        len = strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]>='0' && arr[i]<='9') {sum+= arr[i] - '0' ; if(arr[i] - '0' > maxim) maxim = arr[i] - '0' ;}
            else if(arr[i]>='A' && arr[i]<='Z') {sum += arr[i] - 55; if(arr[i] - 55 > maxim) maxim = arr[i] - 55 ;}
            else if(arr[i]>='a' && arr[i]<='z') {sum += arr[i] - 61; if(arr[i] - 61 > maxim) maxim = arr[i] - 61 ;}
        }
        maxim = maxim > 0 ? maxim : 1;
        flag = 0 ;
        for(i=maxim;i<=61;i++)
        {
            if(sum % i == 0)
            {
                printf("%d\n",i+1);
                flag = 1;
                break;
            }
        }
        if( !flag ) printf("such number is impossible!\n");
    }

    return 0;
}
