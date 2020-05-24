#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "string"
#include "vector"
#include "set"
#include "queue"
#include "map"
#include "deque"
#include "iostream"
#include "assert.h"
#include "bitset"
#include "algorithm"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define sz(a) (int)a.size()
#define clr(a) a.clear()
#define MP(a, b) make_pair(a, b)

#define SZ 100000+10

int arr[100][100];
int coin[100];

int main()
{
        #ifdef PGD_LAB
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    int tcase,cas=1;

    int val;

    scanf(" %d",&tcase);

    while(tcase--)
    {
        int n,m;

        scanf(" %d %d" , &n , &m);

        for(int i =1 ; i<=n ; i++)
        {
            scanf(" %d" , &arr[i][0]);

            for(int j = 1 ; j<= arr[i][0]+1 ; j++)
            {
                scanf(" %d" , &arr[i][j]);
            }
        }

        for(int i = 1 ; i<=m ;i++)
        {
            scanf(" %d",&coin[i]);
        }

        ll tot = 0;

        for(int i = 1 ; i<=n ; i++)
        {
            int mn = -1;

            for(int j = 1 ; j<=arr[i][0] ; j++)
            {
                if(mn==-1 || mn>coin[arr[i][j]]) mn = coin[arr[i][j]];
            }

            tot += (arr[i][arr[i][0]+1]*mn);
//            cout<<" i "<<i<<" m "<<mn<<endl;
        }

        printf("%lld\n",tot);
    }
}
