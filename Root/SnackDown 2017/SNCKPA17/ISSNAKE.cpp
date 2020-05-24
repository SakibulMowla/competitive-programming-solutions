//
//  main.cpp
//  ISSNAKE
//
//  Created by Rumman Mahmud on 5/28/17.
//  Copyright © 2017 Rumman Mahmud. All rights reserved.
//

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name))
#define EPS 1e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define sf scanf
#define pf printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define inf 0x3f3f3f3f
#define mp make_pair
#define mt make_tuple
#define get(a,b) get<b>(a)
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

ll BigModML(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=MulModL(R,B,M); } P/=2; B=MulModL(B,B,M); } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

int EQ(long double x) {
    if(fabs(x)<EPS) return 0;
    else if(x>0) return 1;
    else return -1;
}

const int MAX = 509;
char mat[4][MAX];
bool col[4][MAX];
int nod[4][MAX];

int deg[4*MAX];
int n;
int id;

void init()
{
    clrall(col,0);
    clrall(nod,0);
    id=0;
    clrall(deg,0);
}

int mark[4*MAX];

void dfs(int a,int b,int m)
{
    //    deb("dfs:",a,b);
    if(col[a][b]) return ;
    col[a][b]=true;
    int x,y,u,v;
    if(nod[a][b]==0) nod[a][b]=++id;
    u=nod[a][b];
    mark[u]=m;
    for(int i=0;i<4;i++)
    {
        x=a+dx[i];
        y=b+dy[i];
        if((x>=0&&x<2) && (y>=0&&y<n) && mat[x][y]=='#')
        {
            //            deb("con:",x,y);
            if(nod[x][y]==0) nod[x][y]=++id;
            if(!col[x][y]) dfs(x,y,m+1);
            v=nod[x][y];
            deg[u]++;
            deg[v]++;
        }
    }
    return ;
}

string str[2];
string s[2];

void bt(int x,int y)
{
    if(x==0)
    {
        if(y+1<n && s[1][y]=='#' && s[1][y+1]=='#')
        {
            s[1][y]='.';
            s[1][y+1]='.';
            s[x][y]='.';
            bt(1,y+1);
        }
        else if(y+1<n && s[0][y+1]=='#' && s[1][y+1]=='#')
        {
            s[0][y+1]='.';
            s[1][y+1]='.';
            s[x][y]='.';
            bt(1,y+1);
        }
        else if(y+1<n && s[0][y+1]=='#')
        {
            s[0][y+1]='.';
            s[x][y]='.';
            bt(0,y+1);
        }
        else if(s[1][y]=='#')
        {
            s[1][y]='.';
            s[x][y]='.';
            bt(1,y);
        }
    }
    else
    {
        if(y+1<n && s[0][y]=='#' && s[0][y+1]=='#')
        {
            s[0][y]='.';
            s[0][y+1]='.';
            s[x][y]='.';
            bt(0,y+1);
        }
        else if(y+1<n && s[1][y+1]=='#' && s[0][y+1]=='#')
        {
            s[1][y+1]='.';
            s[0][y+1]='.';
            s[x][y]='.';
            bt(0,y+1);
        }
        else if(y+1<n && s[1][y+1]=='#')
        {
            s[1][y+1]='.';
            s[x][y]='.';
            bt(1,y+1);
        }
        else if(s[0][y]=='#')
        {
            s[0][y]='.';
            s[x][y]='.';
            bt(0,y);
        }
    }
    return ;
}

bool solve()
{
    s[0]=str[0];
    s[1]=str[1];
    int x=-1,y=-1;
    for(int i=0;i<n;i++)
    {
        if(s[0][i]=='#')
        {
            x=0,y=i;
            break;
        }
    }
    if(x!=-1)
    {
        s[x][y]='.';
        bt(x,y);
        for(int i=0;i<n;i++)
        {
            if(s[0][i]=='#'||s[1][i]=='#') return false;
        }
        return true;
    }
    return false;
}

bool go()
{
    if(solve()) return true;
    swap(str[0],str[1]);
    if(solve()) return true;
    reverse(all(str[0]));
    reverse(all(str[0]));
    if(solve()) return true;
    swap(str[0],str[1]);
    if(solve()) return true;
    return false;
}

int main()
{
#ifdef MAHDI
    //    Read;
    //    Write;
#endif // MAHDI
    int t;
    sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        init();
        for(int i=0;i<2;i++) sf("%s",mat[i]);
        int f=1;
        int cnt=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]=='#' && !col[i][j])
                {
                    if(cnt)
                    {
                        f=0;
                        break;
                    }
                    dfs(i,j,1);
                    cnt=1;
                }
            }
        }
        if(f)
        {
            str[0]=mat[0];
            str[1]=mat[1];
            f=go();
        }
        if(f) puts("yes");
        else puts("no");
    }
    return 0;
}

/**
 6
 2
 ##
 ..
 2
 ##
 .#
 2
 #.
 .#
 7
 #.###..
 #######
 6
 ##.#..
 .###..
 5
 ##.##
 .#.#.
 */
