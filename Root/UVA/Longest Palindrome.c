#include <stdio.h>
#include <string.h>

#define max 1010
#define maximum(a,b) a>b?a:b

char arr[max];

int str[max][max];

int main()
{
    int n,m,i,j,k,len;
    char z;
    scanf("%d%c",&n,&z);

    for(k=0; k<n; k++)
    {
        gets(arr);

        len=strlen(arr);

        for(i=1; i<=len; i++)
        {
            for(j=1,m=len; j<=len; j++,m--)
            {
                if(arr[i-1]==arr[m-1])
                    str[i][j]=str[i-1][j-1] + 1;
                else
                    str[i][j] = maximum( str[i-1][j] , str[i][j-1] );
            }
        }

        printf("%d\n",str[len][len]);

    }


    return 0;
}
