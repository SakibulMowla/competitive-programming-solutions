#include "stdio.h"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#include "algorithm"
#include "iostream"

using namespace std;

int main()
{
    int num1,num2,i,k,t,power;
    char arr[200];
    string ans,str1,str2;
    scanf("%d",&t);
    while(t--)
    {
        ans.erase();
        str1.erase();
        str2.erase();
        num1 = num2 = k = i = 0;
        scanf(" %[^\n]",arr);
        while(arr[i])
        {
            if(isalpha(arr[i]))
            {
                while(isalpha(arr[i]))
                {
                    if(k==0) str1 += arr[i];
                    else str2 += arr[i];
                    i++;
                }
                k++;
            }
            else if(isdigit(arr[i]))
            {
                while(isdigit(arr[i]))
                {
                    if(k == 1) num1 = (num1 * 10) + arr[i] - '0';
                    else num2 = (num2 * 10) + arr[i] - '0';
                    i++;
                }
            }
        }
        if(k == 2)
        {
            while(num2)
            {
                if(num2 % 26 == 0)
                {
                    ans += 'Z';
                    num2 = (num2 - 1) / 26;
                }
                else
                {
                    ans += num2%26 + 64;
                    num2 /= 26;
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<num1<<endl;
        }
        else
        {
            k = 0;
            power = 1;
            for(i=str1.size()-1;i>=0;i--)
            {
                k += power * (str1[i] - 'A' + 1);
                power *= 26;
            }
            cout << "R" << num1 << "C" << k << endl;
        }
    }

    return 0;
}
