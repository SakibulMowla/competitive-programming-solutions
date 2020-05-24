#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
#include "iostream"

using namespace std;

#define inf 1<<28
#define SZ 10010

int memo[SZ];

int a, b, c, d, e, f;
int fn( int n )
{
    if(memo[n] != -1) return memo[n];
    if( n == 0 ) return a% 10000007;
    if( n == 1 ) return b% 10000007;
    if( n == 2 ) return c% 10000007;
    if( n == 3 ) return d% 10000007;
    if( n == 4 ) return e% 10000007;
    if( n == 5 ) return f% 10000007;
    return memo[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % 10000007;
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        memset(memo,-1,sizeof(memo));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
