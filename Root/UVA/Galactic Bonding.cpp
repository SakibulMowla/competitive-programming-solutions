#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 1010
#define Union(a,b) par[find(a)] = find(b)

int par[SZ];
struct data{double x,y;}arr[SZ];

int find(int r)
{
    if(r == par[r])
        return r;
    return par[r] = find(par[r]);
}

int makeset(int n)
{
    int i;
    for(i=0;i<n;i++)
        par[i] = i;
}

int main()
{
    int t=0,test,n,i,j,cnt,set[SZ];
    double d,dist;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %lf",&n,&d);
        makeset(n);
        for(i=0;i<n;i++)
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                dist = sqrt( pow(arr[i].x-arr[j].x , 2) + pow(arr[i].y-arr[j].y , 2) );
                if(dist <= d)
                    Union(i,j);
            }
        cnt = 0;
        memset(set,0,sizeof(set));
        for(i=0;i<n;i++)
        {
            if(set[find(i)] == 0)
                cnt++ , set[find(i)] = 1;
        }
        printf("Case %d: %d\n",++t,cnt);
    }
    return 0;
}
