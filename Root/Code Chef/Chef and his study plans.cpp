#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>
using namespace std;
#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif
/************ for topcoder by zz1215 *******************/
#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)
#define FFF(i,a)        for( int i = 0 ; i < (a) ; i ++)
#define FFD(i,a,b)      for( int i = (a) ; i >= (b) ; i --)
#define S64(a)          scanf(in64,&a)
#define SS(a)           scanf("%d",&a)
#define LL(a)           ((a)<<1)
#define RR(a)           (((a)<<1)+1)
#define pb              push_back
#define CL(Q)           while(!Q.empty())Q.pop()
#define MM(name,what)   memset(name,what,sizeof(name))
#define MAX(a,b)        ((a)>(b)?(a):(b))
#define MIN(a,b)        ((a)<(b)?(a):(b))
#define read            freopen("out.txt","r",stdin)
#define write           freopen("zz.txt","w",stdout)

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-9;
const double pi = acos(-1.0);
const int maxn = 4000001;
const int maxc = 21;

struct zz
{
	int x;
	int y;
	bool operator < (const zz & cmp) const
	{
		if(x!=cmp.x)
		{
			return x<cmp.x;
		}
		else
		{
			return y>cmp.y;
		}
	}
}zx;

map<int,int>mp;
vector<zz>vx;
vector<zz>v;
vector<int>cx;
vector<int>c;
int x[maxn];
int y[maxn];
int f[maxc][maxn];
int n,m;

int go(int l,int r)
{
	int ans=0;
	for(int i=0;i<maxc;i++)
	{
		if(f[i][l]>r)
		{
			return i-1;
		}
	}
}

int find(int l,int r)
{
	int ans=0;
	int temp;
	while(true)
	{
		temp = go(l,r);
		if(temp==-1)
		{
			return ans;
		}
		else
		{
			ans+=1<<temp;
			l=f[temp][l];
		}
	}
}

int main()
{
	while(cin>>n>>m)
	{
		v.clear();
		vx.clear();
		mp.clear();
		c.clear();
		cx.clear();
		for(int i=1;i<=n;i++)
		{
			SS(zx.x);
			SS(zx.y);
			zx.y++;
			vx.pb(zx);
		}
		sort(vx.begin(),vx.end());
		for(int i=0;i<vx.size();i++)
		{
			while(!v.empty())
			{
				if(vx[i].y<=v.back().y)
				{
					v.pop_back();
				}
				else
				{
					break;
				}
			}
			v.pb(vx[i]);
		}
		for(int i=0;i<v.size();i++)
		{
			cx.pb(v[i].x);
			cx.pb(v[i].y);
		}
		for(int i=1;i<=m;i++)
		{
			SS(x[i]);
			SS(y[i]);
			y[i]++;
			cx.pb(x[i]);
			cx.pb(y[i]);
		}
		sort(cx.begin(),cx.end());
		int temp=cx[0];
		c.pb(temp);
		for(int i=1;i<cx.size();i++)
		{
			if(cx[i]!=temp)
			{
				temp = cx[i];
				c.pb(temp);
			}
		}
		for(int i=0;i<c.size();i++)
		{
			mp[c[i]]=i+1;
		}
		for(int i=0;i<v.size();i++)
		{
			v[i].x=mp[v[i].x];
			v[i].y=mp[v[i].y];
		}
		for(int i=1;i<=m;i++)
		{
			x[i]=mp[x[i]];
			y[i]=mp[y[i]];
		}
		for(int i=0;i<maxn;i++)
		{
			f[0][i]=inf;
		}

		for(int i=0;i<v.size();i++)
		{
			f[0][v[i].x]=v[i].y;
		}
		temp = inf;
		for(int i=maxn-1;i>=0;i--)
		{
			temp=f[0][i]=min(f[0][i],temp);
		}
		for(int i=1;i<maxc;i++)
		{
			for(int j=0;j<maxn;j++)
			{
				if(f[i-1][j]!=inf)
				{
					f[i][j]=f[i-1][f[i-1][j]];
				}
				else
				{
					f[i][j]=inf;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			printf("%d\n",find(x[i],y[i]));
		}
	}
	return 0;
}

