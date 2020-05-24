#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str,temp;
    vector <string> v;
    int i,j,k,flag;
    while(cin >> str)
    {
        if(str == "XXXXXX")break;
        v.push_back(str);
    }
    sort(v.begin(),v.end());
    while(cin >> str)
    {
        if(str == "XXXXXX")break;
        flag=0;
        sort(str.begin(),str.end());
        for(i=0;i<v.size();i++)
        {
            temp = v[i];
            sort(temp.begin(),temp.end());
            if(temp == str)
            {
                cout<< v[i] << endl;
                flag=1;
            }
        }
        if(flag == 0)
            cout<< "NOT A VALID WORD" << endl;
        cout<< "******" << endl;
    }

    return 0;
}
