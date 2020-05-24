#include <stdio.h> #include <stdlib.h> #include <string.h> #include <cmath> #include <vector> #include <string> #include <iostream> #include <stack>

using namespace std;

#define ll long long #define pb push_back #define mp make_pair #define SZ(a) (int)a.size() #define dd double #define maxx 15100 #define paii pair<int,int> #define mp make_pair #define fr first #define sc second

int main() { int tcase,cas=1;

scanf(" %d",&tcase); while(tcase--) { int n; scanf(" %d",&n); int f = 1; int v1 = 0,v2 = 0; int mul =1; int tmp = n; while(n) { int dig = n%10; // cout<<dig<<endl; if(dig>=1) { if(dig==1) v2 = mul*(dig); else v2 = mul*(dig-1); break; } mul *= 10; n/=10; } v1 = tmp-v2; // cout<<v1<<" "<<v2<<endl; if(v1>0 && v2>0) cout<<"YES"<<endl; else cout<<"N0"<<endl; } }
