#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 610
const ll inf = 1LL<<28;
const ll mod = 1LL;

int r, c;
char arr[SZ][SZ];

int col[SZ];
map <int , int> M;

void sieve()
{
    int i, j, k;

    for(i=4; i<510; i+=2)
        col[i] = 1;

    col[0] = col[1] = 1;

    for(i=3; i<510; i+=2)
        if(arr[i])
            for(j=i*i; j<510; j+=i+i)
                col[j] = 1;

    k = 0;

    for(i=0; i<510; i++)
    {

        if(!col[i]) ++k;
        M[i] = k;
    }
}

int lefft[SZ][SZ], riht[SZ][SZ], top[SZ][SZ], botom[SZ][SZ];

int proces()
{
    int i, j, k;

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(arr[i][j] == '^')
            {
                lefft[i][j] = 1;
                if(j != 0)
                    lefft[i][j] += lefft[i][j-1];
            }
            else
                lefft[i][j] = 0;
        }
    }

    for(i=0; i<r; i++)
    {
        for(j=c-1; j>=0; j--)
        {
            if(arr[i][j] == '^')
            {
                riht[i][j] = 1;
                if(j != c-1)
                    riht[i][j] += riht[i][j+1];
            }
            else
                riht[i][j] = 0;
        }
    }

    for(j=0; j<c; j++)
    {
        for(i=0; i<r; i++)
        {
            if(arr[i][j] == '^')
            {
                top[i][j] = 1;
                if(i != 0)
                    top[i][j] += top[i-1][j];
            }
            else
                top[i][j] = 0;
        }
    }

    for(j=0; j<c; j++)
    {
        for(i=r-1; i>=0; i--)
        {
            if(arr[i][j] == '^')
            {
                botom[i][j] = 1;
                if(i != r-1)
                botom[i][j] += botom[i+1][j];
            }
            else
                botom[i][j] = 0;
        }
    }

    k = 0;
    int ans;

    for(i=1; i<r-1; i++)
        for(j=1; j<c-1; j++)
        {
            if(arr[i][j] == '#')
                continue;
            ans = lefft[i][j-1];
            ans = min(ans, riht[i][j+1]);
            ans = min(ans, top[i-1][j]);
            ans = min(ans, botom[i+1][j]);


            k += M[ans];
        }

    return k;
}


int main()
{
    sieve();
    int n, m, i, j, k, t;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&r,&c);
        for(i=0; i<r; i++)
            scanf("%s",arr[i]);
        printf("%d\n",proces());
    }

    return 0;
}

