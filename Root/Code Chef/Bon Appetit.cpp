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
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define SZ 100010

struct data{
    int st, nd;
    data(){}
    data(int a, int b){
        st=a, nd=b;
    }
};

vector <data> entry[SZ];
map <int , int> mp;

bool comp(data a, data b){
    if(a.nd == b.nd) return a.st > b.st;
    return a.nd < b.nd;
}

int main() {
    int t, n, i, j, k, p, cnt, last, q;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&k);

        REP(i, n){
            clr(entry[i]);
        }
        clr(mp);
        cnt = 0;

        REP(i, n){
            scanf("%d %d %d",&j,&k,&p);
            if(mp.find(p) == mp.end()) mp[p] = cnt++;
            entry[ mp[p] ].pb( data(j, k-1) );
        }

        k = 0;

        REP(i, cnt){
            sort(entry[i].begin(), entry[i].end(), comp);
            j = sz(entry[i]);
            last = -1;
            REP(q, j){
                if(entry[i][q].st > last){
                    k++;
                    last = entry[i][q].nd;
                }
            }
        }

        printf("%d\n",k);
    }

    return 0;
}













