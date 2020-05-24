#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    int i,k,len,sum,n;
    char num[1000];
    int hex[1000];
    while()
    {
        len=strlen(num);
        if(atoi(num)<0)
            break;
        sum=0;
        if(num[0]=='0' && num[1]=='x')
        {
            for(i=2,k=len-3; i<len; i++,k--)
            {
                if(num[i]>='0' && num[i]<='9')
                    sum+=(num[i]-'0')*(pow(16,k));
                else if(toupper(num[i])>='A' && toupper(num[i])<='F')
                    sum+=(toupper(num[i])-55)*(pow(16,k));
            }
            printf("%d\n",sum);
        }
        else
        {
             n=atoi(num);
             printf("0x%X\n",n);
        }
    }

    return 0;
}

