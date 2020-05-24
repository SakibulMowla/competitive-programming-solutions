#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,n,c,len1,len2,len3,d;
    char z,z1,arr1[1000],arr2[1000],str[1000];

    scanf("%d%c",&n,&z1);
    for(i=0;i<n;i++)
    {
        gets(arr1);
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        if(len1==len2)
        {
            if(strcmp(arr1,arr2)==0)
                printf("Case %d: Yes\n",i+1);
            else
                printf("Case %d: Wrong Answer\n",i+1);
        }
        else
        {
            c=0;
            for(j=0;j<len1;j++)
                if(arr1[j]!=' ')
                    str[c++]=arr1[j];
            str[c]='\0';
            len3=strlen(str);
            c=0;d=0;
            for(j=0;j<len2;j++)
            {
                if(arr2[j]==str[j])
                    c++;
            }
            if(len2==len3 && c==len2)
                printf("Case %d: Output Format Error\n",i+1);
            else
                printf("Case %d: Wrong Answer\n",i+1);
        }
    }
    return 0;
}
