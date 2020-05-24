#include<stdio.h>

int main()
{
    double d, a, b, expv;
    char s[12];
    int test, f, i;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%s",s);
        d = 1.0;
        f = 0;
        a = 0.0;
        for(i=0; s[i]; i++)
        {
            if(s[i] != '.')
            {
                if(f)
                    d *= 10.0;
                a += ((double)s[i]-'0') / d;
            }
            else f = 1;
        }
        b = 1.0-a;

        if(b > a)
        {
            expv = a;
            a = b;
            b = expv;
        }

        expv = 10000.0 + (2*b*10000.0)*a - (10000.0*b);

        printf("%.10lf\n",expv);
    }

    return 0;
}
