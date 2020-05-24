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

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define pb(a) push_back(a)
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 1010

deque <int> mdq;

int main(){
//    freopen("1.txt","r",stdin);
    string s;
    int test=0, t, n, m, val;

    RD(t);

    while(t--){
        scanf("%d %d",&n,&m);

        while(!mdq.empty()) mdq.pop_back();
        printf("Case %d:\n",++test);

        while(m--){
            RD(s);
            if(s == "pushLeft"){
                RD(val);
                if(sz(mdq) == n) printf("The queue is full\n");
                else mdq.push_front(val), printf("Pushed in left: %d\n",val);
            }
            else if(s == "pushRight"){
                RD(val);
                if(sz(mdq) == n) printf("The queue is full\n");
                else mdq.push_back(val), printf("Pushed in right: %d\n",val);
            }
            else if(s == "popLeft"){
                if(!sz(mdq)) printf("The queue is empty\n");
                else printf("Popped from left: %d\n",mdq.front()), mdq.pop_front();
            }
            else if(s == "popRight"){
                if(!sz(mdq)) printf("The queue is empty\n");
                else printf("Popped from right: %d\n",mdq.back()), mdq.pop_back();
            }
        }
    }


    return 0;
}

















