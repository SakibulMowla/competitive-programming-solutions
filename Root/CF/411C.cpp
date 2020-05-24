//#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <stack>
#include <bitset>

#define sz 55
#define pb(a) push_back(a)
#define pp pop_back()
#define ll long long
#define fread freopen("input.txt","r",stdin)
#define fwrite freopen("output.txt","w",stdout)
#define inf (1e9)
#define chng(a,b) a^=b^=a^=b;
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define PI acos(-1)
#define fr(i,a,b) for(i=a;i<=b;i++)
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define mod 1000000007
using namespace std;

pair<int, int>p[4];

int main()
{
//#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
//    #endif
    int a[4], b[4],ta=0,tb=0, draw=0;
    int n=-1,m=0, attc, deff;
    while(~scanf("%d %d", &a[0], &b[0]))
    {
        for (int i = 1; i<4; i++) scanf("%d %d", &a[i], &b[i]);
        n=-1;
        p[0].first = a[0];
        p[1].first = a[1];
        p[0].second = b[1];
        p[1].second = b[0];

        p[2].first = a[2];
        p[3].first = a[3];
        p[2].second = b[3];
        p[3].second = b[2];

        for (int i = 0; i<2; i++)
        {
            ta=tb=draw=0;
            for (int j = 0; j<2; j++)
            {
                if(p[i].first>p[2+j].first) attc = 1;
                else if(p[i].first<p[2+j].first) attc = 2;
                else attc = 0;

                if(p[i].second>p[2+j].second) deff = 1;
                else if(p[i].second<p[2+j].second) deff = 2;
                else deff = 0;

                if(attc==1&&deff==1) ta++;
                else if(attc==2&&deff==2) tb++;
                else draw++;
            }
//            cout<<ta<<" "<<tb<<" "<<draw<<" "<<n<<endl;
            if(ta==2)
            {
                n = 1;
                break;
            }
            else if(draw && tb == 0) n = 0;
            else if(tb>0&&n) n = 2;
        }

        if(n==1) printf("Team 1\n");
        else if(n==2) printf("Team 2\n");
        else printf("Draw\n");

    }
    return 0;
}


/*
Input:
41 85
72 38
80 69
65 68

Output:
Team 1

Input:
96 22
49 67
51 61
63 87

Output:
Team 1

Input:
66 24
80 83
71 60
64 52

Output:
Team 1

*/
