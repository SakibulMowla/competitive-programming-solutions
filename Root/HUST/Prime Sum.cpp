#include "stdio.h"
#include "math.h"
#include "vector"
using namespace std;
const int SZ = 1e6 + 10;
int arr[SZ+10];
vector <int> prime;

struct data
{
    int x,y;
};

vector <data> ans;

void sieve()
{
    int i,j,k;
    k = sqrt(SZ);
    prime.push_back(2);
    for(i=4;i<SZ;i+=2)
        arr[i] = 1;
    for(i=3;i<SZ;i+=2)
    {
        if(arr[i] == 0)
        {
            prime.push_back(i);
            if(i<k)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
        }
    }
}

void solve(int n)
{
    int i,j;
    data u;
    ans.clear();
    for(i=0;prime[i]<=n/2;i++)
    {
        for(j=i;prime[i]+prime[j]<=n;j++)
        {
            if(arr[prime[i]+prime[j]] == 0)
            {
                u.x = prime[i];
                u.y = prime[j];
                ans.push_back(u);
            }
        }
    }
    j = ans.size();
    printf("%d\n",j);
    for(i=0;i<j;i++)
        printf("%d %d\n",ans[i].x,ans[i].y);
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n) == 1)
        solve(n);

    return 0;
}
