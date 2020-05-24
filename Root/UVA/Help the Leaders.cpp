#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "vector"
#include "map"
#include "algorithm"
#include "string"
#include "iostream"

using namespace std;

bool comp(string a,string b)
{
    if(a.size() == b.size())
        return a < b;
    return a.size() > b.size();
}

vector <string> input , output;
map <string , int> m;

int t , s , p , k;
bool collision[200][200];

void backtrack(int n)
{
    int i,j;
    if(output.size() == s)
    {
        cout << output[0];
        for(i=1; i<output.size(); i++)
            cout << " " << output[i];
        printf("\n");
        return;
    }
    for(i=n; i<k; i++)
    {
        for(j=0; j<output.size(); j++)
            if(collision[m[output[j]]][m[input[i]]] == 1)
                break;
        if(j == output.size())
        {
            output.push_back(input[i]);
            backtrack(i+1);
            output.pop_back();
        }
    }
}

int main()
{
    int t1,test,i,j,l;
    char arr[200],arr1[200];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    for(t1=1; t1<=test; t1++)
    {
        k = 0;
        scanf("%d %d %d",&t,&p,&s);
        m.clear();
        input.clear();
        output.clear();
        for(i=1; i<=t; i++)
        {
            scanf(" %s",arr);
            for(l=0;arr[l];l++)
                arr[l] = toupper(arr[l]);
            if(m.find(arr) == m.end())
            {
                m[arr] = ++k;
                input.push_back(arr);
            }
        }

        sort(input.begin(),input.end(),comp);
        for(i=0; i<=t; i++)
            for(j=0; j<=t; j++)
                collision[i][j] = 0;
        for(i=1; i<=p; i++)
        {
            scanf(" %s %s",arr,arr1);
            for(l=0;arr[l];l++)
                arr[l] = toupper(arr[l]);
            for(l=0;arr1[l];l++)
                arr1[l] = toupper(arr1[l]);
            collision[m[arr]][m[arr1]] = collision[m[arr1]][m[arr]] = 1;
        }
        printf("Set %d:\n",t1);
        for(i=0; i<t; i++)
        {
            output.clear();
            output.push_back(input[i]);
            backtrack(i+1);
        }
        printf("\n");
    }

    return 0;
}
