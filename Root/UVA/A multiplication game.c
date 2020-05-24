#include <stdio.h>

int main()
{
    long long n;

    while(scanf("%lld",&n)==1)
    {
        if(n<=9)printf("Stan wins.\n");
        else if(n<=9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9)printf("Stan wins.\n");
        else if(n<=9*2*9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9*2*9)printf("Stan wins.\n");
        else if(n<=9*2*9*2*9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9*2*9*2*9)printf("Stan wins.\n");
        else if(n<=9*2*9*2*9*2*9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9)printf("Stan wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9*2*9)printf("Stan wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9*2*9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9*2*9*2*9)printf("Stan wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9*2*9*2*9*2)printf("Ollie wins.\n");
        else if(n<=9*2*9*2*9*2*9*2*9*2*9*2*9*2*9)printf("Stan wins.\n");
    }
    return 0;
}
