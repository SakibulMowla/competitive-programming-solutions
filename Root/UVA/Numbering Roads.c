#include<stdio.h>
int main()
{
    long int a,b,c,j=0;

    while((scanf("%ld %ld",&a,&b))==2)
    {
        if(a==0 && b==0)
            break;
        j++;
        c=a-b;
        if(a<=b)
            printf("Case %ld: 0\n",j);
        else
        {
            if(((double)c/(double)b)>26)
                printf("Case %ld: impossible\n",j);
            else
            {
                if(c%b!=0)
                    printf("Case %ld: %ld\n",j,(c/b)+1);
                else
                    printf("Case %ld: %ld\n",j,(c/b));
            }
        }
    }
    return 0;
}
