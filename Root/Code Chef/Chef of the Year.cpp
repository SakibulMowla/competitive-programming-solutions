#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

struct data
{
    string name;
    int vote;
    int indx;
};

bool comp(data p,data q)
{
    if(p.vote == q.vote)
        return p.name < q.name;
    return p.vote > q.vote;
}

int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,i,j,k,indx1,indx2;
    string name1,name2;
    data u,v;
    vector <data> country , chef;
    map <string , int > msi;
    map <string , int > msc;
    map <string , int > msi1;

    while(scanf("%d %d",&n,&m) == 2)
    {
        k = 0;
        for(i=0; i<n; i++)
        {
            cin >> name1 >> name2;
            u.name = name1;
            u.vote = 0;
            u.indx = i;
            chef.push_back(u);
            msi[name1] = i;
            if(msc.find(name2) == msc.end())
            {
                v.name = name2;
                v.vote = 0;
                v.indx = k;
                msc[name2] = k++;
                country.push_back(v);
            }
            msi1[name1] = msc[name2];
        }

        for(i=0;i<m;i++)
        {
            cin >> name1;
            j = msi[name1];
            k = msi1[name1];
            chef[j].vote++;
            country[k].vote++;
        }

        sort(country.begin(),country.end(),comp);
        sort(chef.begin(),chef.end(),comp);

        cout << country[0].name << "\n" << chef[0].name << "\n";

        country.clear();
        chef.clear();
        msi.clear();
        msc.clear();
        msi1.clear();
    }

    return 0;
}
