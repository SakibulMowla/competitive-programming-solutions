#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct data
{
    int indx;
    double r;
};

bool comp(data p,data q)
{
    return p.r > q.r;
}

vector <data> v;

int main()
{
    int test,n,i,time,cost;
    double ratio;
    data u;
    scanf("%d",&test);
    while(test--)
    {
        v.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&time,&cost);
            u.indx = i + 1;
            u.r = (double)cost / (double)time;
            v.push_back(u);
        }
        sort(v.begin(),v.end(),comp);
        printf("%d",v[0].indx);
        for(i=1;i<n;i++)
            printf(" %d",v[i].indx);
        printf("\n");
        if(test) printf("\n");
    }

    return 0;
}
