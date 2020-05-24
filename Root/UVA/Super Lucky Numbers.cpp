#include <stdio.h>
#include <string.h>
#include <string>

using namespace  std;

#define mem(a,b) memset(a, b, sizeof(a))
#define sz(a) (int)a.size()
#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define REV(i,n) for (i=n;i>=0;i--)


string cut_leading_zero(string a)
{
    string s;
    int i, k;
    k = sz(a);
    if(a[0]!='0') return a;
    REP(i,k-1) if(a[i]!='0') break;
    FOR(i,i,k) s+=a[i];
    return s;
}

string Addition(string &a,string &b)
{
    int carry=0, i, k, sum;
    string ans;

    if(sz(a)>sz(b)) b=string(sz(a)-sz(b),'0')+b;
    if(sz(b)>sz(a)) a=string(sz(b)-sz(a),'0')+a;
    ans.resize(sz(a));
    k = sz(a);
    REV(i,k-1)
    {
        sum=carry+a[i]+b[i]-96;
        ans[i]=(char)(sum%10+'0');
        carry=sum/10;
    }
    if(carry) ans.insert(0,string(1,carry+'0'));
//    ans=cut_leading_zero(ans);
    return ans;
}

string dp[105][130];
int N, B;

string solve(int indx, int pre){
    if(indx == N) return "1";
    string &ret = dp[indx][pre];
    if(ret != "-1") return ret;

    int i, strt;
    string tmp;
    strt = indx ? 0 : 1;
    ret = "0";

    for(i=strt;i<B;i++){
        if(i==3 && pre==1) continue;
        tmp = solve(indx+1, i);
        ret = Addition(ret, tmp);
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int i, j;

    while(scanf("%d %d",&B,&N) == 2 && (N||B)){
        for(i=0;i<=N;i++)
            for(j=0;j<=B;j++)
                dp[i][j] = "-1";

        printf("%s\n",solve(0, 0).c_str());
    }


    return 0;
}










