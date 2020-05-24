#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n,i,j,k,carry,sum[110],test,len,len1,len2,num1[110],num2[110];
    char str[110];
    scanf("%d",&test);
    while(test--)
    {
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        scanf("%s",str);
        len = strlen(str);
        i = 0;
        while(str[i] == '0') i++;
        len1 = len - i;
        for(j=0;j<len1;j++)
            num1[j] = str[j+i] - '0';

        scanf("%s",str);
        len = strlen(str);
        i = 0;
        while(str[i] == '0') i++;
        len2 = len - i;
        for(j=0;j<len2;j++)
            num2[j] = str[j+i] - '0';

        len = len1 > len2 ? len1 : len2;

        carry = 0;
        for(i=0;i<len;i++)
        {
            sum[i] = (num1[i] + num2[i] + carry) % 10;
            carry = (num1[i] + num2[i] + carry) / 10;
        }
        while(carry > 0)
        {
            sum[i++] = carry % 10;
            carry /= 10;
        }
        len = i;
        i = 0;
        while(sum[i] == 0) i++;
        for(j=i;j<len;j++)
            printf("%d",sum[j]);
        if( len == 0 ) printf("0");
        printf("\n");
    }

    return 0;
}
