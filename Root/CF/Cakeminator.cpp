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

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

//%I64d
int main()
{
    ll n, i, j, k, r, c;

    char arr[20][20];
    int ara[20][20];

    while(cin >> r >> c)
    {
        for(i=0;i<r;i++)
            scanf("%s",arr[i]);
        memset(ara,0,sizeof(ara));
        for(i=0;i<r;i++)
        {
            for(j=0,k=0;j<c;j++)
            {
                if(arr[i][j] == 'S')
                {
                    k = 1;
                    break;
                }
            }
            if(!k){
                for(j=0;j<c;j++)
                    ara[i][j] = 1;}
        }

        for(i=0;i<c;i++)
        {
            for(j=0,k=0;j<r;j++)
            {
                if(arr[j][i] == 'S')
                {
                    k = 1;
                    break;
                }
            }
            if(!k){
                for(j=0;j<r;j++)
                    ara[j][i] = 1;}
        }
        k = 0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(ara[i][j] == 1)
                    k++;

        cout << k << "\n";
    }

    return 0;
}
