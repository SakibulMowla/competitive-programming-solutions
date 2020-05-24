#include <stdio.h>

int main()
{
    int i,n;
    char z,ch,prech,str[]={"OIZEASGTBP"};

    scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {
        prech=' ';
        while(scanf("%c",&ch)==1)
        {
            if(ch=='\n' && prech=='\n')
                break;
            if(ch>='0' && ch<='9')
                printf("%c",str[ch-'0']);
            else
                printf("%c",ch);
            prech=ch;
        }
        if(i<n-1)
            printf("\n");
    }
    return 0;
}
