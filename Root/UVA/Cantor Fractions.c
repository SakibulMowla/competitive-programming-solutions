//Assistance Outsbook http://www.outsbook.com/uva/?page=problem_hints&category=8&id=880
#include <stdio.h>
#include <math.h>

int main()
{
    long y,n,upper_bound,up,down;
    while(scanf("%ld",&y)==1)
    {
        n=ceil(( -1 + ceil( sqrt( 1 + 8*y ))) / 2);
        upper_bound=n*(n+1)/2;
        up=( upper_bound - y ) + 1;
        down=( n - up ) + 1;
        printf("%ld/%ld\n",up,down);
    }
    return 0;
}
