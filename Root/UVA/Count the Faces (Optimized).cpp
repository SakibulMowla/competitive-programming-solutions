#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector <int> parent;

#define vector_clear parent.clear()
#define makeset() parent.push_back(parent.size())
#define Union(a,b) parent[find(a)] = find(b)

int find(int r)
{
    if(r == parent[r])
        return r;
    parent[r] = find(parent[r]);
}

int main()
{
    map <char , int> char_to_int;
    map <int , int> int_to_int;
    int i,v,e;
    char a,b;

    while(scanf("%d %d",&v,&e) == 2)
    {
        vector_clear;
        char_to_int.clear();
        int_to_int.clear();

        for(i=0;i<v;i++)
            makeset();
        for(i=0;i<e;i++)
        {
            scanf(" %c %c",&a,&b);
            if(char_to_int.find(a) == char_to_int.end())
                char_to_int[a] = char_to_int.size() - 1;
            if(char_to_int.find(b) == char_to_int.end())
                char_to_int[b] = char_to_int.size() - 1;
            Union(char_to_int[a] , char_to_int[b]);
        }

        for(i=0;i<v;i++)
        {
            int_to_int[find(i)] ++;
        }

        printf("%d\n",1 + int_to_int.size() + e - v);
    }

    return 0;
}
