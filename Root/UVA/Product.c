#include <stdio.h>
#include <string.h>

#define SZ 200000

char arr1[SZ],arr2[SZ],mul1[SZ],mul2[SZ],str[SZ],rev[SZ],res[SZ];

int mul(char arr1[],char arr2[])
{
    int p,i,j,k,l,n,m,c,car,sum,add1,add2,add,len1,len2,len3,len4,mul;

//    while(scanf("%s %s",arr1,arr2)==2)
    {
        len1=strlen(arr1);
        len2=strlen(arr2);
        if((len1==1 && arr1[0]=='0') || (len2==1 && arr2[0]=='0'))
        {
            res[0]='0';
            res[1]='\0';
            return res;
        }

        for(i=len2-1,p=0;i>=0;i--,p++)
        {
            strcpy(mul2,res);
            c=0;car=0;
            for(j=len1-1;j>=0;j--)
            {
                mul=((arr2[i]-'0')*(arr1[j]-'0'))+car;
                str[c++]=(mul%10)+'0';
                car=mul/10;
            }
            if(car>0)
                str[c++]=car+'0';
            for(k=c-1,l=0;k>=0;k--,l++)
                mul1[l]=str[k];
            for(j=0;j<p;j++)
                mul1[l++]='0';
            mul1[l]='\0';

            len3=strlen(mul1);
            len4=strlen(mul2);
            car=0;c=0;

            for(j=len3-1,k=len4-1;j>=0 || k>=0;j--,k--)
            {
                if(mul1[j]>='0' && mul1[j]<='9')
                    add1=mul1[j]-'0';
                else add1=0;
                if(mul2[k]>='0' && mul2[k]<='9')
                    add2=mul2[k]-'0';
                else add2=0;
                add=add1+add2+car;
                rev[c++]=(add%10)+'0';
                car=add/10;
            }
            if(car>0)
                rev[c++]=car+'0';
            for(k=c-1,j=0;k>=0;k--,j++)
            {
                res[j]=rev[k];
            }
            res[j]='\0';
            strcpy(mul1,res);
        }

        return res;
//        for(i=0;i<2000;i++)
//        {
//            arr1[i]=arr2[i]=mul1[i]=mul2[i]=str[i]=rev[i]=res[i]=0;
//        }
    }
    return 0;
}


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
//
//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//
//template <class T> T gcd(T a, T b)
//{
//    while(b == 0) return a;
//    return gcd(b,a%b);
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

int mark[300];

//%I64d
int main()
{
    ll n, m, i, j, k, chalu;

    string s;
    char tmp[12];

    while(cin >> s)
    {
        chalu = 10;
        memset(mark,0,sizeof(mark));
        k = s.size();
        ans[0] = '1';
        ans[1] = '\0';
        for(i=0;i<k;i++)
        {
            if(s[i] == '?')
            {
                if(i == 0) ans = mul(ans,"9");
                else ans = mul(ans,"10");
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
//                ans *= 1;
;
            }
            else
            {
                if(mark[ s[i] ] == 0)
                {
                    sprintf(tmp,"%I64d",chalu);
                    mark[ s[i] ] = 1;
                    if(i == 0)
                    {
                        sprintf(tmp,"%I64d",chalu-1);
                        ans = mul(ans,tmp);
                    }
                    else ans = mul(ans,tmp);;
                    chalu--;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
