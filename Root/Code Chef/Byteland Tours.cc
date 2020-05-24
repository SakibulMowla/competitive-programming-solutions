#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define pb push_back


#define SZ 55

struct data{
    int x, y;
};

data point[SZ];
char arr[SZ][SZ];
char mat[SZ][SZ];

vector <int> v[SZ*SZ];
vector <int> vxup, vxdo;

int dpxup[SZ];
int dpxdo[SZ];
int N, lft, rht;

int solve_x_up(int u){
    int &ret = dpxup[u];
    if(ret != -1) return ret;

    int i;
    ret = 0;

    REP(i, N)
        if(mat[u][i] == 'Y' && (point[i].x >= point[u].x)){
            ret = max(ret, solve_x_up(i));
        }

    return ret+1;
}

void path_x_up(int u){
    vxup.pb(u);

    int i;

    REP(i, N)
        if(mat[u][i] == 'Y' && i!=lft && (point[i].x >= point[u].x) && dpxup[i]+1 == dpxup[u]){
            mat[u][i] = '*', mat[i][u] = '*', path_x_up(i);
            break;
        }

    return;
}

int solve_x_do(int u){
    int &ret = dpxdo[u];
    if(ret != -1) return ret;

    int i;
    ret = 0;

    REP(i, N)
        if(mat[u][i] == 'Y' && i!=rht && (point[i].x <= point[u].x))
            ret = max(ret, solve_x_do(i));

    return ret+1;
}

void path_x_do(int u){
    int i;

    REP(i, N)
        if(mat[u][i] == 'Y' && (point[i].x <= point[u].x) && dpxdo[i]+1 == dpxdo[u]){
            mat[u][i] = '*', mat[i][u] = '*', path_x_do(i);
            break;
        }

    vxdo.pb(u);
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, i, j, k, l, cnt;

    scanf("%d",&n);
    N = n;

    REP(i, n) scanf("%d %d",&point[i].x, &point[i].y);

    REP(i, n) scanf("%s",arr[i]), strcpy(mat[i], arr[i]);

    cnt = 0;
    REP(i, n) REP(j, n) if(mat[i][j] == 'Y') {
        memset(dpxup, -1, sizeof(int)*(n+2));
        memset(dpxdo, -1, sizeof(int)*(n+2));

        if(point[i].x >= point[j].x){
            lft = j, rht = i;
            solve_x_up(i);
            path_x_up(i);
            mat[i][j] = mat[j][i] = '*';
            solve_x_do(j);
            path_x_do(j);
        }
        else{
            lft = i, rht = j;
            solve_x_up(j);
            path_x_up(j);
            mat[i][j] = mat[j][i] = '*';
            solve_x_do(i);
            path_x_do(i);
        }

        k = sz(vxdo);
        REP(l, k) v[cnt].pb(vxdo[l]);
        k = sz(vxup);
        REP(l, k) v[cnt].pb(vxup[l]);
        cnt++;

        clr(vxup);
        clr(vxdo);
    }

    HELL:;
    printf("%d\n",cnt);
    REP(i, cnt){
        k = sz(v[i]);
        printf("%d", k-1);
        REP(j, k) printf(" %d",v[i][j]);
        puts("");
    }

    return 0;
}


/*
3
1 2
1 3
2 4
NYN
YNY
NYN
*/










