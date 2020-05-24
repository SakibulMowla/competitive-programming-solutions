#include <bits/stdc++.h>

#define LOCAL_TEST true
#define SZ(x) ((int)x.size())
#define clr(name,val) memset(name,(val),sizeof(name));
#define Assign(name,val) name.assign(val+1,vector<int>())
#define EPS .000000001
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo ((int)(INT_MAX))
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n) for(var=(s);var<(n);(var)++)
#define rvp(var,s,n) for(var=(n-1);var>(s-1);(var)--)
#define read_ freopen("input.txt","r",stdin)
#define write_ freopen("output.txt","w",stdout)
#define MAX 100006
using namespace std;

int compare(string a,string b){if(a==b) return 0;if(SZ(a)==SZ(b)){for(int i=0;i<SZ(a);i++){if(a[i]>b[i]) return 1;else if(a[i]<b[i]) return -1;}return -1;}if(SZ(a)>SZ(b)) return 1;return -1;}
string string_add(string b,string a){if(SZ(a)>SZ(b)) swap(a,b);a=string((SZ(b)-SZ(a)),'0')+a;int carry=0,add;string res;for(int i=SZ(a)-1; i>-1; i--){add=(int)(a[i]-'0')+(int)(b[i]-'0')+carry;carry=add/10;res+=(add%10)+'0';}if(carry) res+=carry+'0';reverse(res.begin(),res.end());return res;}
string string_mul(string a,string b){if(SZ(a)>SZ(b)) swap(a,b);string res,tres;int l=0,carry,mul;for(int i=SZ(a)-1; i>-1; i--){tres=string(l,'0');carry=0;for(int j=SZ(b)-1; j>-1; j--){mul=(int)(a[i]-'0')*(int)(b[j]-'0')+carry;carry=mul/10;tres+=(mul%10)+'0';}if(carry) tres+=carry+'0';reverse(tres.begin(),tres.end());res=string_add(tres,res);l++;}return res;}
void cut_leading_zero(string &res){int i;for(i=0;i<SZ(res);i++){if(res[i]!='0') break;}res=res.substr(i);if(!SZ(res)) res="0";return;}
ll big_mod(ll a,ll p,ll MOD){if(p==0) return 1L;ll ret=big_mod(a,p/2,MOD);ret=((ret*ret)%MOD+MOD)%MOD;if(p%2) ret=((ret*a)%MOD+MOD)%MOD;return ret;}
ll power(ll a,ll p){if(p==0) return 1L;ll ret=power(a,p/2);ret=(ret*ret);if(p%2) ret=(ret*a);return ret;}
int fastMax(int x, int y) {return (((y-x)>>(32-1))&(x^y))^y;}
int fastMin(int x, int y) {return (((y-x)>>(32-1))&(x^y))^x;}
///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

vector< vector<int> > adj;

int distime[MAX],low[MAX],id,ctt;
bool col[MAX],color[MAX];
stack<pair<int,int> > S;

void bcc(int u,int par)
{
    distime[u]=low[u]=id++;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(v==par) continue;

        if(!distime[v])
        {
            S.push(mp(u,v));
            bcc(v,u);
            low[u]=min(low[u],low[v]);
            if(distime[u]<=low[v])
            {
                int us,vs,cnt=0;
                printf("cycle:\n");
                while(!S.empty())
                {
                    us=S.top().fs;
                    vs=S.top().sc;
                    S.pop();
                    cnt++;
                    cout<<us<<" : "<<vs<<endl;
                    if(cnt==1&&u==us&&v==vs) break;
                    else if(u==us&&v==vs)
                    {
                        col[u]=col[v]=true;

                        break;
                    }
                    else
                    {
                        col[us]=col[vs]=true;
                    }
                }
//                cout<<endl;
            }
        }
        else if(distime[u]>distime[v]) low[u] = min(distime[v],low[u]);
    }
}

void dfs(int u,int par)
{
    color[u]=true;
    ctt++;
    int v;
    for(int i=0;i<SZ(adj[u]);i++)
    {
        v=adj[u][i];
        if(v==par) continue;
        if(!color[v]&&!col[v])
        {
            dfs(v,u);
        }
    }
    return ;
}

int main()
{
    int test,cas=0,n,m,u,v;
    int res;
    SF("%d",&test);
    while(test--)
    {
        id=0;
        ctt=0;
        res=0;
        SF("%d %d",&n,&m);
        Assign(adj,n+2);
        clr(distime,0);
        while(!S.empty()) S.pop();
        clr(low,0);
        clr(col,0);
        clr(color,0);

        for(int i=0;i<m;i++)
        {
            SF("%d %d",&u,&v);
            adj[u].psb(v);
            adj[v].psb(u);
        }
        for(int i=1;i<=n;i++) if(!distime[i]) bcc(i,i);
        for(int i=1;i<=n;i++)
        {
            if(!col[i]&&!color[i])
            {
                ctt=0;
                dfs(i,i);
                res+=((ctt)*(ctt-1))>>1;
            }
        }
        PF("Case #%d: %d\n",++cas,res);
    }
}
/*
2
8 10
1 2
2 3
3 4
4 7
7 5
5 6
7 8
4 1
4 2
1 8

13 13
1 2
2 4
4 3
3 10
10 9
5 8
4 5
8 9
8 7
8 6
7 6
11 12
12 13
*/
