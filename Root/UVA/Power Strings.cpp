#include <cstdio>
#include <cstring>

char arr[1000000+10];
int main()
{
    int n,i,j,k,len,pow,flag;
    while(scanf("%s",arr)==1)
    {
        if(strcmp(arr,".")==0)break;
        pow=1;
        len=strlen(arr);
        for(i=2; i<=len; i++)
        {
            if(len % i==0)
            {
                j=len/i;
                flag=1;
                for(k=j; k<len; k++)
                {
                    if(arr[k] != arr[k%j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    pow=i;
                }
            }
        }
        printf("%d\n",pow);
    }
    return 0;
}
