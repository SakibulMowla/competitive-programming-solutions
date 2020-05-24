#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int n;
void func(int r,int c,char arr[100][100]);
int main()
{
    int m,i,j,count;
    char arr[100][100],z;
    m=1;
    while(cin >> n >> z)
    {
        memset(arr,0,sizeof arr);
        for(i=0;i<n;i++)
            gets(arr[i]);
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]=='1')
                {
                    count++;
                    arr[i][j]='0';
                    func(i,j,arr);
                }
            }
        }
        cout << "Image number "<< m <<" contains "<< count <<" war eagles." << endl;
        m++;
    }

    return 0;
}

void func(int r,int c,char arr[100][100])
{
    int i,j;
    if(r<0 || r>=n || c<0 || c>=n)
        return;
    for(i=r-1;i<=r+1;i++)
    {
        for(j=c-1;j<=c+1;j++)
        {
            if(arr[i][j]=='1')
            {
                arr[i][j]='0';
                func(i,j,arr);
            }
        }
    }
    return;
}
