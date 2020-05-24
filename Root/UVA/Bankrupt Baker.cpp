#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

struct data {string item ; int price ;};
bool comp(data p,data q) { if(p.price == q.price) return p.item < q.item ; return p.price < q.price; }

map <string , int> msi;
vector <data> input;

int main()
{
//    freopen("1.txt","r",stdin);
    data u;
    char arr[101];
    int i,j,k,n,m,budj,t,sum,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %[^\n]",arr);
        for(i=0;arr[i];i++) printf("%c",toupper(arr[i]));
        printf("\n");

        input.clear();
        msi.clear();

        scanf("%d %d %d",&m,&n,&budj);
        for(i=0;i<m;i++)
        {
            scanf("%s %d",arr,&j);
            msi[arr] = j;
        }

        for(i=0;i<n;i++)
        {
            scanf(" %[^\n]",arr);
            u.item = arr;
            scanf("%d",&k);
            sum = 0;
            for(j=0;j<k;j++)
            {
                scanf("%s %d",arr,&flag);
                sum += msi[arr] * flag;
            }
            u.price = sum;
            input.push_back(u);
        }

        sort(input.begin(),input.end(),comp);

        flag = 0;

        for(i=0;i<input.size();i++)
            if(input[i].price <= budj)
                flag = 1 , cout << input[i].item << endl;

        if(flag == 0) printf("Too expensive!\n");

        printf("\n");
    }

    return 0;
}
