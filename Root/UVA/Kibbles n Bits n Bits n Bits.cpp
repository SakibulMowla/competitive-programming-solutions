#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"

int hex_to_dec(char *arr)
{
    int i,j,len,dec;
    dec = 0;
    len = strlen(arr);
    j = len - 1;
    for(i=0; i<len; i++)
    {
        if(arr[i] >= '0' && arr[i] <= '9')
            dec += ( (arr[i]-'0') * pow(16,j) );
        else if(toupper(arr[i]) >= 'A' && toupper(arr[i]) <= 'Z')
            dec += ( (toupper(arr[i]) - 55) * pow(16,j) );
        j--;
    }
    return dec;
}

void dec_to_bin(int num)
{
    int i,j,k;
    char arr[14];
    for(i=0; i<13; i++)
        arr[i] = '0';
    arr[i] = '\0';

    for(k = 12 ; num > 0; num /= 2,k--)
        arr[k] = (num % 2) + '0';

    printf("%s",arr);
}

int main()
{
    int dec1,dec2,test,res;
    char ch , hex1[10] , hex2[10];


    scanf("%d",&test);
    while(test--)
    {
        scanf(" %s %c %s",hex1,&ch,hex2);

        dec1 = hex_to_dec(hex1);
        dec2 = hex_to_dec(hex2);

        dec_to_bin(dec1);
        printf(" %c ",ch);
        dec_to_bin(dec2);

        if(ch == '+')
            res = dec1 + dec2;
        else
            res = dec1 - dec2;
        printf(" = %d\n",res);
    }

    return 0;
}
