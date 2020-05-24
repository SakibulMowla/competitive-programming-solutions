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
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)

#define SZ 42

int arr[SZ][SZ];
int dp[SZ][SZ][SZ][SZ];

int main() {
//    freopen("1.txt", "r", stdin);
    int n, m, q, i, j, k, a, b, tmp;
    char ch;
    {
        RD(n);
        RD(m);
        RD(q);

        REP1(i, 1, n) REP1(j, 1, m){
            scanf(" %c",&ch);
            arr[i][j] = !(ch-'0');
        }

        REP1(i, 1, n) REP1(j, 1, m){
            if(arr[i][j])
                arr[i][j] += arr[i][j-1];
        }

        REP1(i, 1, n) REP1(j, 1, m) REP1(a, i, n) REP1(b, j, m){
            dp[i][j][a][b] += dp[i][j][a-1][b];
            dp[i][j][a][b] += dp[i][j][a][b-1];
            dp[i][j][a][b] -= dp[i][j][a-1][b-1];

            tmp = b-j+1;

            REP2(k, a, i){
                tmp = min(tmp, arr[k][b]);
                dp[i][j][a][b] += tmp;
            }
        }

        while(q--){
            RD(i, j);
            RD(a, b);
            PR(dp[i][j][a][b]);
        }
    }


    return 0;
}















