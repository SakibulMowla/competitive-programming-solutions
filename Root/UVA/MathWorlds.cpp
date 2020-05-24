#include <bits/stdc++.h>
using namespace  std;

int main()
{
    ll n;
    double x,y,z,d;
    char ch;

    while(cin >>x>>y>>z)
    {
        n = 0;
        d = x + y;
        if(d == z)
        {
            n++;
            ch = '+';
        }
        d = x - y;
        if(d == z)
        {
            n++;
            ch = '-';
        }
        d = x * y;
        if(d == z)
        {
            n++;
            ch = '*';
        }
        d = x / y;
        if(d == z)
        {
            n++;
            ch = '/';
        }
        if(n == 1)
            printf("%c\n",ch);
        else
            printf("Invalid\n");
    }


    return 0;
}
