#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
char line[200],*word;
long long W[20] ,C ,n;

long long calculate()
{
    long long i,sum;
    sum = 0;
    for(i=0;i<strlen(word);i++)
    {
        sum = (sum << 5) + word[i] - 'a' +1;
    }
    return sum;
}

int hash()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if((C/W[i])%n == (C/W[j])%n)
            {
                C = min( (C/W[i] + 1) * W[i] , (C/W[j] + 1) * W[j] );
                return 0;
            }
    return 1;
}

int main()
{
    while(scanf(" %[^\n]",line) == 1)
    {
        printf("%s\n",line);
        n = 0;
        word = strtok(line," ");
        while(word != NULL)
        {
            W[n++] = calculate();
            word = strtok(NULL," ");
        }
        C = *min_element(W,W+n);
        while( !hash() );
        printf("%lld\n\n",C);
    }

    return 0;
}
