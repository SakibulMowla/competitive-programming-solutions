#include <stdio.h>
#include <string.h>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    int t,test,i,j,c,cnt,now;
    char arr[310];
    map <char , int> m , ser , unser;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        m.clear();
        ser.clear();
        unser.clear();
        now = cnt = 0;
        scanf("%d %s",&c,arr);
        for(i=0; i<strlen(arr); i++)
        {
            m[arr[i]]++;
            if(m[arr[i]] % 2 == 1)
            {
                if(now < c)
                {
                    now++;
                    ser[arr[i]]++;
                }
                else
                {
                    cnt++;
                    unser[arr[i]]++;
                }
            }
            else
            {
                if(ser[arr[i]] != 0)
                {
                    ser[arr[i]]--;
                    now--;
                }
                else if(unser[arr[i]] != 0)
                {
                    unser[arr[i]]--;
                }
            }
        }
        printf("Case %d: %d\n",++t,cnt);
    }

    return 0;
}
