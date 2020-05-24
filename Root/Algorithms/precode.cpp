#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>


#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):-(x))
#define ll long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)


#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)


#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n)  while(scanf("%d",&n)!=-1)
using namespace std;


void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(ll &x,ll &y,ll &z){scanf("%I64d%I64d%I64d",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}


void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(u32 x) {printf("%u\n",x);}
void PR(double x) {printf("%.3lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}


const ll inf=((ll)1)<<60;
const double dinf=1e50;
const int INF=1000000000;
const int N=1005;



int n,m;
int a1,b1,c1,a2,b2,c2;

class Matrix
{
public:
    ll a[6][6];

    void init(int x)
    {
        if(x==0)
        {
            clr(a,0);
        }
        else if(x==1)
        {
            clr(a,0);
            int i;
            FOR0(i,6) a[i][i]=1;
        }
        else
        {
            clr(a,0);
            a[1][0]=a[2][1]=a[4][3]=a[5][4]=1;

            a[1][2]=b1;
            a[2][2]=a1;
            a[3][2]=c1;

            a[0][5]=c2;
            a[4][5]=b2;
            a[5][5]=a2;
        }


    }
    Matrix operator*(Matrix p)
        {
            Matrix ans;
            ans.init(0);
            int i,j,k;
            FOR0(k,6) FOR0(i,6) FOR0(j,6)
            {
                ans.a[i][j]+=a[i][k]*p.a[k][j]%m;
                ans.a[i][j]%=m;
            }
            return ans;
        }

        Matrix Pow(int n)
        {
            Matrix ans,p=*this;
            ans.init(1);
            while(n)
            {
                if(n&1) ans=ans*p;
                p=p*p;
                n>>=1;
            }
            return ans;
        }


        void print()
        {
            int i,j;
            FOR0(i,6)
            {
                FOR0(j,6) printf("%lld ",a[i][j]);
                puts("");
            }
        }
};

Matrix a;
int f0,f1,f2;
int g0,g1,g2;



void deal(int n)
{
    if(n==0)
    {
        PR(f0%m,g0%m);
    }
    else if(n==1)
    {
        PR(f1%m,g1%m);
    }
    else if(n==2)
    {
        PR(f2%m,g2%m);
    }
    else
    {
        a.init(2);
       // a.print();
        a=a.Pow(n-2);
     //   a.print();
        ll x=f0*a.a[0][2]+f1*a.a[1][2]+f2*a.a[2][2]+g0*a.a[3][2]+g1*a.a[4][2]+g2*a.a[5][2];
        ll y=f0*a.a[0][5]+f1*a.a[1][5]+f2*a.a[2][5]+g0*a.a[3][5]+g1*a.a[4][5]+g2*a.a[5][5];
        printf("%lld %lld\n",x%m,y%m);
    }

}

int main()
{
    int num=0;
    rush()
    {
        RD(a1,b1,c1);


        RD(a2,b2,c2);

        RD(f0,f1,f2);
        RD(g0,g1,g2);
        RD(m);



        RD(n);
        printf("Case %d:\n",++num);
        while(n--)
        {
            int x;
            RD(x);
            deal(x);
        }
    }
}
