#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long test,i,j,k,l,cost;
    vector <long long> v;

    scanf("%lld",&test);
    while(test--)
    {
        v.clear();
        while(scanf("%lld",&cost) == 1 && cost)
        {
            v.push_back(cost);
        }
        sort(v.rbegin(),v.rend());
        cost = 0;
        for(i=0;i<v.size();i++)
        {
            cost += (2 * pow(v[i] , i+1));
        }
        if(cost <= 5000000)
            printf("%lld\n",cost);
        else
            printf("Too expensive\n");
    }

    return 0;
}
