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

#define MAX 200000
/******************************************************************/
void reverse(char *from, char *to )
{
    int len=strlen(from);
    int l;
    for(l=0; l<len; l++)
        to[l]=from[len-l-1];
    to[len]='\0';
}
char F[MAX],S[MAX],temp[MAX];

/******************************************************************/
void call_mult(char *first,char *sec,char *result)
{

    int f_len,s_len,f,s,r,t_len,hold,res;
    f_len=strlen(first);
    s_len=strlen(sec);
    reverse(first,F);
    reverse(sec,S);
    t_len=f_len+s_len;
    r=-1;

    for(f=0; f<=t_len; f++)
        temp[f]='0';
    temp[f]='\0';
    for(s=0; s<s_len; s++)
    {
        hold=0;
        for(f=0; f<f_len; f++)
        {
            res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
            temp[f+s]=res%10+'0';
            hold=res/10;
            if(f+s>r) r=f+s;
        }
        while(hold!=0)
        {
            res=hold+temp[f+s]-'0';
            hold=res/10;
            temp[f+s]=res%10+'0';
            if(r<f+s) r=f+s;
            f++;
        }
    }
    for(; r>0 && temp[r]=='0'; r--);
    temp[r+1]='\0';
    reverse(temp,result);
}
/***************************************************************/
int main()
{
    char fir[MAX],sec[MAX],res[MAX];
    char tmp[MAX];

    ll n, m, i, j, k, ans, chalu;

    string s;
    fir[0] = '1';
    fir[1] = '\0';

    while(cin >> s)
    {
        chalu = 10;
        memset(mark,0,sizeof(mark));
        k = s.size();
//        ans =1;
        for(i=0; i<k; i++)
        {
            if(s[i] == '?')
            {
                if(i == 0)
                {
                    sprintf(tmp,"%I64d",9);
                    call_mult(fir,tmp,res);
                    strcpy(fir,res);
                }
                else
                {
                    sprintf(tmp,"%I64d",10);
                    call_mult(fir,tmp,res);
                    strcpy(fir,res);
                }
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
                    mark[ s[i] ] = 1;
                    if(i == 0)
                    {
                        sprintf(tmp,"%I64d",chalu-1);
                        call_mult(fir,tmp,res);
                        strcpy(fir,res);
                    }
                    else
                    {
                        sprintf(tmp,"%I64d",chalu);
                        call_mult(fir,tmp,res);
                        strcpy(fir,res);
                    }
                    chalu--;
                }
            }
        }

        printf("%s\n",fir);
    }

    return 0;
}
