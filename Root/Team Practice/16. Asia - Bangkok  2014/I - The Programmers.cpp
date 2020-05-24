#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define pb push_back
#define clean(a,b) memset(a,b,sizeof(a))
#define oo 1<<20
#define dd double
#define ll long long
#define ull unsigned long long
#define ff float
#define fr first
#define sc second
#define MAXX 110
#define PRIME_N 1000000
#define INFI 1<<20
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define MODD 1000000007
#define padd pair<dd , dd >
#define mp make_pair

//int rx[] = {0,-1,0,1,1,-1,-1,0,1}; //four diviewtion x
//int ry[] = {0,1,1,1,0,0,-1,-1,-1   //four diviewtion y
//int rep[] = {1,1,4,4,2,1,1,4,4,2}; //repet cycle for mod
//void ullpr(){printf("range unsigned long long : %llu\n",-1U);} //for ull
//void ulpr(){printf("range unsigned long : %lu\n",-1U);} //for ull
//void upr(){printf("range unsigned : %u\n",-1U);} //for ull

const ll mod = 1000000007LL;


namespace matching
{
	typedef int val_t;
	const int SIZE= 3000;

	int v1,v2;

	std::vector<int> graph[SIZE];

	int mx[SIZE],my[SIZE];
	int dist[SIZE];
	int total_matching;
	int inf_dist;

	bool bfs(){
		int x,y;
		queue<int>q;
		for (int x = 0; x < v1; ++x)
		{
			if(mx[x]==-1){
				dist[x] = 0;
				q.push(x);
			}
			else
				dist[x] = -1;
		}
		bool flg = false;
		while(!q.empty()){
			x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size() ; ++i)
			{
				y = graph[x][i];
				if(my[y]==-1){
					inf_dist = dist[x] +1;
					flg = true;
				}
				else if(dist[my[y]]==-1){
					dist[my[y]] = dist[x]+1;
					q.push(my[y]);
				}
			}
		}
		return flg;
	}

	bool dfs(int x){
		if(x==-1) return true;
		for (int i = 0; i < graph[x].size() ; ++i){
			/* code */
			int y= graph[x][i];
			int tmp = (my[y]==-1) ? inf_dist : dist[my[y]];
			if(tmp==dist[x]+1 && dfs(my[y])){
				mx[x] = y;
				my[y] = x;
				return true;
			}
		}
		dist[x] = -1;
		return false;
	}

	int hofcroft(){
		memset(mx, -1, sizeof(mx));
		memset(my , -1 ,sizeof(my));

		total_matching = 0;
		while(bfs())
		{
			for (int i = 0; i < v1; ++i)
			{
				/* code */
				if(mx[i]==-1 && dfs(i))
				{
					total_matching++;
				}
			}
		}
		return total_matching;
	}
}

int main()
{
	int tcase,cas=1;

	scanf(" %d",&tcase);

	while(tcase--)
	{
		int p,s,n,c,m;

		scanf(" %d %d %d %d",&p,&s,&c,&m);


		for(int i = 0 ; i<p ; i++)
			matching::graph[i].clear();

		matching::v1 = p;
		matching::v2 = c*s;

		for(int i = 0 ; i<m ; i++)
		{
			int u,v;
			scanf(" %d %d",&u,&v);
			for(int j = 0 ; j<c ; j++)
			{
				matching::graph[u-1].push_back(((v-1)*c)+j);
			}
		}

		printf("%d\n",matching::hofcroft() );
	}
	return 0;
}
