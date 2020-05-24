#include "stdio.h"
#include "math.h"
#include "map"
#include "iostream"

using namespace std;

#define X it->first
#define Y it->second

map <int , int> mii;
map <int , int> :: iterator it;

int main()
{
    int t,test,n,num,k,popu;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        mii.clear();
        scanf("%d",&n);
        k = n;
        while(k--)
        {
            scanf("%d",&num);
            mii[num]++;
        }
        popu = 0;
        for(it=mii.begin();it!=mii.end();it++)
        {
            popu += ceil( Y*1.0 / (X + 1) ) * (X + 1) ;
        }
        printf("Case %d: %d\n",++t,popu);
    }

    return 0;
}
