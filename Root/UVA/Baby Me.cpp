#include <stdio.h>
#include <string.h>

int main()
{
    int a , b , t , p = 0 , test;
    char arr[100];
    double d;
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %s",arr);
        a = b = 0;
        a = arr[0] - '0';
        if(arr[1] >= '0' && arr[1] <= '9') a = (a*10) + arr[1] - '0';
        for(t=2;t<strlen(arr);t++)
            if(arr[t] >= '0' && arr[t] <= '9')
                b = arr[t] - '0';
        d = (double)a * 0.5 + (double)b * 0.05;
        printf("Case %d: %g\n",++p,d);
    }

    return 0;
}
