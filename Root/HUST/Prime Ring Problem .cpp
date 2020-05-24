#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

int arr[50] , taken[50] , n;
vector <int> ans;

void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=4;i<50;i+=2) arr[i] = 1;
    for(i=3;i<sqrt(50);i++)
        if(arr[i] == 0)
            for(j=i*i;j<50;j+=i+i)
                arr[j] = 1;
}

void bctk()
{
    int i,j;
    if(ans.size() == n)
    {
        if(arr[ ans[0] + ans[ans.size()-1] ] == 1) return;
//        for(i=0;i<ans.size()-1;i++)
//            if(arr[ ans[i] + ans[i+1] ] == 1) return;

        j = 0;
        for(i=0;i<ans.size();i++)
        {
            if(j) printf(" ");
            j = 1;
            printf("%d",ans[i]);
        }
        printf("\n");
        return;
    }
    for(i=2;i<=n;i++)
    {
        if(taken[i] == 0)
        {
            if(ans.size() > 0 && arr[ans[ans.size()-1] + i] == 1) continue;
            ans.push_back(i);
            taken[i] = 1;
            bctk();
            ans.pop_back();
            taken[i] = 0;
        }
    }
}

int main()
{
    sieve();
    int i,j,k,t;
    t = 0;
    while(scanf("%d",&n) == 1)
    {
        if(t) printf("\n");
        memset(taken,0,sizeof(taken));
        ans.clear();
        ans.push_back(1);
        taken[1] = 1;
        printf("Case %d:\n",++t);
        bctk();
    }

    return 0;
}
