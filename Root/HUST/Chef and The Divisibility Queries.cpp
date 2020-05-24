#include <bits/stdc++.h>
using namespace  std;

#define sz(x) (int)x.size()
typedef long long ll;
#define SZ 100010

bool col[SZ];
vector <int> mult[SZ];

void sieve()
{
    int i, j, k;
    col[0] = col[1] = 1;
    for(i=4; i<SZ; i+=2)
        col[i] = 1;
    k = sqrt(SZ);
    for(i=3; i<k; i+=2)
        if(!col[i])
            for(j=i*i; j<SZ; j+=i+i)
                col[j] = 1;
}

int b_search(int st,int end,int k,int upto)
{
    if(st > end) return 0;
    int mid =(st + end) / 2;
    if(mult[k][mid] > upto)
        return b_search(st, mid-1, k, upto);
    if(mid+1 < sz(mult[k]) && mult[k][mid+1] <= upto)
        return b_search(mid+1, end, k, upto);
    return mid+1;
}

int main()
{
    sieve();
    int n, m, i, j, k, l;
    vector<int>::iterator low,up;

    scanf("%d %d",&n,&m);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&j);
        if(!col[j])
        {
            mult[1].push_back(i);
            mult[j].push_back(i);
            continue;
        }
        for(k=1; k*k<j; k++)
        {
            if(j % k == 0)
            {
                mult[k].push_back(i);
                mult[j/k].push_back(i);
            }
        }
        if(k*k == j)
            mult[k].push_back(i);
    }

    for(l=0;l<m;l++)
    {
        scanf("%d %d %d",&i,&j,&k);
//        printf("%d\n", b_search(0,sz(mult[k])-1, k, j) - b_search(0,sz(mult[k])-1, k, i-1) );
        up = upper_bound(mult[k].begin(), mult[k].end(), j);
        low = lower_bound(mult[k].begin(), mult[k].end(), i);
        k = (up-mult[k].begin()) - (low-mult[k].begin());
//        printf("up low %d %d\n",(int)(low-mult[k].begin()),(int)(up-mult[k].begin()));
        printf("%d\n",k);
    }

    return 0;
}
