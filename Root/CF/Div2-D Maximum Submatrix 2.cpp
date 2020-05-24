//#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <stdlib.h>
//#include <math.h>
//#include <map>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <set>
//#include <iostream>
//#include <algorithm>
//#include <deque>

#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)


inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }

#define SZ 5010

int mat[SZ][SZ];
char arr[SZ];
int grid[SZ][SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
    #endif // defined


    int i, j, k, n, m, cnt, ans, p, q;

    while(scanf("%d %d",&n,&m) == 2){
        REP1(i, 1, n){
            scanf("%s",arr+1);
            REP1(j, 1, m) mat[i][j] = (arr[j] - '0');

            for(j=1;j<=m;j++){
                if(mat[i][j] == 0) continue;

                k = j;
                while(k+1<=m && mat[i][k+1]==1) k++;

                grid[j][j]++;
                grid[j][k+1]--;

                j = k;
            }
        }

        REP1(i, 1, m)
            REP1(j, i, m)
                grid[i][j] += grid[i][j-1];
        REP1(i, 1, m)
            REP1(j, i, m)
                grid[i][j] += grid[i-1][j];
        ans = 0;

        REP1(i, 1, m) REP1(j, i, m) {
            ans = FastMax(ans, (grid[i][j]*(j-i+1)));
        }

        PR(ans);
    }


    return 0;
}
















