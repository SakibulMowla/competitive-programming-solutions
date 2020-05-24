#include "stdio.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

int main()
{
    vector <double> v;
    double d;
    while(scanf("%lf",&d) == 1)
        v.push_back(sqrt(d));
    for(int i=v.size()-1; i>=0; i--)
        printf("%.4lf\n",v[i]);
}
