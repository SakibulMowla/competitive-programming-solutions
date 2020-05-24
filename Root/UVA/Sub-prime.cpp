#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int bank[25],debtor,creditor,debenture,i,b,n;
    char ch;
    while(scanf("%d %d",&b,&n) == 2)
    {
        if(b==0 && n==0)break;
        ch = 'S';
        memset(bank,0,sizeof(bank));
        for(i=1;i<=b;i++)
            scanf("%d",&bank[i]);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&debtor,&creditor,&debenture);
            bank[debtor] -= debenture;
            bank[creditor] += debenture;
        }
        for(i=1;i<=b;i++)
            if(bank[i] < 0)
                {ch = 'N';break;}
        printf("%c\n",ch);
    }


    return 0;
}
