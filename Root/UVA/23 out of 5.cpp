#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

vector <char> signs;
vector <string> final;
int A[5];
char operand[] = {'+','-','*'};

bool found;

int calculate(int a,int b,char ch)
{
    if(ch == '+')
        return a+b;
    if(ch == '-')
        return a-b;
    if(ch == '*')
        return a*b;
}

void backtrack()
{
    int i;
    for(i=0;i<81;i++)
    {
        int r1,r2,r3,r4;
        do
        {
            if(found)
                break;
            r1 = calculate(A[0],A[1],final[i][0]);
            r2 = calculate(r1,A[2],final[i][1]);
            r3 = calculate(r2,A[3],final[i][2]);
            r4 = calculate(r3,A[4],final[i][3]);

            if(r4 == 23)
                found = true;

        }while(next_permutation(A,A+5));
    }
}

void precompute()
{
    int i;
    if(signs.size() == 4)
    {
        string str;
        for(i=0;i<4;i++)
            str += signs[i];
        final.push_back(str);
        return;
    }
    for(i=0;i<3;i++)
    {
        signs.push_back(operand[i]);
        precompute();
        signs.pop_back();
    }
}

int main()
{
    precompute();
//    freopen("1.txt","r",stdin);
    while(scanf(" %d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&A[4]) == 5)
    {
        if(A[0]==0 && A[1]==0 && A[2]==0 && A[3]==0 && A[4]==0)break;
        signs.clear();
        found = false;
        sort(A,A+5);
        backtrack();
        if(found)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
