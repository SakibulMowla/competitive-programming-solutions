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
#define SZ 100


int main()
{
    double n,m,a;
    while(scanf("%lf %lf %lf",&n,&m,&a) == 3)
    {
        printf("%.0lf\n",ceil(n/a)*ceil(m/a));
    }

    return 0;
}
