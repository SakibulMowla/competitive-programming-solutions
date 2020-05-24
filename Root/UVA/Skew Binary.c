#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    long long int i,k,len,sum;
    char arr[1000];
    while(gets(arr))
    {
        len=strlen(arr);
        if(len==1 && arr[0]=='0')
            break;
        sum=0;
        for(k=1,i=len-1;i>=0;i--,k++)
        {
            sum+=((arr[i]-'0')*(pow(2,k)-1));
        }
        printf("%lld\n",sum);
    }
    return 0;
}
