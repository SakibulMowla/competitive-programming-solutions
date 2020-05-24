#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int color[50];
int circle[20];
vector <int> result;
int n;

void sieve(void)
{
    int i,j;
    color[0] = color[1] = 1;
    for(i=4; i<50; i+=2)
        color[i] = 1;
    for(i=3; i<sqrt(50); i+=2)
        if(color[i] == 0)
            for(j=i*i; j<50; j+=i+i)
                color[j] = 1;
    return;
}

void backtrack(int p)
{
    int i;
    if(result.size() == n)
    {
        if(color[p+result[0]] == 0)
        {
            cout<<result[0];
            for(i=1; i<n; i++)
                cout<<" "<<result[i];
            printf("\n");
            return;
        }
        else
            return;
    }
    for(i=2; i<=n; i++)
    {
        if(circle[i] == 0 && color[p+i]==0)
        {
            result.push_back(i);
            circle[i] = 1;
            backtrack(i);
            circle[i] = 0;
            result.pop_back();
        }
    }
    return;
}

int main()
{
    sieve();
    int test=0;
    while(scanf("%d",&n) == 1)
    {
        if(test)printf("\n");
        memset(circle,0,sizeof(circle));
        result.clear();
        result.push_back(1);
        printf("Case %d:\n",++test);
        backtrack(1);
    }

    return 0;
}
