#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int f,i,n,m,k,c,w,arr[500010];

    while(cin >> n)
    {
        if(n==0) break;

        m=log2(n);

        if(pow(2,m)==n)
        {
            cout << n << endl;
        }
        else
        {
            n=(n-pow(2,m))*2;
            cout << n << endl;
        }
    }

    return 0;
}
