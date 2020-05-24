#include <bits/stdc++.h>
using namespace std;

#define INF_MAX 	2147483647
#define INF_MIN 	-2147483648
#define INF 		(1 << 30)
#define SORT(a,n)   sort(a,a+n)
#define EPS			1e-9
#define PI 			acos(-1.0)
#define N 		    2 + 100
#define MOD			10000000007
#define sz(x) 		(int)(x).size()
#define all(x) 		(x).begin(), (x).end()
#define pb 			push_back
#define mp			make_pair
#define ms(x, a) 	memset((x), (a), sizeof(x))
#define ff           first
#define ss           second
#define rep(i,a,b)  for(int i=(a); i<(b); i++)
#define repC(i,x) 	for(size_t i=0; i<x.size(); i++)
#define repIT(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define nn          '\n'
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define i64 __int64
#define isValid(x, y) ( x >= 0 And x < row And y >= 0 And y < col )
#define dump cin.ignore()


typedef long long 		LL;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<string> 	vs;
typedef vector<char>	vc;
typedef vector<bool>    vb;
typedef vector< pii >   vii;
typedef map<string,int> msi;
typedef map<int,int>	mii;
typedef map<char,int>   mci;
typedef map<int,string>	mis;

template<class T> T Abs(T x) {return x>0 ? x : -x;}
template<class T> T Max(T a, T b) {return a>b ? a : b;}
template<class T> T Min(T a, T b) {return a<b ? a : b;}
template<class T> T gcd(T a, T b) {return (b ? gcd(b,a%b) : a);}
template< class T > T sq(T x){ return x * x;}
template< class T > T lcm(T a, T b){ return (a / gcd<T>(a, b) * b); }
template< class T > T deb(T cmd) {cout << "debugger:" << endl; cout << cmd << endl;}
template< class T > T deb(T cmd1, T cmd2) {cout << "debugger:" << endl; cout << cmd1 << "\t" << cmd2 << endl;}
template< class T > T deb(T cmd1, T cmd2, T cmd3) {cout << "debugger:" << endl; cout << cmd1 << "\t" << cmd2 << "\t" << cmd3 << endl;}
template< class T > T deb(T cmd1, T cmd2, T cmd3, T cmd4) {cout << "debugger:" << endl; cout << cmd1 << "\t" << cmd2 << "\t" << cmd3 <<"\t" << cmd4 << endl;}
bool isVowel(char ch){ch=tolower(ch);return(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');}

//int dx[4] = {-1, 0, 0, 1};
//int dy[4] = {0, -1, 1, 0};
//int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
//int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

#define MAX 1000

char num1[MAX+5], num2[MAX+5];
int sum[MAX+5];
int len1, len2;

void revAndAdd()
{
    int num, factoring, val, rough, n, ans;

    int big_len, min_len, last, start;
    start = last = 0;

    ms(sum, 0);

    if(len1 > len2)
    {
        big_len = len1;
        rep(i, len2, len1)
            num2[i] = '0';
    }

    else if( len2 > len1 )
    {
        big_len = len2;
        rep(i, len1, len2)
            num1[i] = '0';
    }

    else big_len = len1;

    rep(i, 0, big_len)
    {
        sum[i] += (num1[i]-'0') + (num2[i]-'0');

        if(sum[i]>9)
        {
            sum[i] = sum[i]%10;
            sum[i+1]++;
            last = i+1;
        }
    }

    big_len = Max(big_len - 1, last);

    rep(i, 0, big_len+1)
    {
        if(sum[i] > 0)
        {
            start = i;
            break;
        }
    }

    rep(i, start, big_len+1)
        cout << sum[i];

    puts("");
}

int main()
{
    freopen("1.txt", "w", stdout);
    int t = 10;
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        int n = rand()%10;
        n++;
        cout << endl << n << endl;
        for (int j = 0; j < n; j++) {
            cout << (rand()%450) + 1 << endl;
        }
    }
}

/*
SampleInput
3
24 1
4358 754
305 794
SampleOutput
34
1998
1
*/
