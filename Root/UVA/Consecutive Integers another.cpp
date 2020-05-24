#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long LL;

// theory : sum = n/2 { 2*a + (n - 1)*d }

int main()
{
    LL a,n,sum,posn,i;
    while(scanf("%lld",&sum) == 1 && sum!=-1)
    {
        posn = sqrt(2*sum);
        for(i=posn;i>=1;i--)
        {
            if( (2*sum + i - (i*i)) % (2*i) == 0 )
            {
                n = i;
                break;
            }
        }
        a = (2*sum + n - (n*n)) / (2*n);
        n = a + n - 1;
        printf("%lld = %lld + ... + %lld\n",sum,a,n);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long LL;

// theory : sum = n/2 { 2*a + (n - 1)*d }

int main()
{
    LL a,n,sum,posn,i;
    while(scanf("%lld",&sum) == 1 && sum!=-1)
    {
        posn = sqrt(2*sum);
        for(i=posn;i>=1;i--)
        {
            if( (2*sum + i - (i*i)) % (2*i) == 0 )
            {
                n = i;
                break;
            }
        }
        a = (2*sum + n - (n*n)) / (2*n);
        n = a + n - 1;
        printf("%lld = %lld + ... + %lld\n",sum,a,n);
    }

    return 0;
}
