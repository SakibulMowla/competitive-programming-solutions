#include <stdio.h>
#include <math.h>

#define EPS 1e-7

int p , q , r , s , t , u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

/*double bisection()    // Bisection Method
{
    double low = 0 , high = 1 , x;
    while(low + EPS < high)
    {
        x = (low + high) / 2;
        if( f(low) * f(x) <= 0 )
            high = x;
        else
            low = x;
    }
    return (low + high) / 2;
}*/

/*double secant()       // Secant Method
{
    if (f(0)==0) return 0;
    double x0 = 0 , x1 = 1 , d;
    while(1)
    {
        d = f(x1) * (x1-x0) / (f(x1)-f(x0));
        if(fabs(d) < EPS)
            return x1;
        x0 = x1;
        x1 = x1 - d;
    }
}*/

double fd(double x)
{
    return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x ;
}

double newton()          // Newton Method
{
    if (f(0)==0) return 0;
    double x = 0.5 , x1;
    while(1)
    {
        x1 = x - f(x) / fd(x);
        if(fabs(x1-x) < EPS)
            return x;
        x = x1;
    }
}

int main()
{
    while(scanf("%d %d %d %d %d %d",&p , &q , &r , &s , &t , &u) == 6)
    {
        if( f(0) * f(1) > 0 )
            printf("No solution\n");
        else
            //printf("%.4lf\n",bisection());
            //printf("%.4lf\n",secant());
            printf("%.4lf\n",newton());
    }
    return 0;
}
