#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

/*ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}*/

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

//%I64d
int main()
{
    ll i,j,k,l,best,besti,bestj,cur,curi,curj,prev,previ,prevj;
    string str;
    stack <int> S;
    char ch;
    while(cin >> str)
    {
        while(!S.empty()) S.pop();
        best = besti = bestj = cur = curi = curj = prev = previ = prevj = 0;
        l = str.size();
//        stable = 0;
        for(i=0; i<l; i++)
        {
//            printf("i = %d\n",i);
            if(str[i] == '(' || str[i] == '[')
            {
                S.push(str[i]);
            }
            else
            {
//                if(i == 9) printf("iuhsdf = %c\n",S.top());
                j = i;
                cur = 0;
                curj = i - 1;
                while(j < l && (str[j] == ']' || str[j] == ')' ) )
                {
                    if(S.empty())
                    {
                        j++;
                        break;
                    }
                    ch = S.top();
                    if((ch == '(' && str[j] == ')') || (ch == '[' && str[j] == ']'))
                    {
                        curj = j;
                        j++;
                        S.pop();
                        if(ch == '[') cur++;
                    }
                    else {j++;break;}
                }
                curi = i - 1 - (curj-i);
//                while(!S.empty()) S.pop();
                if(prevj+1 == curi) curi = previ , cur += prev;
                if(cur > best)
                {
                    best = cur;
                    besti = curi;
                    bestj = curj;
                }
                i = j-1;
                prev = cur;
                previ = curi;
                prevj = curj;
            }
        }
        printf("%d\n",best);
//        printf("curi = %d\n",curi);
        if(best) for(i=besti;i<=bestj;i++) printf("%c",str[i]);
        printf("\n");
    }

    return 0;
}
