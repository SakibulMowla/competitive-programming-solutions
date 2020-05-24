#include "stdio.h"
#include "map"
#include "iostream"

using namespace std;

map <long long , long long> m;

long long rplc(long long n)
{
    if(!n) return n;
    if(m.find(n) != m.end()) return m[n];
    m[n] = n = max(n , rplc(n/2)+rplc(n/3)+rplc(n/4));
    return n;
}

int main()
{
    long long n;
    while(1 == scanf("%lld",&n)) printf("%lld\n",rplc(n));

    return 0;
}
