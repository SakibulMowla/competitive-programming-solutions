#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
    freopen("1.txt","w",stdout);
    int i, j, k, n, m, t;

    t = 10;

    while(t--){
        n = rand()%100;
        n++;
        printf("\n%d\n",n);
        for(i=0;i<n;i++)
            printf("%d\n",rand());
    }
    printf("0\n");

    return 0;
}


