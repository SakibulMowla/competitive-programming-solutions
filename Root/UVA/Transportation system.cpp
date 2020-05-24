#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
#define SZ 1010
#define Union(a,b) par[find(a)] = find(b)

struct point
{
    int x,y;
};

struct data
{
    int a,b;
    double dist;
};

bool comp(data a,data b)
{
    return  a.dist < b.dist;
}

vector <data> v;

int n,r,state;
double rail,road;
int par[SZ];

int makeset(int n)
{
    for(int i=1; i<=n; i++)
        par[i] =i;
}

int find(int r)
{
    if(r != par[r])
        par[r] = find(par[r]);
    return par[r];
}

void MST()
{
    sort(v.begin(),v.end(),comp);
    int p,q,i,j,k;
    for(i=0; i<v.size(); i++)
    {
        p = v[i].a;
        q = v[i].b;
        if(find(p) == find(q))continue;
        Union(p,q);
        if(v[i].dist<=r)
            road += v[i].dist;
        else
        {
            state++;
            rail += v[i].dist;
        }
    }
}

int main()
{
    point arr[SZ];
    data u;
    int t,test,i,j,k,l,mati,steel;
    double d;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        v.clear();
        scanf("%d %d",&n,&r);
        makeset(n);
        for(i=1; i<=n; i++)
            scanf("%d %d",&arr[i].x,&arr[i].y);

        for(i=1; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                u.a = i;
                u.b = j;
                u.dist = sqrt( pow(arr[i].x-arr[j].x , 2) + pow(arr[i].y-arr[j].y , 2) );
                v.push_back(u);
            }
        }
        state = 1;
        rail = road = 0;
        MST();
        mati = (int) (road + 0.5);
        steel = (int) (rail + 0.5);
        printf("Case #%d: %d %d %d\n",t,state,mati,steel);
    }

    return 0;
}
