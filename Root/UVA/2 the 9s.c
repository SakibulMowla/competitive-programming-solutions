#include<stdio.h>
#include<string.h>

int main(void)
{
    int i,j,len,sum,t,c;
    char arr[1010];
    while(gets(arr))
    {
        len=strlen(arr);
        if(len==1 && arr[0]=='0')
            break;
        sum=0;
        c=1;
        for(i=0; i<len; i++)
            sum+=arr[i]-'0';
        if(sum%9 != 0)
            printf("%s is not a multiple of 9.\n",arr);
        else
        {
            while(sum!=9)
            {
                j=0;
                for(t=sum; t>0; t/=10)
                    j+=t%10;
                sum=j;
                c++;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n",arr,c);
        }
    }

    return 0;
}
