#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define Union(a,b) par[find(a)] = find(b)
#define SZ 30

int par[SZ] , in[SZ] , out[SZ];

int find(int r)
{
    if(r == par[r])
        return r;
    return par[r] = find(par[r]);
}

void init()
{
    int i;
    for(i=0;i<SZ;i++)
    {
        par[i] = i;
        in[i] = 0;
        out[i] = 0;
    }
}

char arr[1010];

void solve()
{
    int n,n1,n2,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %[^\n]",arr);
        n1 = arr[0] - 'a' + 1;
        n2 = arr[ strlen(arr) - 1 ] - 'a' + 1;
        out[n1]++;
        in[n2]++;
        Union(n1,n2);
    }
    int equal = 0 , inoutp = 0 , outinp = 0 ;// equal means (in == out), inoutp means (in = out + 1), outinp means(out = in + 1)
    int flag1 = 0 , flag2 = 0 , test , mot = 0 , paisi = 0;
    for(i=1;i<=26;i++)
    {
        if(in[i] == out[i]) equal++;
        else if(in[i] == out[i] + 1) inoutp++;
        else if(out[i] == in[i] + 1) outinp++;
    }
    if(equal==26 || (equal == 24 && inoutp == 1 && outinp == 1)) flag1 = 1;
    for(i=1;i<=26;i++)
    {
        if(in[i] + out[i] > 0)
        {
            test = find(i);
            break;
        }
    }
    for(i=1;i<=26;i++)
    {
        if(in[i] + out[i] > 0)
        {
            mot++;
            if(find(i) == test) paisi++;
        }
    }
    if(mot == paisi) flag2 = 1;
//    printf("%d %d t = %d\n",flag1,flag2,test);
    if(flag1 && flag2) printf("Ordering is possible.\n");
    else printf("The door cannot be opened.\n");
}

int main()
{
    int test ;
    scanf("%d",&test);
    while(test--)
    {
        init();
        solve();
    }

    return 0;
}
