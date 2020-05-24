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

typedef long long ll;

//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

//template <class T> T gcd(T a, T b)
//{
//    while(b) b ^= a ^= b ^= a %= b;
//    return a;
//}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

//%I64d
int main()
{
    ll i,j,k,n,len1,len2,one;
    string a,b;
    while(cin >> a >> b)
    {
        len1 = a.size();
        len2 = b.size();
        if(a == b)
        {
            printf("YES\n");
            continue;
        }
        k = 1;
        one = 0;
        for(i=0; i<len1; i++)
            if(a[i] == '1')
                one++;
        i = 0;
//        string c;
        while(i<len2)
        {
//            cout << i << "\n";
//            cout << a << "\n";
            n = a.size();
            if(n == 0)
            {
                break;
            }
            if(a == b) break;
            if(b[i] == '0')
            {
//                cout << "one = " << one << "\n";
                if(one%2 == 0)
                {
                    i++;
//                    c += '0';
                    a += '0';
                }
                else
                {
                    j = 0;
                    while(a.size() != 0)
                    {
                        if(a[0] == '1')
                        {
                            a.erase(a.begin(),a.begin()+1);
                            one--;
                            a += '0';
                            i++;
//                            cout << "sdfa = " << a << "\n";
                            break;
                        }
//                        cout << "qwa = " << a << "\n";
                        a.erase(a.begin(),a.begin()+1);
//                        cout << "qwa = " << a << "\n";
                        if(a.size() == 0)
                        {
                            k = -1;
                            break;
                        }

                    }
                    if(k == -1) break;

                }
            }

            else if(b[i] == '1')
            {
                if(one % 2 == 0)
                {
                    j = 0;
                    while(a.size() != 0)
                    {
                        if(a[0] == '1')
                        {
                            a.erase(a.begin(),a.begin()+1);
//                            c[i] = '1';
                            a += '1';
                            i++;
//                            cout << "a = " << a << "\n";
                            break;
                        }
                        a.erase(a.begin(),a.begin()+1);
                        if(a.size() == 0)
                        {
                            k = -1;
                            break;
                        }

                    }
                    if(k == -1) break;
                }
                else
                {
                    one++;
                    a += '1';
                    i++;
                }
            }
        }

        if(k <= 0) printf("NO\n");
        while(a.size() > len2)
            a.erase(0,1);
        if(a == b) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
