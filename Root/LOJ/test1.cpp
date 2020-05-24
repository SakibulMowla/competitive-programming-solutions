#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ(a)       (int)a.size()
#define LL          long long
#define ULL         unsigned long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define countbit(mask) __builtin_popcount(musk)
using namespace std;
#define MAXN 12010
bool col[MAXN];
long long prime[MAXN];

int seive(LL N)
{
    long long i,j,k,l;
    col[0]=true;
    col[1]=true;
    k=0;
    prime[++k]=2;
    for(j=4;j<N;j+=2)
        col[j]=true;
    for(i=3;i<N;i+=2)
         if(!col[i])
         {
                prime[++k]=i;
                for(j=i*i;j<N;j+=2*i)
                    col[j]=true;
         }
    return 0;
}
LL m,n;
LL ans;
int factor[MAXN];
int num[MAXN];

void bt(LL a,int cur,int used)
{
    factor[a]=used;
    int i;
    for(i=cur+1;;i++)
    {
        if(a*prime[i]>10000) break;
        bt(a*prime[i],i,used+1);
    }
}


int main()
{
    seive(MAXN);
    bt(1,0,2);
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        mem(num,0);
        int n;
        cin>>n;
        int i,j;
        fr(i,1,n)
        {
            int a;
            scanf("%d",&a);
            num[a]++;
        }
        ans=0;
        fr(i,1,10000)
        if(factor[i])
        {
            LL tot=0;
            for(j=i;j<=10000;j+=i)
            if(num[j])
            {
                tot+=num[j];
            }

            tot=(tot*(tot-1)*(tot-2)*(tot-3))/24;

            if(factor[i]%2) ans-=tot;
            else ans+=tot;
        }
        printf("Case %d: ",++cas);
        print1(ans);
    }
    return 0;
}
