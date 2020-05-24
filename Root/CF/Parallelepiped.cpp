#include "stdio.h"
#include "math.h"
#include "iostream"
using namespace std;
int main()
{
    long long a,b,c,ab,bc,ca,abc;
    while(cin >> ab >> bc >> ca)
    {
        abc = sqrt(ab * bc * ca);
        a = abc / bc;
        b = abc / ca;
        c = abc / ab;
        abc = 4 * (a + b + c);
        printf("%I64d\n",abc);
    }

    return 0;
}
