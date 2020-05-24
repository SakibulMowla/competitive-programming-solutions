#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <int> V;

int main()
{
    int test,n,i,cost;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        V.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&cost);
            V.push_back(cost);
        }
        sort(V.rbegin(),V.rend());
        cost = 0;
        for(i=2;i<n;i+=3)
            cost += V[i] ;
        printf("%d\n",cost);
    }

    return 0;
}
