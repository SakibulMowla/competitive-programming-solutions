#include "stdio.h"
#include "string.h"
#include "string"
#include "stack"
#include "iostream"

using namespace std;

typedef long long ll;

string str;
stack <ll> S;

ll maxim()
{
    while(!S.empty()) S.pop();
    ll i,j,k,l,p;
    l = str.size();
    j = 0;
    for(i=0;i<l;i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            j = (j*10) + str[i] - '0';
        else if(str[i] == '*')
            S.push(j) , j = 0;
        else if(str[i] == '+')
        {
            k = i;
            p = 0;
            while(k < l && str[k+1] >= '0' && str[k+1] <= '9')
                p = (p*10) + str[k+1] - '0' , k++;
            j += p;
            i = k;
        }
    }
    S.push(j);
    j = 1;
    while(!S.empty())
    {
        j *= S.top();
        S.pop();
    }
    return j;
}

ll minim()
{
    while(!S.empty()) S.pop();
    ll i,j,k,l,p;
    l = str.size();
    j = 0;
    for(i=0;i<l;i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            j = (j*10) + str[i] - '0';
        else if(str[i] == '+')
            S.push(j) , j = 0;
        else if(str[i] == '*')
        {
            k = i;
            p = 0;
            while(k < l && str[k+1] >= '0' && str[k+1] <= '9')
                p = (p*10) + str[k+1] - '0' , k++;
            j *= p;
            i = k;
        }
    }
    S.push(j);
    j = 0;
    while(!S.empty())
    {
        j += S.top();
        S.pop();
    }
    return j;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        cin >> str;
        printf("The maximum and minimum are %lld and %lld.\n",maxim(),minim());
    }

    return 0;
}
