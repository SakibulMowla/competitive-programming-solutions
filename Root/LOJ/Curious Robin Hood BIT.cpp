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
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ 100010

int tree[SZ];
int arr[SZ];
int n;

void update(int indx, int val){
    while(indx <= n){
        tree[indx] += val;
        indx += (indx & -indx);
    }
}


int sum(int indx){
    int ret = 0;
    while(indx > 0){
        ret += tree[indx];
        indx -= (indx & -indx);
    }
    return ret;
}


int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, m, i, j, k;

    RD(t);

    while(t--){
        RD(n, m);
        memset(tree, 0, sizeof(int)*(n+2));

        REP1(i, 1, n){
            RD(arr[i]);
            update(i, arr[i]);
        }

        printf("Case %d:\n",++test);

        while(m--){
            RD(k);
            if(k == 1){
                RD(i);
                i++;
                PR(arr[i]);
                update(i, -arr[i]);
                arr[i] = 0;
            }
            else if(k == 2){
                RD(i, j);
                i++;
                update(i, j);
                arr[i] += j;
            }
            else if(k == 3){
                RD(i, j);
                i++, j++;
                PR(sum(j)-sum(i-1));
            }
        }
    }


    return 0;
}













