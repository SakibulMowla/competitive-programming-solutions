#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

#define SZ 1010

using namespace std;

vector <int> prime_factor[SZ];
queue <int> q;
bool arr[SZ] , color[SZ];
int prime[SZ] , dist[SZ];

void sieve_factor()
{
    int i,j,k,n,m;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime[0] = 2;
    k=1;
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime[k++] = i;
    for(i=1;i<SZ;i++)
    {
        n = i;
        for(j=0;prime[j]*prime[j]<=i && n!=1;j++)
        {
            if(n%prime[j] == 0)
                prime_factor[i].push_back(prime[j]);
            while(n%prime[j] == 0)
                n /= prime[j];
        }
        if(n!=1 && n!=i)
            prime_factor[i].push_back(n);
    }

    return;
}

int BFS(int s,int t)   // s = start  &&  t = target
{
    int a,u,i;
    q.push(s);
    color[s] = 1;
    dist[s] = 0;

    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        for(i=0;i<prime_factor[u].size();i++)
        {
            a = u + prime_factor[u][i];
            if(a<=t && color[a] == 0)
            {
                color[a] = 1;
                q.push(a);
                dist[a] = dist[u] + 1;
                if(a == t)
                    return dist[a];
            }
        }
    }

    return dist[t];
}

int main()
{
    sieve_factor();
    int ans,test,tt,s,t;
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
        while( !q.empty() ) q.pop();
        memset(color , 0 ,sizeof(color));
        memset(dist, -1 ,sizeof(dist));
        scanf("%d %d",&s,&t);
        ans = BFS(s,t);
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}
