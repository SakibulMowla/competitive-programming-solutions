// prime numbers are not smith numbers as they have no divisors
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 100010

int arr[SZ] ;
vector <int> prime;

void sieve()
{
    int i,j;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);

    return;
}

int sod(char *a)
{
    int i,len,sum=0;
    len = strlen(a);
    for(i=0;i<len;i++)
        sum += a[i] - '0';
    return sum;
}

int check(int a)
{
    int sum1,sum2,i,func,an=a;
    char arr[100];
    sprintf(arr,"%d",a);
    sum1 = sod(arr);
    sum2 = 0;
    for(i=0;prime[i]<a && i<prime.size() && a!=1;i++)
    {
        if(a%prime[i] == 0)
        {
            while(a%prime[i] == 0)
            {
                a/=prime[i];
                sprintf(arr,"%d",prime[i]);
                sum2 += sod(arr);
            }
        }
    }
    if(a!=1)
    {
        sprintf(arr,"%d",a);
        sum2 += sod(arr);
    }
    if(an == a)return 0;
    if(sum1 == sum2) return sum1;
    return 0;
}

int main()
{
    sieve();
    int test,i,j,k;
    char arr[100];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&k);
        for(i=k+1;;i++)
        {
            if(check(i) != 0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

    return 0;
}
