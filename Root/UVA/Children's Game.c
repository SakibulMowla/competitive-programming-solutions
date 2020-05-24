#include <stdio.h>
#include <string.h>

int len;

int equal(char str1[200],char str2[200])
{
    int i;
    for(i=0; i<len; i++)
    {
        if(str2[i] > str1[i])
            return 0;
        if(str1[i] > str2[i])
            return 1;
    }
    return 1;
}

int main()
{
    int n,i,j,res2;
    char arr[50+5][1000],temp[1000],str1[2000],str2[2000];
    while(scanf("%d",&n) && n)
    {
        for(i=0; i<n; i++)
            scanf("%s",arr[i]);

        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                strcpy(str1,arr[i]);
                strcat(str1,arr[j]);
                strcpy(str2,arr[j]);
                strcat(str2,arr[i]);
                len=strlen(str1);

                res2=equal(str1,str2);
                if(res2==0)
                {
                    strcpy(temp,arr[i]);
                    strcpy(arr[i],arr[j]);
                    strcpy(arr[j],temp);
                }
            }

        }
        for(i=0; i<n; i++)
            printf("%s",arr[i]);
        printf("\n");
    }
    return 0;
}
