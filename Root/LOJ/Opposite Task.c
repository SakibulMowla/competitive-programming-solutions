#include <stdio.h>

int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        if(m%2==0)
        printf("%d %d\n",m/2,m/2);
        else
        printf("%d %d\n",(m/2)+1,m/2);
    }

    return 0;
}
