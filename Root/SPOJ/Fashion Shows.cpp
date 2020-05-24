#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

vector <int> men,women;

int main()
{
    int t,i,j,n,m,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        men.clear();
        women.clear();
        for(i=0;i<n;i++)
            scanf("%d",&j) , men.push_back(j);
        for(i=0;i<n;i++)
            scanf("%d",&j) , women.push_back(j);
        k = 0;
        sort(men.begin(),men.end());
        sort(women.begin(),women.end());
        for(i=0;i<n;i++)
        {
            k += (men[i] * women[i]);
        }
        printf("%d\n",k);
    }
    return 0;
}
