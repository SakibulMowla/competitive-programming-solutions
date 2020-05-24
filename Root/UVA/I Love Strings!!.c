#include <stdio.h>
#include <string.h>

int main()
{
    int n,m,i,j,k,len2;
    char arr[100000+5],str[1000+5];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",arr);
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%s",str);
            len2=strlen(str);
            for(k=0;str[k];k++)
            {
                if(str[k]!=arr[k])
                    break;
            }
            if(k==len2)
                printf("y\n");
            else
                printf("n\n");
        }
    }

    return 0;
}
