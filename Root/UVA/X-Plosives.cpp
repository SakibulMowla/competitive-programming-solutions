#include "stdio.h"
#include "string.h"
#include "map"
#include "iostream"
using namespace std;
#define SZ 100010

int par[SZ];

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

struct data
{
    int x,y;
} arr[SZ];

map <int , int> M;

int main()
{
    int i,j,k,l,n,m;
    while(scanf("%d",&i) == 1)
    {
        M.clear();
        n = m = 0;
        while(i != -1)
        {
            scanf("%d",&j);
            if(M.find(i) == M.end()) M[i] = m++;
            if(M.find(j) == M.end()) M[j] = m++;
            arr[n].x = M[i];
            arr[n].y = M[j];
            n++;
            scanf("%d",&i);
        }
        k = 0;
        for(j=0; j<=m; j++)
            par[j] = j;
        for(i=0; i<n; i++)
        {
            l = find(arr[i].x);
            j = find(arr[i].y);
            if(l != j) par[l] = j;
            else k++;
        }
        printf("%d\n",k);
    }

    return 0;
}
