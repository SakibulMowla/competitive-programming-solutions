#include <stdio.h>
#include <string.h>

int a, b, c, d, e, f;
int hexa[10010];
int fn( int n )
{
    if( n == 0 ) return a % 10000007;
    if( n == 1 ) return b % 10000007;
    if( n == 2 ) return c % 10000007;
    if( n == 3 ) return d % 10000007;
    if( n == 4 ) return e % 10000007;
    if( n == 5 ) return f % 10000007;
    if(hexa[n-1] ==0 )
        hexa[n-1]=fn(n-1);
    if(hexa[n-2] ==0 )
        hexa[n-2]=fn(n-2);
    if(hexa[n-3] ==0 )
        hexa[n-3]=fn(n-3);
    if(hexa[n-4] ==0 )
        hexa[n-4]=fn(n-4);
    if(hexa[n-5] ==0 )
        hexa[n-5]=fn(n-5);
    if(hexa[n-6] ==0 )
        hexa[n-6]=fn(n-6);
    return (hexa[n-1]+hexa[n-2]+hexa[n-3]+hexa[n-4]+hexa[n-5]+hexa[n-6]) % 10000007;
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        memset(hexa,0,sizeof(hexa));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) );
    }
    return 0;
}
