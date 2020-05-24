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
#define SZ

int main()
{
    double r1,r2,r3,ta,b,c,s,a,a1,a2,a3,t;
    int n,test = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        a = r1 + r2;
        b = r1 + r3;
        c = r2 + r3;
        s = (a + b + c) / 2;
        ta = sqrt( s * (s-a) * (s-b) * (s-c) );
        a1 = 0.5 * r1 * r1 * acos( (a*a + b*b - c*c) / (2*a*b) );
        a2 = 0.5 * r2 * r2 * acos( (a*a + c*c - b*b) / (2*a*c) );
        a3 = 0.5 * r3 * r3 * acos( (b*b + c*c - a*a) / (2*b*c) );
        t = ta - (a1 + a2 + a3);
        printf("Case %d: %.10lf\n",++test,t);
    }


    return 0;
}
