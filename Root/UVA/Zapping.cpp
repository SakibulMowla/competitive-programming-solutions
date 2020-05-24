#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
int main()
{
    int n,m,c;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==-1 && m==-1)
            break;
        c=abs(n-m);
        if(c>50)
            c=(100-c);
        printf("%d\n",c);
    }

    return 0;
}
