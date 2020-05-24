#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "iostream"
#include "algorithm"

using namespace std;

map <string , int> dic;
map <string , int> wordmap;
vector <char> board[5];
vector <string> words;
string tmp;
int r,c;
int taken[5][5];
int check[30][30];

int cnt;

void make_word()
{
    cnt++;
//    printf("%d\n",cnt);
    int i,j;
    if(dic.find(tmp) != dic.end()/* && wordmap.find(tmp) == wordmap.end()*/)
    {
        words.push_back(tmp);
        wordmap[tmp] = 1;
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(taken[i][j] == 0)
            {
                taken[i][j] = 1;
                tmp += board[i][j];
                make_word();
                taken[i][j] = 0;
                tmp.erase(tmp.size()-1,1);
            }
        }
    }
}

int play(int player)
{
    int i,j,k;
    for(i=0;i<words.size();i++)
    {

    }
}


int main()
{
    int i,j,n,t;
    char ch;
    string str;
    scanf("%d",&n);
    while(n--)
    {
        cin >> str;
        dic[str] = 1;
    }
    scanf("%d %d",&r,&c);
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<r;i++) board[i].clear();
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                scanf(" %c",&ch);
                board[i].push_back(ch);
            }
        }
        memset(taken,0,sizeof(taken));
        words.clear();
        wordmap.clear();
        tmp.erase();
        cnt = 0;
        make_word();

        printf("cnt = %d\n",cnt);
        for(i=0;i<words.size();i++) cout << words[i] << "\n";
    }

    return 0;
}
