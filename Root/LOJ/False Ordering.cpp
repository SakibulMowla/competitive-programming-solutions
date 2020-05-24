#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define SZ 1010

int arr[SZ];

vector <int> prime;
void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=4;i<SZ;i+=2)
        arr[i] = 1;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int nod(int n)
{
    int i,j,k,num,mul=1;

    for(i=0;prime[i]<=n && n!=1;i++)
    {
        if(n%prime[i] == 0)
        {
            k = 1;
            while(n%prime[i] == 0)
            {
                n /= prime[i];
                k++;
            }
            mul *= k;
        }
    }
    return mul;
}

struct data
{
    int num , div;
};

data pre[SZ];

bool comp(data p,data q)
{
    if(p.div == q.div)
        return p.num > q.num;
    return p.div < q.div;
}

int main()
{
    sieve();
    int i,j,k,t=0;
    for(i=0;i<1000;i++)
    {
        pre[i].num = i+1;
        pre[i].div = nod(i+1);
//        printf("%d %d\n",i+1,pre[i].div);
    }
    sort(pre,pre+1000,comp);
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&j);
        printf("Case %d: %d\n",++t,pre[j-1].num);
    }

    return 0;
}
