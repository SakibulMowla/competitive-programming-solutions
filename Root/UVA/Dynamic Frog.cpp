#include "stdio.h"
#include "set"
#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
int main()
{
    vector <int> input;
    int i,j,k=0,t,n,d,ans;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&d);
        input.clear();
        ans = 0;
        input.push_back(0);
        input.push_back(0);
        for(i=0;i<n;i++)
        {
            scanf(" %c-%d",&ch,&j);
            input.push_back(j);
            if(ch == 'B') input.push_back(j);
        }
        input.push_back(d);
        input.push_back(d);
        for(i=2;i<input.size();i++)
            ans = max(ans , input[i] - input[i-2]);
        printf("Case %d: %d\n",++k,ans);
    }

    return 0;
}
