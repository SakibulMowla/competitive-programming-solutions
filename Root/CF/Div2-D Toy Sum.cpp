#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


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
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 1000010

bool used[SZ];
set <int> ms;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, n, x, y, p, q;


    while(scanf("%d",&n) == 1) {
        clr(ms);
        mem(used, 0);

        for(i = 0; i < n; i++) {
            scanf("%d",&j);
            ms.insert(j);
            used[j] = 1;
        }

        j = 1;
        printf("%d\n",n);

        for(set<int>::iterator it = ms.begin(); it !=ms.end(); it++) {
            x = (*it);
            y = 1000000 - x + 1;
            if(ms.find(y) == ms.end()) {
                printf("%d ",y);
                used[y] = 1;
            }
            else {
                for( ; j <= 1000000; j++) {
                    p = j;
                    q = 1000000-j+1;
                    if(used[p] == 0 && used[q] == 0) {
                        used[p] = used[q] = 1;
                        printf("%d %d ",p,q);
                        j++;
                        break;
                    }
                }
                ms.erase(ms.find(y));
            }
        }
        printf("\n");
    }

    return 0;
}










