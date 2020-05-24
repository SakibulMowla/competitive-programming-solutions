#include <bits/stdc++.h>

using namespace  std;

void RD(int &x){scanf("%d",&x);}
void PR(int x) {printf("%d\n",x);}

#define pb push_back
#define sz(a) a.size()
#define clr(a) (a.clear())
#define mem(a,b) memset(a, b, sizeof(a))
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)


#define SZ  20010
#define SZ1 25

int mat[SZ1][SZ1];
vector <int> adj[SZ];


int main() {
    int i, j, k, n, m, p, q, mask, ans;
    bool flag;

    while(scanf("%d %d",&n,&m) == 2){
        mem(mat, 0);
        REP1(i, 1, n)
            clr(adj[i]);

        REP1(i, 1, m){
            RD(k);
            while(k--){
                RD(j);
                adj[j].pb(i);
            }
        }

        REP1(i, 1, n){
            k = sz(adj[i]);
            REP1(p, 0, k-2)
                REP1(q, p+1, k-1)
                    mat[ adj[i][p] ][ adj[i][q] ] = mat[ adj[i][q] ][ adj[i][p] ] = 1;
        }

        ans = 0;
        REP1(mask, 0, (1<<m)-1){
            flag = true;

            REP1(i, 0, m-1) if(mask&(1<<i)) {
                REP1(j, i+1, m-1) if(mask&(1<<j)) {
                    if(mat[i+1][j+1]){
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }

            if(flag)
                ans = max(ans, __builtin_popcount(mask));
        }

        PR(ans);
    }

    return 0;
}


