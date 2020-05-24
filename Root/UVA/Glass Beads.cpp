#include "stdio.h"
#include "string.h"

int minimum_expression(char *s)
{
    int i,j,k,len,x,y,tmp;

    len = strlen(s);
    i = 0 , j = 1 , k = 0;

    while(i < len && j < len && k < len)
    {
        x = i + k;
        y = j + k;
        if(x >= len) x -= len;
        if(y >= len) y -= len;

        if(s[x] == s[y])
        {
            k++;
        }
        else if(s[x] > s[y])
        {
            i = j+1 > i+k+1 ? j+1 : i+k+1;
            k = 0;
            tmp = i , i = j , j = tmp;
        }
        else
        {
            j = i+1 > j+k+1 ? i+1 : j+k+1;
            k = 0;
        }
    }

    return i;
}

int main()
{
    int t;
    char arr[10100];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",arr);
        printf("%d\n",minimum_expression(arr)+1);
    }

    return 0;
}
