#include <stdio.h>
#include <string.h>
#include <math.h>

char arr[6][20] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
    int n,div , range , start;
    while(scanf("%d",&n) == 1)
    {
        div = 1 , range = 5 , start = 1;
        while(start + range <= n)
        {
            start = start + range;
            range = range + range;
            div = div + div;
        }
        printf("%s\n",arr[ (n - start) / div ]);
    }

    return 0;
}
