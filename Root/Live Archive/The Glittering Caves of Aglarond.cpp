#include "stdio.h"
#include "string.h"
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

#define clr(a) (a.clear())
#define sz(a) ((int)a.size())

#define REP(i, n) for(i=0;i<(int)n;i++)
#define REP1(i, a, b) for(i=a;i<=(int)b;i++)
#define REP2(i, a, b) for(i=a;i>=(int)b;i--)



#define SZ 1010

struct data{
    int ase, nai;
};

bool comp(data p, data q){
    return p.nai > q.nai;
}

data arr[1010];

int main(){
//    freopen("1.txt","r",stdin);

    int i, j, k, n, m, test, minim;
    char s[1010];

    scanf("%d",&test);

    while(test--){
        scanf("%d %d %d",&n,&m,&k);

        REP1(i, 1, n){
            arr[i].ase = arr[i].nai = 0;
            scanf("%s",s+1);
            REP1(j, 1, m){
                if(s[j] == '*') arr[i].ase++;
                else arr[i].nai++;
            }
        }

        sort(arr+1, arr+n+1, comp);

        REP1(i, 1, n){
            if(k == 0) break;
            if(arr[i].nai >= arr[i].ase){
                k--;
                swap(arr[i].ase, arr[i].nai);
            }
        }

        minim = 1e9;
        int indx = 0;

//        printf("k = %d\n",k);

        if(k%2 == 1){
            REP1(i, 1, n){
                if(abs(arr[i].ase - arr[i].nai) <= minim){
                    minim = abs(arr[i].ase - arr[i].nai);
                    indx = i;
                }
            }



            swap(arr[indx].ase, arr[indx].nai);
        }

        minim = 0;

        REP1(i, 1, n) minim += arr[i].ase;

        printf("%d\n",minim);
    }



    return 0;
}
