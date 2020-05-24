#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,i,j,k,len,l;
    char arr[1000],prech,z;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        l=0;
        scanf("%d",&m);
        scanf("%c",&z);

        for(j=0;j<m;j++)
        {
            gets(arr);
            len=strlen(arr);
            prech='a';
            if(l==0 && i!=1)printf("\n");
            if(l==0)printf("Case %d:\n",i);l++;
            for(k=0;k<len;k++)
            {
                if(arr[k]==' ' && prech==' ')
                {
                    prech=arr[k];
                    continue;
                }
                else
                {
                    printf("%c",arr[k]);
                    prech=arr[k];
                }
            }
            printf("\n");
        }
    }
    return 0;
}
