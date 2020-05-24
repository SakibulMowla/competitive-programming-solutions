#include <stdio.h>
#include <string.h>

#define N  1000010

char arr1[N],arr2[N];

int main()
{
    int i,j,len1,len2,count;
    while(scanf("%s %s",&arr1,&arr2)==2)
    {
        len1=strlen(arr1);
        len2=strlen(arr2);
        count=0;
        for(i=0,j=0;i<len1;i++)
        {
            for(;j<len2;j++)
            {
                if(arr1[i]==arr2[j])
                {
                    count++;
                    j++;
                    break;
                }
            }
        }
        if(count==len1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
