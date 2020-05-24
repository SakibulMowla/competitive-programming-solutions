#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

bool isoperator(char ch) {
    if(ch=='+' || ch=='-' || ch=='*' ||
            ch=='/' || ch=='^') return true;
    return false;
}

int precedence(char sign) {
    if(sign=='+' || sign=='-') return 1;
    if(sign=='*' || sign=='/') return 2;
    if(sign=='^') return 3;
    return 0;
}

string in2post(string in) {
    stack<char>stk;
    char temp;
    string post;
    int i,val1,val2;
    stk.push('(');
    in+=")";
    for(i=0; i<in.size(); i++) {
        if(isalpha(in[i]) || isdigit(in[i]))
            post.push_back(in[i]);
        else if(in[i]=='(') stk.push(in[i]);
        else if(in[i]==')') {
            while(true) {
                temp=stk.top();
                stk.pop();
                if(temp=='(') break;
                post.push_back(temp);
            }
        } else if(isoperator(in[i])) {
            val1=precedence(in[i]);
            while(true) {
                temp=stk.top();
                stk.pop();
                val2=precedence(temp);
                if(val2<val1) {
                    stk.push(temp);
                    stk.push(in[i]);
                    break;
                }
                post.push_back(temp);
            }
        }
    }
    return post;
}

int val[10];
map <char, int> mp;
stack <int> stk;

int evaluate (string s) {
    while (!stk.empty()) stk.pop();

    for (int i = 0; i < sz(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            stk.push(mp[ s[i] ]);
        } else {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            if (s[i] == '+'){
                stk.push(a+b);
            }
            else if (s[i] == '-'){
                stk.push(a-b);
            }
            else if (s[i] == '*'){
                stk.push(a*b);
            }
        }
    }

    return stk.top();
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    string s, alphas;

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        cin >> target;
        if (n == 0 && target == 0) break;

        cin >> s;
        alphas = "";

        for (int i = 0; i < sz(s); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                alphas += s[i];
        }

        sort(alphas.begin(), alphas.end());
        Unique(alphas);
//        cout << alphas << '\n';

//        cout << ">> HERE\n";

        s = in2post(s);
//        cout << "s = " << s << '\n';

        bool flag = false;
        do {
//            cout << "> " << alphas << " s = " << s << '\n';
            for (int i = 0; i < n; i++) {
                mp[ alphas[i] ] = val[i];
            }
            if (evaluate(s) == target) {
                flag = true;
                break;
            }
        } while (next_permutation(alphas.begin(), alphas.end()));

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}






