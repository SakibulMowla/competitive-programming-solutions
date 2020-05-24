#include "stdio.h"
#include "vector"
#include "string.h"
#include "iostream"
#include "algorithm"
using namespace std;
int main()
{
    int test,n,i,j,k;
    vector <int> input;
    scanf("%d",&test);
    while(test--)
    {
        k = 0;
        input.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            input.push_back(j);
        }
        sort(input.begin(),input.end());
        while(count(input.begin(),input.end(),input[ input.size()-1 ]) != n)
        {
            j = input[ input.size()-1 ] - input[ input.size()-2 ];
            if(j == 0) j = 1;
            k += j;
            for(i=0;i<input.size()-1;i++)
                input[i] += j;
            sort(input.begin(),input.end());
        }
        printf("%d\n",k);
    }

    return 0;
}
