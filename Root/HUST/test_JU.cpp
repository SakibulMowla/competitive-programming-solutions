#include<iostream>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<functional>
#include<istream>
#include<iterator>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>


using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b-1);i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define PCC pair<char,char>
#define PIC pair<int,char>
#define PCI pair<char,int>
#define FST first
#define SEC second
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)
#define RADIANS(x) (((1.0 * x * PI) / 180.0))
#define DEGREES(x) (((x * 180.0) / (1.0 * pi)))
#define SINE(x) (sin(RADIANS(x)))
#define COSINE(x) (cos(RADIANS(x)))
#define SETBIT(x, i) (x |= (1 << i))
#define TANGENT(x) (tan(RADIANS(x)))
#define ARCSINE(x) (DEGREES((asin(x))))
#define RESETBIT(x, i) (x &= (~(1 << i)))
#define ARCCOSINE(x) (DEGREES((acos(x))))
#define ARCTANGENT(x) (DEGREES((atan(x))))
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define IN scanf
#define OUT printf
#define SI(a) scanf("%d",&a)
#define SL(a) scanf("%lld",&a)
#define SD(a) scanf("%lf",&a)
#define OI(a) printf("%d",a)
#define OL(a) printf("%lld",a)
#define OD(a) printf("%lf",a)
#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 1000000
#define FASTIO ios_base::sync_with_stdio(0);cin.tie();
#define LIM 4

//TYPE conversion
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline LL toLong(T a)
{
    LL res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  SQ(T a)
{
    return a*a;
}
template<typename T>inline T GCD(T a, T b)
{
    if (b == 0)return a;
    else return GCD(b, a % b);
}
template<typename T>inline T LCM(T a, T b)
{
    LL res=a*b;
    res/=GCD(a,b);
    return res;
}
template<typename T>inline ULL BIGMOD(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return SQ(BIGMOD(a, b / 2, m)) % m;
    else return (a % m*BIGMOD(a, b - 1, m)) % m;
}
template<typename T>inline VS PARSE(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.PB(s);
    return res;
}
template<typename T>inline ULL  DIST(T A,T B)
{
    ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T POWER(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool IS_ON(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int OFF(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int ON(T mask,T pos)
{
    return mask|(1<<pos);
}
//MOVEMENT INSIDE GRID
template<typename T>inline bool INSIDE_GRID(int R,int C,int ro,int clm)
{
    if(R>=0&&C>=0&&R<ro&&C<clm)return 1;
    return 0;
}
#define ll long long
int arr[70];

ll dp[70][70][2];
string str;
int len;
string zerostr;
void tobin(ll x)
{
    str=zerostr;

    int j=62;
    while(x!=0)
    {
        if(x%2==1)
        {
            str[j]='1';
        }
        x/=2;
        j--;
    }
//    cout<<"dasf";
//    cout<<str<<endl;
}

ll solve(int pos , int baki , int flag)
{
//    cout<<len<<endl;

    if(pos==len)
    {

        if(baki==0)return 1;

        else return 0;
    }

    if(dp[pos][baki][flag]!=-1)return dp[pos][baki][flag];
    ll &res=dp[pos][baki][flag]=0;
    if(flag==1)
    {
        if(baki>=1)
        res+=solve(pos+1,baki-1,flag);
        res+=solve(pos+1,baki,flag);
    }

    else
    {
        int l,h;
        l=0;
        h=str[pos]-'0';

        for(int i=l;i<=h;i++)
        {
            if(i==1)
            {
                res+=solve(pos+1,baki-1,flag);
            }
            else
            {
                int nf=flag;
                if(i<h)nf=1;
                res+=solve(pos+1,baki,nf);
            }
        }
    }
    return res;
}

int main()
{
freopen("input.txt","r",stdin);
    freopen("outputJU.txt","w",stdout);

    int n,i,j;

    zerostr="";


    for(i=0;i<63;i++)
    {
        zerostr=zerostr+"0";
    }
//tobin(12);
    for(i=63;i>=1;i--)
    {
        int cnt=0;
        n=i;
        while(n!=1)
        {
            int x=__builtin_popcount(n);
            cnt++;
            n=x;
        }

        arr[i]=cnt;
    }

   // for(i=1;i<=32;i++)cout<<i<<" "<<arr[i]<<endl;

    ll xx,yy,des;
    while(cin>>xx>>yy>>des)
    {
        if(xx==0 && yy==0 && des==0)return 0;

        if(xx>yy)swap(xx,yy);
        if(des==0)
        {
            if(xx==1LL)
            {
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }

        else
        {
            tobin(yy);
        len=str.length();
        //cout<<len<<" *** "<<endl;
        ll now=0;
        for(i=1;i<=63;i++)
        {
            SET(dp,-1);
            if(arr[i]==des-1)
                now=now+solve(0,i,0);

        }

       // cout<<now<<endl;
//

        ll then=0;
        tobin(xx-1);

        for(i=1;i<=63;i++)
        {
            SET(dp,-1);
            if(arr[i]==des-1)
                now=now-solve(0,i,0);

        }
        if(xx==1 && des==1)now--;
        cout<<now<<endl;
        }
    }


    return 0;
}
