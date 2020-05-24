#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 32767+3
#define SD(a) scanf("%d",&a)

bool arr[SZ];
vector <int> prime;

void sieve()
{
    int i,j;
    for(j=3;j<sqrt(SZ);j+=2)
        if(arr[j] == 0)
            for(i=j*j;i<SZ;i+=j+j)
                arr[i] = 1;
    prime.push_back(2);
    for(j=3;j<SZ;j++)
        if(arr[j] == 0)
            prime.push_back(j);
}

void factorize(int n)
{
    int i,k;
    vector <int> answer;
    for(i=0;n!=1&&prime[i]<=n && i<prime.size();i++)
    {
        if(n % prime[i] == 0)
        {
            k = 0;
            while(n % prime[i] == 0)
            {
                k++;
                n /= prime[i];
            }
            answer.push_back(k);
            answer.push_back(prime[i]);
        }
    }
    if(n != 1)
    {
        answer.push_back(1);
        answer.push_back(n);
    }
    if(answer.size())printf("%d",answer[ answer.size() - 1 ]);
    for(i=answer.size()-2;i>=0;i--) printf(" %d",answer[i]);
    printf("\n");
}

int main()
{
    sieve();
//    freopen("1.txt","r",stdin);
    char str[1111] , *ptr;
    int p,k,n;
    while(scanf(" %[^\n]",str) == 1)
    {
        if(strcmp(str,"0") == 0) break;
        n = 1;
        ptr = strtok(str," ");
        while(ptr != NULL)
        {
            p = atoi(ptr);
            ptr = strtok(NULL," ");
            k = atoi(ptr);
            n *= pow(p,k);
            ptr = strtok(NULL," ");
        }
        n--;
        factorize(n);
    }

    return 0;
}
