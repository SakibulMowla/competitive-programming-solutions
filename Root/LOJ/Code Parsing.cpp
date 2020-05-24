#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

string s;

int main()
{
    int n,i,j,flag1,flag2,cnt1,cnt2;
    while(cin >> s)
    {
//        while(1)
//        {
//            flag1 = flag2 = 0;
//            for(i=0; i<s.size()-1; i++)
//            {
//                if(s[i] == 'y' && s[i+1]=='x')
//                {
//                    swap(s[i],s[i+1]);
//                    flag1 = 1;
//                    break;
//                }
//            }
//            if(flag1 == 1) continue;
//            for(i=0;i<s.size()-1;i++)
//            {
//                if(s[i]=='x' && s[i+1]=='y')
//                {
//                    s.erase(i,2);
//                    flag2 = 1;
//                    break;
//                }
//            }
//            if(flag2 == 1)continue;
//            cout << s << endl;
//            return 0;


//        }

        cnt1 = cnt2 = 0;
        for(i=0;i<s.size();i++)
        {
            if(s[i] == 'x') cnt1++;
            if(s[i] == 'y') cnt2++;
        }
        if(cnt1 > cnt2)
        {
            for(i=cnt2;i<cnt1;i++) printf("x");
            printf("\n");
        }
        else if(cnt2 > cnt1)
        {
            for(i=cnt1;i<cnt2;i++) printf("y");
            printf("\n");
        }
        else printf("\n");
    }

    return 0;
}
