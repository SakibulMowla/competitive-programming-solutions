#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define INF 1<<28
#define SIZE 1000

#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define FOR(i,p,k) for (i=p; i<k;i++)

#define bug(x) cout<< "->" <<#x<<": "<<x<<endl //debug(x) variable
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define COPY(c,r) memcpy(c,r,sizeof(r))
#define SZ(x) (int)x.size()
#define PB push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b) __gcd(a,b)
#define fs first
#define sc second

//structure model
struct pq
{
    int cost,node;
    bool operator<(const pq &b)const
    {
        return cost>b.cost; // Min Priority Queue
    }
};

//Comp Sort
bool comp(pq a,pq b)
{
    return a.cost > b.cost;
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<double>vd;
typedef vector<string> vs;
typedef vector<vi>vvi;
typedef map<string,int> msi;
typedef map<int,int>mii;
typedef map<pii,int>mpi;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

string Addition(string a,string b); //Addition any two string
string Multiplication(string a,string b); //Multiplication between a and b
string Multiplication(string a,int k); //Multiplication between a and int k
string Subtraction(string a,string b); // Subtraction from a to b(a always >=b)
string Division(string a,string b); //Division return a/b
string Division(string a,int k); //Division return a/k
string Div_mod(string a,string b); //Modulus of Division a%b
int Div_mod(string a,int k); //Modulus of Division a%k
string cut_leading_zero(string a); //leading zero cut 001 -> 1
int compare(string a,string b); //(1 means a>b) (-1 means a<b) (0 means a=b)
string Pow(string s, int a); //Calculate Power s^a
string _gcd(string a,string b); //Calculate gcd between a and b
string _lcm(string a,string b); //Calculate lcd between a and b

int main()
{

    string s1,s2,mod;

    int test,Case=1;

    scanf("%d",&test);
    while(test--)
    {
        cin>>s1>>s2;

        if(s1[0]=='-')
            s1.erase(0,1);
        if(s2[0]=='-')
            s2.erase(0,1);
        mod=Div_mod(s1,s2);
        if(mod=="0")
            printf("Case %d: divisible\n",Case++);
        else
            printf("Case %d: not divisible\n",Case++);
    }


    return 0;
}
string _lcm(string a,string b)
{
    return Division(Multiplication(a,b),_gcd(a,b));
}
string _gcd(string a,string b)
{
    return (b=="0")?a:_gcd(b,Div_mod(a,b));
}

string Pow(string B,int P)
{
    string R="1";
    while(P>0)
    {
        if(P%2==1)
            R=Multiplication(R,B);
        P/=2;
        B=Multiplication(B,B);
    }
    return R;
}

string Multiplication(string a,string b)
{
    int i,j,multi,carry;
    string ans,temp;

    ans="0";
    REV(j,SZ(b)-1)
    {
        temp="";
        carry=0;
        REV(i,SZ(a)-1)
        {
            multi=(a[i]-'0')*(b[j]-'0')+carry;
            temp+=(multi%10+'0');
            carry=multi/10;
        }
        if(carry) temp+=(carry+'0');
        Reverse(temp);
        temp+=string(SZ(b)-j-1,'0');
        ans=Addition(ans,temp);
    }
    ans=cut_leading_zero(ans);
    return ans;
}
string Multiplication(string a,int k)
{
    string ans;
    int i,sum,carry=0;

    REV(i,SZ(a)-1)
    {
        sum=(a[i]-'0')*k+carry;
        carry=sum/10;
        ans+=(sum%10)+'0';
    }
    while(carry)
    {
        ans+=(carry%10)+'0';
        carry/=10;
    }
    Reverse(ans);
    ans=cut_leading_zero(ans);
    return ans;
}

string Addition(string a,string b)
{
    int carry=0,i;
    string ans;

    if(SZ(a)>SZ(b)) b=string(SZ(a)-SZ(b),'0')+b;
    if(SZ(b)>SZ(a)) a=string(SZ(b)-SZ(a),'0')+a;
    ans.resize(SZ(a));
    REV(i,SZ(a)-1)
    {
        int sum=carry+a[i]+b[i]-96;
        ans[i]=(char)(sum%10+'0');
        carry=sum/10;
    }
    if(carry) ans.insert(0,string(1,carry+'0'));
    ans=cut_leading_zero(ans);
    return ans;
}

string Subtraction(string a,string b)
{
    int borrow=0,i,sub;
    string ans;
    if(SZ(b)<SZ(a)) b=string(SZ(a)-SZ(b),'0')+b;
    REV(i,SZ(a)-1)
    {
        sub=a[i]-b[i]-borrow;
        if(sub<0)
        {
            sub+=10;
            borrow=1;
        }
        else borrow=0;
        ans+=sub+'0';
    }
    Reverse(ans);
    ans=cut_leading_zero(ans);
    return ans;
}

string Division(string a,string b)
{
    string mod,temp,ans="0";
    int i,j;

    REP(i,SZ(a))
    {
        mod+=a[i];
        mod=cut_leading_zero(mod);
        FOR(j,0,10)
        {
            temp=Multiplication(b,j);
            if(compare(temp,mod)==1)
                break;
        }
        temp=Multiplication(b,j-1);
        mod=Subtraction(mod,temp);
        ans+=(j-1)+'0';
    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return ans;
}

string Division(string a,int k)
{
    int i,sum=0;
    string ans="0";

    REP(i,SZ(a))
    {
        sum=(sum*10+(a[i]-'0'));
        ans+=(sum/k)+'0';
        sum=sum%k;
    }
    ans=cut_leading_zero(ans);
    return ans;
}

string Div_mod(string a,string b)
{
    string mod,temp,ans="0";
    int i,j;

    REP(i,SZ(a))
    {
        mod+=a[i];
        mod=cut_leading_zero(mod);
        FOR(j,0,10)
        {
            temp=Multiplication(b,j);
            if(compare(temp,mod)==1)
                break;
        }
        temp=Multiplication(b,j-1);
        mod=Subtraction(mod,temp);
        ans+=(j-1)+'0';
    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return mod;
}

int Div_mod(string a,int k)
{
    int i,sum=0;

    REP(i,SZ(a))
    sum=(sum*10+(a[i]-'0'))%k;
    return sum;
}

int compare(string a,string b)
{
    int i;
    a=cut_leading_zero(a);
    b=cut_leading_zero(b);
    if(SZ(a)>SZ(b)) return 1; //bigger
    if(SZ(a)<SZ(b)) return -1; //smaller
    REP(i,SZ(a))
    if(a[i]>b[i]) return 1; //bigger
    else if(a[i]<b[i]) return -1; //smaller
    return 0; //equal
}

string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0') return a;
    REP(i,SZ(a)-1) if(a[i]!='0') break;
    FOR(i,i,SZ(a)) s+=a[i];
    return s;
}
/*
Tested By UVa problems
495 Fibonacci Freeze
500! Big Factorial
424 Integer Inquiry
10106 Product
10929 You can say 11
Tested By Google Code Jam
Code jam'10 Qual Round B Problem
*/

