#include "bits/stdc++.h"
using namespace std;

#define MP(a, b) make_pair(a, b)
#define sz(a) (int)a.size()
#define X first
#define Y second

typedef pair <int , int> pii;
typedef vector <pii> vp;
typedef vector <vp> vpp;

bool comp(pii a,pii b)
{
    if(a.X == b.X)
        return a.Y < b.Y;
    return a.X < b.X;
}

vp num, tmp;
vpp ans;

vector <int> snkha;

bool chk[310][310];

int main()
{
    int i, j, k, l, n, m;

    while(scanf("%d %d",&n,&m) == 2)
    {
        if(!n and !m) break;

        num.clear();
        num.push_back(MP(n, m));

        while(scanf("%d %d",&n,&m) == 2)
        {
            if(!n and !m) break;
            num.push_back(MP(n, m));
        }

        sort(num.begin(), num.end(), comp);

        k = sz(num);
        ans.clear();

        for(i=0; i<k; i++)
            for(j=0; j<k; j++)
                chk[i][j] = 0;

        for(i=0; i<k; i++)
        {
            for(j=i+1; j<k; j++)
            {
                if(chk[i][j]) continue;

                tmp.clear();
                tmp.push_back(num[i]);
                tmp.push_back(num[j]);

                snkha.clear();
                snkha.push_back(i);
                snkha.push_back(j);

                for(l=j+1; l<k; l++)
                {
                    n = ( num[l].X - num[i].X ) * ( num[i].Y - num[j].Y );
                    m = ( num[l].Y - num[i].Y ) * ( num[i].X - num[j].X );

                    if(n == m)
                    {
                        tmp.push_back(num[l]);
                        snkha.push_back(l);
                    }
                }
                if(sz(tmp) > 2)
                {
                    ans.push_back(tmp);

                    l = sz(snkha);

                    for(n=0; n<l; n++)
                        for(m=n+1; m<l; m++)
                            chk[snkha[n]][snkha[m]] = chk[snkha[m]][snkha[n]] = 1;
                }
            }
        }


        if(!sz(ans))
        {
            printf("No lines were found\n");
            continue;
        }

        printf("The following lines were found:\n");
        k = sz(ans);

        for(i=0; i<k; i++)
        {
            l = sz(ans[i]);
            for(j=0; j<l; j++)
            {
                printf("(%4d,%4d)",ans[i][j].X, ans[i][j].Y);
            }
            printf("\n");
        }
    }

    return 0;
}
