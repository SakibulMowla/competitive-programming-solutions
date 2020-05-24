using namespace std;

#include "stdio.h"
#include "math.h"
#include "iostream"
#include "vector"

#define SZ 100010

int arr[SZ], num[SZ];
vector <int> v;

int main()
{
    int i,j,k,n,m;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&i);
        v.push_back(i);
    }

    printf("%d\n",min(n,2));
    printf("%d",v[0]);
    for(i=1;i<2 && i<v.size();i++)
        printf(" %d",v[i]);
    printf("\n");

    return 0;
}
