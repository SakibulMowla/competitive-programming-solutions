#include "stdio.h"
#include "string.h"

char input1[]="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
char input2[]="~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char output1[]="`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
char output2[]="~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

int main()
{
    int i,j,k,len,len1;
    char arr[10100];
    while(gets(arr))
    {
        len = strlen(arr);
        len1 = strlen(input1);
        for(i=0;i<len;i++)
        {
            k = 0;
            for(j=0;j<len1;j++)
            {
                if(input1[j] == arr[i])
                {
                    printf("%c",output1[j]);
                    k = 1;
                    break;
                }
                if(input2[j] == arr[i])
                {
                    printf("%c",output2[j]);
                    k = 1;
                    break;
                }
            }
            if(k == 0) printf("%c",arr[i]);
        }

        printf("\n");
    }

    return 0;
}
