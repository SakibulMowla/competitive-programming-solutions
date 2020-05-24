#include "stdio.h"
#include "string.h"
#include "math.h"

char arr[1010];
int num[1010] , n;

int polyno(int x)
{
    int i,j=0;
    for(i=0;i<n;i++)
    {
        j += num[i] * pow(x,n-i-1);
    }
    return j;
}

int tonum(char *s)
{
    int sign = 1,i,j=0;
    for(i=0;s[i];i++)
    {
        if(s[i] == '-') sign = -1;
        else j = (j*10) + s[i] - '0';
    }
    return sign*j;
}

int main()
{
    int i,j,k;
    char *str;
    while(scanf(" %[^\n]",arr) == 1)
    {
        str = strtok(arr," ");
        j = k = 0;
        while(str)
        {
            num[j++] = tonum(str);
            str = strtok(NULL," ");
        }
        n = j;
        scanf(" %[^\n]",arr);
        str = strtok(arr," ");
        while(str)
        {
            j = tonum(str);
            if(k) printf(" ");
            k = 1;
            printf("%d",polyno(j));
            str = strtok(NULL," ");
        }
        printf("\n");
    }

    return 0;
}
