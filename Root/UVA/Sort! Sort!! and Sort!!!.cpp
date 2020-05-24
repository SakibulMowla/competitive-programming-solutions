#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct data
{
    long num,mod;
};

vector <data> v;

bool even(long n)
{
    if(n<0) n *= -1;
    if(n%2 == 0)return true;
    return false;
}

bool odd(long n)
{
    if(n<0) n *= -1;
    if(n%2 == 1)return true;
    return false;
}

bool comp(data a,data b)
{
    if( a.mod < b.mod )
        return true;

    if(a.mod == b.mod)
    {
        if(odd(a.num) && even(b.num))
            return true;
        if(odd(a.num) && odd(b.num) && a.num>b.num)
            return true;
        if(even(a.num) && even(b.num) && a.num < b.num)
            return true;
    }
    return false;
}

int main()
{
    data store;
    long n,m,element,i,j,k;
    while(scanf("%ld %ld",&n,&m) == 2)
    {
        printf("%ld %ld\n",n,m);
        if(n==0 && m==0)break;
        v.clear();
        for(i=0;i<n;i++)
        {
            scanf("%ld",&element);
            store.num = element;
            store.mod = element % m;
            v.push_back(store);
        }
        sort(v.begin(),v.end(),comp);
        for(i=0;i<n;i++)
            cout<<v[i].num<<endl;
    }

    return 0;
}
