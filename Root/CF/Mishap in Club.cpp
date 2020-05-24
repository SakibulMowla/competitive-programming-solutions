#include "iostream"
using namespace std;
int cnt , i , ansp , ansn;
string s;
int main()
{
    cin >> s;
    for(i=0; i<s.size(); i++)
    {
        if(s[i] == '+') cnt++;
        else cnt--;
        ansp = max(ansp,cnt);
        ansn = min(ansn,cnt);
    }
    cout << ansp - ansn;
    return 0;
}
