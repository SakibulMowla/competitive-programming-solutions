#include "stdio.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
#define SZ 20

int Set(int n,int pos) { return n = n | (1<<pos); }
int reset(int n,int pos) { return n = n & ~(1<<pos); }
int check(int n,int pos) { return n & (1<<pos); }

int avg , N , arr[SZ+2] , first[5];
template <class T> T max(T a,T b) { return a > b ? a : b; }

int solve(int n,int mask,int sum,int group)
{
    if(mask == (1<<N)-1 && group == 4) return 1;
    if(sum > avg) return 0;
    if(sum == avg) return solve(first[group]+1,mask,0,group+1);
    for(int i=n;i<N;i++) if(!check(mask,i))
    {
        if(sum == 0) first[group] = i;
        int tmp = Set(mask,i);
        if(solve(i+1,tmp,sum+arr[i],group)) return 1;
    }
    return 0;
}

int main()
{
    int i,j,n,t,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        N = n;
        sum = 0;
        j = 0;
        for(i=0;i<n;i++) scanf("%d",&arr[i]) , sum += arr[i] , j = arr[i] > j ? arr[i] : j;
        if(sum % 4 || j > (sum/4))
        {
            printf("no\n");
            continue;
        }
        avg = sum / 4;
        if(solve(0,0,0,0)) printf("yes\n");
        else printf("no\n");
     }

    return 0;
}
