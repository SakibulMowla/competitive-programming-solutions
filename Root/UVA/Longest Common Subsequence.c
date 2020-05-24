#include <stdio.h>
#include <string.h>

#define N 1010
#define max(a,b) a>b?a:b

char arr1[N],arr2[N];
int str[N][N];

int main()
{
    int i,j,len1,len2;
    while(gets(arr1) && gets(arr2))
    {
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(arr1[i-1]==arr2[j-1])
                    str[i][j]=str[i-1][j-1]+1;
                else
                    str[i][j]=max(str[i][j-1],str[i-1][j]);
            }
        }
        printf("%d\n",str[len1][len2]);
    }

    return 0;
}
