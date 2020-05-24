#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

class CountryGroupHard {
public:
    string solve(vector <int> a) {
        int n = sz(a);
        vector <int> dp(n+1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                bool flag = 1;
                for (int k = j; k < i; k++) {
                    if (a[k] != 0 && a[k] != i - j) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) dp[i] += dp[j];
                if (dp[i] > 2) dp[i] = 2;
            }
        }

        if (dp[n] == 1) return "Sufficient";
        return "Insufficient";
    }
};

///Modified by me :-)

// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}


#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int aARRAY[] = {0,2,3,0,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(0, theObject.solve(a),"Sufficient");
    }
    {
        int aARRAY[] = {0,2,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(1, theObject.solve(a),"Insufficient");
    }
    {
        int aARRAY[] = {0,3,0,0,3,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(2, theObject.solve(a),"Sufficient");
    }
    {
        int aARRAY[] = {0,0,3,3,0,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(3, theObject.solve(a),"Insufficient");
    }
    {
        int aARRAY[] = {2,2,0,2,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(4, theObject.solve(a),"Sufficient");
    }
}
// END CUT HERE
