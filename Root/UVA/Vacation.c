#include <stdio.h>
#include <string.h>

#define N 100
#define max(a,b) a>b?a:b

int str[N+1][N+1];
char arr1[N+1],arr2[N+1];

int main()
{
    int i,j,k,len1,len2;
    k=1;
    while(gets(arr1) && gets(arr2))
    {
        if(strcmp(arr1,"#")==0) break;

        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=1; i<=len1; i++)
        {
            for(j=1; j<=len2; j++)
            {
                if(arr1[i-1]==arr2[j-1])
                {
                    printf("%c",arr1[i-1]);
                    str[i][j]=str[i-1][j-1]+1;
                }
                else
                    str[i][j]=max(str[i-1][j],str[i][j-1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",k,str[len1][len2]);
        k++;
    }
    return 0;
}
