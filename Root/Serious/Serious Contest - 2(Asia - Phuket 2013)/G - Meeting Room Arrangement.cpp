#include <bits/stdc++.h>

using namespace std;

int dp[100];

int rec(int cur,vector<pair<int,int> >&v)
{
	//if(cur==v.size()) return 0;

	int &ret =dp[cur];
	if(ret!=-1) return ret;

	ret = 0;

	for(int i = 0 ; i<v.size() ; i++)
	{
		if(v[i].first>=cur)
		{
			ret= max(ret , rec(v[i].second , v)+1);
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int tcase,cas=1;

	scanf(" %d",&tcase);

	while(tcase--)
	{
		vector<pair<int,int> >v;
		memset(dp , -1,sizeof dp);
		int x,y;
		while(cin>>x>>y)
		{
			if(x==0 && y==0) break;
			v.push_back(make_pair(x,y));
		}

		sort(v.begin() , v.end());


		int sol = 0;
		// for(int i = 0 ; i<v.size() ; i++)
		// 	cout<<v[i].first<<" -- "<<v[i].second<<endl;

		for(int mask= 0 ; mask<(1<<10) ; mask++)
		{
			//if(mask!=2) continue;
			int now = 0;
			for(int i = 0 ; i<10 ; i++)
			{
				if(mask&(1<<i))
				{
					int tmpnow = -1;
					for(int j = 0; j<v.size() ; j++)
					{
						if(v[j].first==i && v[j].first>=now)
						{
							tmpnow = v[j].second;
							break;
						}
					}
					if(tmpnow==-1)
					{
						now = -1;
						break;
					}
					else now = tmpnow;
				}

				//cout<<i<<" lsdf "<<now<<endl;
			}
			if(now!=-1) sol = max(sol , __builtin_popcount(mask));
		}
		sol = rec(0 , v);
		printf("%d\n", cas++ , sol);
	}
	return 0;
}
