#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
#define SZ 100010

const double pi = 2*acos(0.0);

vector <double> angle;

int main()
{
    int i,n,adj;
    double theta,x,y,ans;
    while(scanf("%d",&n) == 1)
    {
        angle.clear();
        for(i=0; i<n; i++)
        {
            scanf("%lf %lf",&x,&y);
            theta = atan2(y,x) * 180 / pi;
            theta = fmod(theta+360,360);
            angle.push_back(theta);
        }
        sort(angle.begin(),angle.end());
        ans = angle[0] - angle[n-1] + 360;
        if(n == 1) printf("%.8lf\n",0);
        else
        {
            for(i=1;i<n;i++)
            {
                ans = max(ans , angle[i] - angle[i-1]);
            }
            printf("%.8lf\n",360-ans);
        }
    }

    return 0;
}
