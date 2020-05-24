#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#define SZ 1000001
int arr[SZ];
vector <int> v[SZ];
int main()
{
    int n,q,i,j,oc,num;
    while(scanf("%d %d",&n,&q) == 2)
    {
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
            v[i].clear();
        for(i=0;i<n;i++)
            v[arr[i]].push_back(i+1);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&oc,&num);
            if(v[num].size() < oc) printf("0\n");
            else printf("%d\n",v[num][oc-1]);
        }
    }

    return 0;
}
