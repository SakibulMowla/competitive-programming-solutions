//
//  main.cpp
//  SAMESNAK
//
//  Created by Rumman Mahmud on 5/22/17.
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
#define clrall(name,val) memset(name,(val),sizeof(name));
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
#define Read freopen("input00.txt","r",stdin)
#define Write freopen("output1.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false),cin.tie(0),cout.tie(0)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6,T7 e7){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<" "<<e7<<"\n";}


struct PT
{
    ll x,y;
    PT(){}
    PT(ll x,ll y):x(x),y(y){}
    void input()
    {
        sf("%lld %lld",&x,&y);
    }
    void output()
    {
        pf("%lld %lld\n",x,y);
    }
    bool operator < (const PT &p)  const
    {
        if(y==p.y) return x<p.x;
        return y<p.y;
    }
    bool operator == (const PT &p)  const
    {
        return mp(x,y)==mp(p.x,p.y);
    }
    bool operator != (const PT &p)  const
    {
        return mp(x,y)!=mp(p.x,p.y);
    }
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
};

bool go(PT a,PT b,PT c,PT d)
{
    if(a.x==b.x && c.x==d.x && a.x==c.x)
    {
        ll df=min(b.y,d.y)-max(a.y,c.y);
        if(df>=0) return true;
    }
    else if(a.y==b.y && c.y==d.y && a.y==c.y)
    {
        ll df=min(b.x,d.x)-max(a.x,c.x);
        if(df>=0) return true;
    }
    return false;
}

bool gogo(PT a,PT b,PT c,PT d)
{
    return (a==c||a==d||b==c||b==d);
}

bool solve(PT a,PT b,PT c,PT d)
{
    if(mp(a.x,a.y)>mp(b.x,b.y)) swap(a,b);
    if(mp(c.x,c.y)>mp(d.x,d.y)) swap(c,d);
    return (go(a, b, c, d)||gogo(a, b, c, d));
}

int main()
{
    //Read;
    //Write;
    int t;
    PT a,b,c,d;
    sf("%d",&t);
    while (t--) {
        a.input();
        b.input();
        c.input();
        d.input();
        if(solve(a, b, c, d)) pf("yes\n");
        else pf("no\n");
    }
    return 0;
}














