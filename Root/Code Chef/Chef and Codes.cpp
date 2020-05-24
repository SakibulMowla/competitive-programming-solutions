#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 1010

struct data{
    int n;
    char ch;
};

data arr[30];

bool comp(data p, data q){
    if(p.n == q.n) return p.ch < q.ch;
    return p.n < q.n;
}

int main() {
    string seq, s;
    int t, i, k;
    int pos[300];
    char ch;

    scanf("%d",&t);

    while(t--){
        cin >> seq;
        getchar();
        getline(cin, s);

        k = sz(s);

        REP(i, 26)
            arr[i].ch = i + 'a', arr[i].n = 0;

        REP(i, k){
            ch = tolower(s[i]);
            if(isalpha(ch))
                arr[ ch-'a' ].n++;
        }

        sort(arr, arr+26, comp);

        REP(i, 26)
            pos[ arr[i].ch ] = i;

        REP(i, k){
            if(isalpha(s[i]))
                printf("%c", (s[i]>='a' && s[i]<='z') ? (char)seq[pos[tolower(s[i])]] : (char)(seq[pos[tolower(s[i])]]+'A'-'a') );
            else
                printf("%c",s[i]);
        }

        puts("");
    }


    return 0;
}
















