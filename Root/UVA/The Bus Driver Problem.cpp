#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    long long i,n,r,d,sum;
    vector <long long> morning , evening;
//    freopen("1.txt","r",stdin);
    while(scanf("%lld %lld %lld",&n,&d,&r) == 3)
    {
        morning.clear();
        evening.clear();
        if(n==0 && d==0 && r==0)break;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&sum);
            morning.push_back(sum);
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld",&sum);
            evening.push_back(sum);
        }
        sort(morning.begin(),morning.end());
        sort(evening.rbegin(),evening.rend());
        sum = 0;
        for(i=0;i<n;i++)
        {
            if(morning[i] + evening[i] > d)
                sum += morning[i] + evening[i] - d;
        }
        sum *= r;
        printf("%lld\n",sum);
    }
    return 0;
}
