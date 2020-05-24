#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    int i,k,len,sum,n;
    char num[1000];
    int hex[1000];
    while(gets(num))
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
            k=0;
            for(i=0; n>0; i++)
            {
                hex[i]=n%16;
                n/=16;
                k++;
            }
            printf("0x");
            for(i=k-1; i>=0; i--)
            {
                if(hex[i]==10)printf("A");
                else if(hex[i]==11)printf("B");
                else if(hex[i]==12)printf("C");
                else if(hex[i]==13)printf("D");
                else if(hex[i]==14)printf("E");
                else if(hex[i]==15)printf("F");
                else printf("%d",hex[i]);
            }
            printf("\n");
        }
    }

    return 0;

}
