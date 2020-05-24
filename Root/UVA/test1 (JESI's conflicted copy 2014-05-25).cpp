#include "stdio.h"
#include "iostream"
#include "string.h"
#include "math.h"
#include "stdlib.h"

using namespace std;

int main()
{
    freopen("1.txt", "w", stdout);
    int n, m, test=100;

    while(test--){
        n = rand() % 11;
        if(!n) n++;
        m = rand() % (n+1);
        if(!m) m++;
        printf("%d %d\n",n,m);
    }

    return 0;
}


