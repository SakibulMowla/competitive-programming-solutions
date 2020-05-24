#include <stdio.h>
#include <string.h>

char arr[100+10],arr1[100+10],str[100+10];
int len;

int main()
{
    int n,m,i,j,k,res;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",arr);
        len=strlen(arr);

        m=0;
        for(j=0; j<len; j++)
        {
            str[m++]=arr[j];
            str[m]='\0';
            strcpy(arr1,str);
            for(k=0;k<len/m-1;k++)
            {
                strcat(arr1,str);
            }

            if(strcmp(arr1,arr)==0)
            {
                printf("%d\n",m);
                break;
            }
        }
        if(i<n-1)
            printf("\n");
    }
    return 0;
}
