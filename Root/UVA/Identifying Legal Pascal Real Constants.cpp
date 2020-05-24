#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdlib.h"

int valid[300];

int main()
{
    char arr[1010];
    valid['0'] = valid['1'] = valid['2'] = valid['3'] = valid['4'] = valid['5'] = valid['6'] = valid['7'] =
    valid['8'] = valid['9'] = valid['e'] = valid['E'] = valid['+'] = valid['-'] = valid['.'] = 1;
    int EXP,exp,plus,minus,point,i,j,k,n,len,flag,epos,dotpos;
    while(scanf(" %[^\n]",arr) == 1)
    {
        if(strcmp(arr,"*") == 0) break;
        EXP = exp = plus = minus = point = flag = epos = dotpos = 0;
        len = strlen(arr);
        while(len-1 && arr[len-1] == ' ')len--;
        for(i=0;i<len;i++)
        {
            if(valid[ arr[i] ])
            {
                if(arr[i] == '+')
                {
                    plus++;
                    if(plus > 1) {flag=1;break;}
                    if((i==0 && i+1<len && isdigit(arr[i+1]) ) || (i-1>=0 && (arr[i-1]=='e'||arr[i-1]=='E') && i+1<len && isdigit(arr[i+1]) ))
                        continue;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(arr[i] == '-')
                {
                    minus++;
                    if(minus > 1) {flag=1;break;}
                    if((i==0 && i+1<len && isdigit(arr[i+1]) ) || (i-1>=0 && (arr[i-1]=='e'||arr[i-1]=='E') && i+1<len && isdigit(arr[i+1]) ))
                        continue;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(arr[i] == 'e')
                {
                    exp++;
                    epos = i;
                    if(exp > 1) {flag=1;break;}
                    if(i!=0 && i!=len-1 && (i-1>=0 && isdigit(arr[i-1])) && (i+1<len && (isdigit(arr[i+1]) || arr[i+1] == '+' || arr[i+1] == '-' ) ) )
                        continue;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(arr[i] == 'E')
                {
                    EXP++;
                    epos = i;
                    if(EXP > 1) {flag=1;break;}
                    if(i!=0 && i!=len-1 && (i-1>=0 && isdigit(arr[i-1])) && (i+1<len && (isdigit(arr[i+1]) || arr[i+1] == '+' || arr[i+1] == '-' ) ) )
                        continue;
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(arr[i] == '.')
                {

                    point++;
                    dotpos = i;
                    if(point > 1) {flag=1;break;}
                    if(i!=0 && i!=len-1 && (i-1>=0 && isdigit(arr[i-1])) && (i+1<len && isdigit(arr[i+1]) ) )
                        continue;

                    else
                    {
                        flag = 1;
                        break;
                    }

                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(point + exp + EXP == 0 || exp + EXP > 1 || point + exp + EXP > 2 || (point + exp + EXP == 2 && dotpos > epos))
        {
            flag = 1;
        }

        if(flag) printf("%s is illegal.\n",arr);
        else printf("%s is legal.\n",arr);

    }

    return 0;
}
