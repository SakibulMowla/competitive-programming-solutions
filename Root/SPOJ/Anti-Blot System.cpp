#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    int test , a , b , c ,i;
    char num1[100] , num2[100] , num3[100];
    scanf("%d",&test);
    while(test--)
    {
        a = b = c = 0;
        scanf("%s + %s = %s",num1,num2,num3);
        for(i=0;num1[i];i++)
        {
            if(num1[i]>='0' && num1[i]<='9')
                a = (a*10) + num1[i] - '0';
            else
            {
                a = -1;
                break;
            }
        }
        for(i=0;num2[i];i++)
        {
            if(num2[i]>='0' && num2[i]<='9')
                b = (b*10) + num2[i] - '0';
            else
            {
                b = -1;
                break;
            }
        }
        for(i=0;num3[i];i++)
        {
            if(num3[i]>='0' && num3[i]<='9')
                c = (c*10) + num3[i] - '0';
            else
            {
                c = -1;
                break;
            }
        }
        if(a == -1) a = c - b;
        if(b == -1) b = c - a;
        if(c == -1) c = a + b;
        printf("%d + %d = %d\n",a,b,c);
    }

    return 0;
}
