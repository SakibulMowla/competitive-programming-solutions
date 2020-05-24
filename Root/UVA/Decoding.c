#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k,l,n;
    char z,ch;
    scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {
        scanf("%c",&ch);
        l=0;
        while(ch!='\n')
        {
            scanf("%d",&j);
            if(l==0)
                printf("Case %d: ",i+1);
            for(k=0;k<j;k++)
                printf("%c",ch);
            scanf("%c",&ch);
            l++;
        }
        printf("\n");
    }
    return 0;
}
