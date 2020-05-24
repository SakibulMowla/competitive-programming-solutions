#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

vector <int> ind;
vector <string> num;

struct data{int n;string d;};
bool comp(data p,data q)
{
    return p.n < q.n;
}

vector <data> v;

int main()
{
    data u;
    int i,j,k,test,number;
    char arr[100000];
    bool blank = false;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);

    while(test--)
    {
        v.clear();
        num.clear();
        ind.clear();
        scanf(" %[^\n]",arr);
        char *tok = strtok(arr," ");
        number = 0;
        j = 0;
        while( tok != NULL )
        {
            number = atoi(tok);
            ind.push_back(number);
            tok = strtok(NULL," ");
            j++;
        }
        scanf(" %[^\n]",arr);
        tok = strtok(arr," ");
        while( tok != NULL )
        {
            num.push_back(tok);
            tok = strtok(NULL," ");
        }

        for(k=0;k<j;k++)
        {
            u.n = ind[k];
            u.d = num[k];
            v.push_back(u);
        }

        sort(v.begin(),v.end(),comp);

        if(blank)printf("\n");
            blank = true;
        for(i=0;i<v.size();i++)
            cout << v[i].d << endl;
    }

    return 0;
}
