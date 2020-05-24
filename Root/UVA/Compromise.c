#include <stdio.h>
#include <string.h>

#define max(a,b) a>b?a:b
#define N 110
#define M 35

char arr1[N][M],arr2[N][M],lcs[N][M],test[M];
int str[N][N];

int main()
{
    int len1,len2,n,m,i,j,k;

    while(scanf("%s",test)!=EOF)
    {
        i=0;
        strcpy(arr1[i],test);
        while(strcmp(arr1[i],"#")!=0)
        {
            i++;
            scanf("%s",arr1[i]);
        }
        len1=i;

        i=0;
        while(scanf("%s",arr2[i])==1)
        {
            if(strcmp(arr2[i],"#")==0)break;
            i++;
        }
        len2=i;

        for(i=1; i<=len1; i++)
        {
            for(j=1; j<=len2; j++)
            {
                if(strcmp(arr1[i-1],arr2[j-1])==0)
                    str[i][j]=str[i-1][j-1]+1;
                else
                    str[i][j]=max( str[i-1][j],str[i][j-1] );
            }
        }

        k=0;
        i=len1;
        j=len2;
        while(str[i][j] > 0)
        {
            if( strcmp(arr1[i-1],arr2[j-1]) == 0 )
            {
                strcpy(lcs[k++],arr1[i-1]);
                i--;
                j--;
            }
            else if(str[i-1][j] > str[i][j-1])
            {
                i--;
            }
            else
                j--;
        }

        if(k>0)
        {
            for(i=k-1; i>=0; i--)
            {
                if(i==k-1)
                    printf("%s",lcs[i]);
                else
                    printf(" %s",lcs[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
