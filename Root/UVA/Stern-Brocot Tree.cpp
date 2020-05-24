// _n = Numerator && _d = Denominator
#include <stdio.h>
#include <string.h>

int main()
{
    long long cur_n,cur_d,L_n,L_d,R_n,R_d,i,len,test;
    char arr[100];
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%s",arr);
        cur_n = 1 , cur_d = 1 , L_n = 0, L_d = 1 , R_n = 1 , R_d = 0;
        len = strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i] == 'L')
            {
                R_n = cur_n;
                R_d = cur_d;
                cur_n += L_n;
                cur_d += L_d;
            }
            else
            {
                L_n = cur_n;
                L_d = cur_d;
                cur_n += R_n;
                cur_d += R_d;
            }
        }
        printf("%lld/%lld\n",cur_n,cur_d);
    }
    return 0;
}
