#include "stdio.h"
#include "iostream"
#include "set"

using namespace std;

typedef long long ll;

ll n,a,b;
set <ll> myset;

void dfs(ll num,ll digit)
{
    if(num > n || digit>10) return;
    myset.insert(num);
    dfs(num*10+a , digit+1);
    dfs(num*10+b , digit+1);
}

int main()
{
    while(scanf("%I64d",&n) == 1)
    {
        for(a=0;a<=9;a++)
            for(b=a+1;b<=9;b++)
                dfs(0,0);
        printf("%I64d\n",myset.size()-1);
        myset.clear();
    }

    return 0;
}
