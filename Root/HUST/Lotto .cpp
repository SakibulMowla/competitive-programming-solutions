#include "stdio.h"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

vector <int> v;

int main()
{
    int i,j,n;
    bool blank = false;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) == 1 && n)
    {
        if(blank) printf("\n");
        blank = true;
        v.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            v.push_back(j);
        }
        sort(v.begin(),v.end());
        for(int p=0;p<n;p++)
        for(int q=p+1;q<n;q++)
        for(int r=q+1;r<n;r++)
        for(int s=r+1;s<n;s++)
        for(int t=s+1;t<n;t++)
        for(int u=t+1;u<n;u++)
            printf("%d %d %d %d %d %d\n",v[p],v[q],v[r],v[s],v[t],v[u]);
    }

    return 0;
}
