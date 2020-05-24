#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "string"
#include "vector"
#include "set"
#include "stack"
#include "queue"
#include "iostream"
#include "algorithm"
#include "assert.h"
#include "map"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MP(a, b) make_pair(a, b)
#define clr(a) (a.clear())
#define sz(a) ((int)a.size())

#define REP(i, n) for(i=0;i<(int)n;i++)
#define REP1(i, a, b) for(i=a;i<=(int)b;i++)
#define REP2(i, a, b) for(i=a;i>=(int)b;i--)


#define SZ 1010

int arr1[5], arr2[5];

map <int, int> mp1, mp2;

bool ok(){
    int ft, fo, st, so;

    if(arr1[1] == arr1[0]){
        ft = arr1[0];
        fo = arr1[2];
    }
    else{
        ft = arr1[2];
        fo = arr1[0];
    }

    if(arr2[0] == arr2[1]){
        st = arr2[0];
        so = arr2[2];
    }
    else{
        st = arr2[2];
        so = arr2[0];
    }

    if(st > ft) return true;
    else if(st == ft && so > fo) return true;

    return false;
}

int main(){
//    freopen("1.txt","r",stdin);

    int i, j, k, n, m, flag;

    while(scanf("%d %d %d",&arr1[0],&arr1[1],&arr1[2]) == 3){
        if(arr1[0] == 0 && arr1[1] == 0 && arr1[2] == 0) break;

        flag = 0;
        mp1.clear();
        mp1[ arr1[0] ] = 1;
        mp1[ arr1[1] ] = 1;
        mp1[ arr1[2] ] = 1;

        sort(arr1, arr1+3);

        if(sz(mp1) == 1){
            if(arr1[0] == 13) printf("*\n");
            else printf("%d %d %d\n",arr1[0]+1,arr1[0]+1,arr1[0]+1);
            continue;
        }
        else if(sz(mp1) == 3){
            printf("1 1 2\n");
            continue;
        }

        REP1(i, 1, 13) {
            REP1(j, i, i) {
                REP1(k, 1, 13) {
                    if(k == j) continue;
                    mp2.clear();
                    mp2[i] = mp2[j] = mp2[k] = 1;
                    arr2[0] = i;
                    arr2[1] = j;
                    arr2[2] = k;
                    sort(arr2, arr2+3);

                    if(sz(mp2) == 2 && ok()){
                        printf("%d %d %d\n",arr2[0],arr2[1],arr2[2]);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            if(flag == 1) break;
        }

        if(flag == 0)
            printf("1 1 1\n");
    }




    return 0;
}

