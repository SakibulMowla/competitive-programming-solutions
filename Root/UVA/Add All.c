#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,i,j,k,sum;
    priority_queue <int> pq;
    while(scanf("%d",&n) == 1 && n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            pq.push_back(k);
        }
        sum=pq.top();
        while( !pq.empty() )
        {
            sum+=pq.top();
            pq.pop();
        }
        printf("%d\n",sum);
    }

    return 0;
}
