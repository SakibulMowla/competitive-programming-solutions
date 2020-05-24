////BISMILLAHIRRAHMANIRRAHIM
#include "stdio.h"

#define SZ 110
#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define swap(a,b) a^=b^=a^=b

int main()
{
    int arr[SZ] , t , test , n ,i , j , cnt;
    test = 0;
    SD(t);
    while(t--)
    {
        cnt = 0;
        SD(n);
        FORI(i,1,n) SD(arr[i]);
        FORI(i,1,n) if(arr[i] != i)
        FORI(j,i+1,n) if(arr[j] == i) swap(arr[j],arr[i]) , cnt++;
        printf("Case %d: %d\n",++test,cnt);
    }

    return 0;
}
