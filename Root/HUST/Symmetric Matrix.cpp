#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;


ll matrix[110][110];
ll N;

bool symmetry()
{
    ll i, j;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            if(matrix[i][j] != matrix[N-i-1][N-j-1])
                return false;
    }

    return true;
}


int main()
{
    ll i, j, k, t, test = 0;

    scanf("%lld",&t);

    while(t--)
    {
        scanf(" %*c %*c %lld",&N);
//        printf("N = %lld\n",N);

        bool f = 1;

        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
            {
                scanf("%lld",&matrix[i][j]);
                if(matrix[i][j] < 0)
                    f = 0;
            }

        if(f == 1)
            f = symmetry();

        if(f == 0)
            printf("Test #%lld: Non-symmetric.\n",++test);
        else
            printf("Test #%lld: Symmetric.\n",++test);
    }

    return 0;
}

