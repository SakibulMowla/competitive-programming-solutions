#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char arr[20000],z;
    int n,i,j,k,len;
    double s;
    scanf("%d%c",&n,&z);
    for(k=0;k<n;k++)
    {
        gets(arr);
        len=strlen(arr);
        s=sqrt(len);
        if(s-(int)s != 0)
            printf("INVALID\n");
        else
        {
            for(i=0;i<(int)s;i++)
            {
                for(j=i;j<len;j+=(int)s)
                    printf("%c",arr[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
