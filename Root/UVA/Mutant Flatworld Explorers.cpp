#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>

using namespace std;

#define SZ 55

int row , col , dir , x1 , x2 , y1 , y2 ,scent[SZ][SZ];
char arr[110];
char sign[] = {'S' , 'W' , 'N' , 'E'};
int x[] = {0 , -1 , 0 , 1};
int y[] = {-1 , 0 , 1 , 0};

bool move(int pos)
{
    if(pos >= strlen(arr)) return 0;
    if(arr[pos] != 'F') dir = (dir + (arr[pos]=='L' ? 3 : 1)) % 4;
    if(arr[pos] == 'F')
    {
        x2 = x1 + x[dir] , y2 = y1 + y[dir] ;
        if(x2>=0 && y2>=0 && x2<=row && y2<=col) x1 = x2 , y1 = y2;
        else if( !scent[x1][y1] ) return scent[x1][y1] = 1;
    }
    return move(pos+1);
}

int main()
{
    map <char , int> m;
    m['S'] = 0 , m['W'] = 1 , m['N'] = 2 , m['E'] = 3;
    bool lost;
    char ch;
//    freopen("1.txt","r",stdin);
    scanf("%d %d",&row,&col);
    while(scanf("%d %d %c %s",&x1,&y1,&ch,arr) == 4)
    {
        dir = m[ch];
        lost = move(0);
        printf("%d %d %c",x1,y1,sign[dir]);
        if(lost) printf(" LOST\n");
        else printf("\n");
    }

    return 0;
}
