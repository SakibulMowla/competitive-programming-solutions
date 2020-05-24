#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"
#include "set"
#include "queue"
#include "map"
#include "stdlib.h"
#include "assert.h"
#include "deque"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 1e9;
const int mod = 1;

#define REP(i, n) for(i=0;i<(int)n;i++)
#define REP1(i, a, b) for(i=(int)a;i<=(int)b;i++)
#define REP2(i, a, b) for(i=(int)a;i>=(int)b;i--)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define MP(a, b) make_pair(a, b)
#define mem(a, b) memset(a, b, sizeof(a))

#define SZ 2010

int lastx, lasty, n, m;

queue <int> Q;

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};
int col[SZ][SZ];

void bfs(){
    int i, j, k, u, v;

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        v = Q.front(); Q.pop();
        REP(i, 4){
            j = u + x[i];
            k = v + y[i];
            if(j>=1 && j<=n && k>=1 && k<=m && col[j][k] == 0){
                Q.push(j);
                Q.push(k);
                col[j][k] = 1;
                lastx = j;
                lasty = k;
            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, k;

    while(scanf("%d %d",&n,&m) == 2){
        scanf("%d",&k);

        while(!Q.empty()) Q.pop();
        mem(col, 0);

        while(k--){
            scanf("%d %d",&i,&j);
            Q.push(i);
            Q.push(j);
            lastx = i;
            lasty = j;
            col[i][j] = 1;
        }


        bfs();

        printf("%d %d\n",lastx,lasty);
    }



    return 0;
}
