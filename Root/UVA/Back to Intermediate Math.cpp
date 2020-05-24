#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
    double d,u,v,t1,t2,p;
    int i,n;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> d >> v >> u;
        if(u==0 || v==0 || u<=v)
            cout << "Case " << i+1 << ": " << "can't determine" << endl;
        else
        {
            t1=d/u;
            t2=d/sqrt(u*u-v*v);
            p=abs(t1-t2);
            cout << "Case " << i+1 << ": " << setprecision(3) << fixed << p << endl;
        }
    }

    return 0;
}
