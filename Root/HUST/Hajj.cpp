#include "bits/stdc++.h"
using namespace std;
int main()
{
string s;
int cas=0;
while(cin>>s)
{
if(s=="*") break;
if(s=="Hajj") s="Hajj-e-Akbar";
else s="Hajj-e-Asghar";
printf("Case %d: ",++cas);
cout<<s<<endl;
}
return 0;
}
