#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1e9;
const ll mod = 1LL;

#define SZ 100010

int dp[1010];
int N;

int solve(int n){
    if(n == N) return 0;
    int &ret = dp[n];
    if(ret != -1) return ret;

    int i, tmp=1;
    ret = inf;

    for(i=1;n+(i*n)<=N;i++){
        tmp++;
        ret = min(ret, tmp+solve(n+(i*n)));
    }

    return ret;
}

class EmoticonsDiv2 {
public:
	int printSmiles(int smiles) {
        mem(dp, -1);
        N = smiles;
        return solve(1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	EmoticonsDiv2 *obj;
	int answer;
	obj = new EmoticonsDiv2();
	clock_t startTime = clock();
	answer = obj->printSmiles(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;

	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 6;
	p1 = 5;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 11;
	p1 = 11;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 16;
	p1 = 8;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 1000;
	p1 = 21;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// You are very happy because you advanced to the next round of a very important programming contest.
// You want your best friend to know how happy you are.
// Therefore, you are going to send him a lot of smile emoticons.
// You are given an int smiles: the exact number of emoticons you want to send.
//
// You have already typed one emoticon into the chat.
// Then, you realized that typing is slow.
// Instead, you will produce the remaining emoticons using copy and paste.
//
// You can only do two different operations:
//
// Copy all the emoticons you currently have into the clipboard.
// Paste all emoticons from the clipboard.
//
// Each operation takes precisely one second.
// Copying replaces the old content of the clipboard.
// Pasting does not empty the clipboard.
// Note that you are not allowed to copy just a part of the emoticons you already have.
//
// Return the smallest number of seconds in which you can turn the one initial emoticon into smiles emoticons.
//
// DEFINITION
// Class:EmoticonsDiv2
// Method:printSmiles
// Parameters:int
// Returns:int
// Method signature:int printSmiles(int smiles)
//
//
// CONSTRAINTS
// -smiles will be between 2 and 1000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 2
//
// Returns: 2
//
// First use copy, then use paste. The first operation copies one emoticon into the clipboard, the second operation pastes it into the message, so now you have two emoticons and you are done.
//
// 1)
// 6
//
// Returns: 5
//
//
// Copy. This puts one emoticon into the clipboard.
// Paste. You now have 2 emoticons in the message.
// Copy. The clipboard now contains 2 emoticons.
// Paste. You now have 4 emoticons in the message.
// Paste. You now have 6 emoticons in the message and you are done.
//
//
// 2)
// 11
//
// Returns: 11
//
//
//
// 3)
// 16
//
// Returns: 8
//
//
//
// 4)
// 1000
//
// Returns: 21
//
//
//
// END KAWIGIEDIT TESTING




//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!