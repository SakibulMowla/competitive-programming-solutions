#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "iostream"
#include "algorithm"
#define SZ 110
using namespace std;
typedef long long ll;
struct data
{
    string name , insen;
    ll time;
};

bool comp(data p,data q)
{
    if(p.time == q.time) return p.insen < q.insen;
    return p.time < q.time;
};

data arr[SZ];

int main()
{
    char str[100],str1[30],str2[30];
    ll i,j,k,n,x,y,z;
    while(scanf("%lld",&n) == 1)
    {
        for(i=0;i<n;i++)
        {
            scanf(" %[^\n]",str);
            sscanf(str," %s : %lld %s %lld %s %lld %s",str1,&x,str2,&y,str2,&z,str2);
            for(j=0;j<strlen(str1);j++)
                str2[j] = tolower(str1[j]);
            str2[j] = '\0';
            k = (x*60 + y) * 1000 + z;
            arr[i].name = str1;
            arr[i].insen = str2;
            arr[i].time = k;
        }
        stable_sort(arr,arr+n,comp);
        k = 0;
        for(i=0;i<n;i++)
        {
            if(i%2 == 0) printf("Row %lld\n",++k);
            printf("%s\n",arr[i].name.c_str());
        }
        printf("\n");
    }

    return 0;
}
