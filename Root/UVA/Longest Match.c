#include <stdio.h>
#include <string.h>

#define max(a,b) a>b?a:b

char arr1[1010][20],arr2[1010][20],str1[1010],str2[1010];
int str[1010][1010];

int main()
{
    int i,j,k,count,count1,count2,len1,len2;
    char prech;

    count=0;
    while(gets(str1) && gets(str2))
    {
        len1=strlen(str1);
        len2=strlen(str2);
        if(len1==0 || len2==0)
        {
            printf("%2d. Blank!\n",++count);
            continue;
        }
        k=j=0;
        prech=' ';
        for(i=0;i<len1;i++)
        {
            if((toupper(str1[i]) >= 'A' && toupper(str1[i]) <='Z') ||  (str1[i]>='0' && str1[i]<='9'))
            {
                arr1[k][j++]=str1[i];
            }

            else if((toupper(prech) >= 'A' && toupper(prech) <='Z') || (prech>='0' && prech<='9'))
            {
                arr1[k][j]='\0';
                k++;
                j=0;
            }
            prech=str1[i];
        }
        if((toupper(prech) >= 'A' && toupper(prech) <='Z') || (prech>='0' && prech<='9'))
            arr1[k++][j]='\0';
        count1=k;

        k=j=0;
        prech=' ';
        for(i=0;i<len2;i++)
        {
            if((toupper(str2[i]) >= 'A' && toupper(str2[i]) <='Z') || (str2[i]>='0' && str2[i]<='9'))
            {
                arr2[k][j++]=str2[i];
            }

            else if((toupper(prech) >= 'A' && toupper(prech) <='Z') || (prech>='0' && prech<='9'))
            {
                arr2[k][j]='\0';
                k++;
                j=0;
            }
            prech=str2[i];
        }
        if((toupper(prech) >= 'A' && toupper(prech) <='Z') || (prech>='0' && prech<='9'))
            arr2[k++][j]='\0';
        count2=k;
        for(i=1;i<=count1;i++)
        {
            for(j=1;j<=count2;j++)
            {
                if(strcmp( arr1[i-1] , arr2[j-1] ) == 0)
                    str[i][j] = str[i-1][j-1] + 1;
                else
                    str[i][j] = max( str[i-1][j] , str[i][j-1] );
            }
        }

        printf("%2d. Length of longest match: %d\n",++count,str[count1][count2]);

    }

    return 0;
}
