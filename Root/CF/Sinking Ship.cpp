#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

struct data { string name; int prio; };
bool comp(data p,data q) { return p.prio < q.prio; }

vector <data> input;
map <string , int> msi;

int main()
{
    data u;
    int i,n;
    string arr;
    msi["rat"] = 0;
    msi["woman"] = 1;
    msi["child"] = 1;
    msi["man"] = 2;
    msi["captain"] = 3;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> arr;
        u.name = arr;
        cin >> arr;
        u.prio = msi[arr];
        input.push_back(u);
    }
    stable_sort(input.begin(),input.end(),comp);
    for(i=0;i<n;i++) cout << input[i].name << endl;

    return 0;
}
