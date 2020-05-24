#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

#define SZ 10000010

bool arr[SZ] ;
vector <int> prime , ans;
map <int , int> m;

void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=4; i<SZ; i+=2)
        arr[i] = 1;
    for(i=3; i<sqrt(SZ); i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    j = 0;
    m[2] = j;
    for(i=3; i<SZ; i+=2)
        if(arr[i] == 0)
            m[i] = ++j , prime.push_back(i);
}

bool bctk(int n,int p)
{
//    printf("n = %d p = %d\n",n,p);
    int i,j,k,start;
    bool flag;
    if(p==1)
    {
        if(arr[n] == 0)
        {
            ans.push_back(n);
            printf("%d",ans[0]);
            for(i=1; i<4; i++)
                printf(" %d",ans[i]);
            printf("\n");
            return true;
        }
        return false;
    }
    start = -1;
    for(i=n-1; i>=0; i--)
        if(arr[i] == 0)
        {
            start = m[i] ;
            break;
        }
    flag = false;
    for(i=start; i>=0; i--)
    {
        ans.push_back(prime[i]);
        flag = bctk(n - prime[i],p-1);
        if(flag) return true;
        ans.pop_back();
    }
    return false;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d",&n) == 1)
    {
        ans.clear() ;
        if(bctk(n,4) == false)
            printf("Impossible.\n");
    }

    return 0;
}
