#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    unsigned long long c,n,starting_number,sum;
    while(scanf("%llu",&n)==1)
    {
        c=ceil((n-2)/2.);
        starting_number=c*c*2+1;
        sum=starting_number+2*(n-1)+starting_number+2*(n-2)+starting_number+2*(n-3);
        printf("%llu\n",sum);
    }
    return 0;
}
