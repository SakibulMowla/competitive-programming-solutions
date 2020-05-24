#include<stdio.h>
#include<string.h>

int main()
{
    char str1[1000],str2[1000];
    int j,n,len1,len2,i,flag;

    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        scanf("%s",&str1);
        scanf("%s",&str2);

        len1=strlen(str1);
        len2=strlen(str2);

        flag=0;
        if(len1!=len2)
            printf("No\n");
        else if(len1==len2)
        {
            for(i=0; i<len1; i++)
            {
                if((toupper(str1[i])=='A'||toupper(str1[i])=='E'||toupper(str1[i])=='I'||toupper(str1[i])=='O'||toupper(str1[i])=='U') && (toupper(str2[i])=='A'||toupper(str2[i])=='E'||toupper(str2[i])=='I'||toupper(str2[i])=='O'||toupper(str2[i])=='U'))
                    continue;
                else if(str1[i]==str2[i])
                    continue;
                else if(str1!=str2)
                    flag++;
            }

            if(flag==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
