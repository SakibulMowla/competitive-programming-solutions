#include<stdio.h>

int main()
{
    int n,i,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(a<b)
            printf("impossible\n");
        else
        {
            if(((a+b)%2)==0 && ((a-b)%2)==0)
                printf("%d %d\n",((a+b)/2),((a-b)/2));
            else
                printf("impossible\n");
        }
    }

    return 0;
}
