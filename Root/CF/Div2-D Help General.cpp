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

int main() {
    int i, j, k, n, m, ans;

    while(scanf("%d%d",&n,&m) == 2){
        if(n==1||m==1){
            printf("%d\n",max(n,m));
            continue;
        }

        ans = 0;

        if(n==2||m==2){
            if(m!=2) k = m;
            else k=n;

            for(i=0;i<k;i++){
                if(i%4<=1)
                    ans += 2;
            }
            printf("%d\n",ans);
            continue;
        }

        for(i=1;i<=n;i++){
            if(m%2 == 0)
                ans += m/2;
            else if(i%2==1)
                ans += ((m/2)+1);
            else
                ans += m/2;
        }

        PR(ans);
    }


    return 0;
}
















