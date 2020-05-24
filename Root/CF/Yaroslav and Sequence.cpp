using namespace std;

#include "stdio.h"
#include "iostream"

typedef long long ll;
template <class T> T mini(T a,T b) { return a < b ? a : b; }

int main()
{
    ll i,j,k,n,m,sum,minim;
    while(cin >> n)
    {
        m = n;
        n = (2*n) - 1;
        k = sum = 0;
        minim = (1LL<<28);
        for(i=0;i<n;i++)
        {
            cin >> j;
            if(j < 0)
                k++ , j = -j;
            sum += j;
            minim = mini(minim , j);
        }
        if((k&1) && !(m&1)) sum -= (2*minim);
        cout << sum << "\n";
    }

    return 0;
}
