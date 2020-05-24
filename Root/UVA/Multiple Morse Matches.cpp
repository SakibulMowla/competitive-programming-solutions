#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace  std;


#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ 10010

char morse[26][5] =
{
    ".-","-...","-.-.","-..",".","..-.","--.","....",".."
    ,".---","-.-",".-..","--","-.","---",".--.","--.-",".-."
    ,"...","-","..-","...-",".--","-..-","-.--","--.."
};

char arr[SZ];
map <string , int> mp;

//void init(){
//    morse[0] = ".-";morse[1] = "-...";morse[2] = "-.-.";morse[3] = "-..";morse[4] = ".";morse[5] = "..-.";
//    morse[6] = "--.";morse[7] = "....";morse[8] = "..";morse[9] = ".---";morse[10] = "-.-";morse[11] = ".-..";
//    morse[12] = "--";morse[13] = "-.";morse[14] = "---";morse[15] = ".--.";morse[16] = "--.-";morse[17] = ".-.";
//    morse[18] = "...";morse[19] = "-";morse[20] = "..-";morse[21] = "...-";morse[22] = ".--";morse[23] = "-..-";
//    morse[24] = "-.--";morse[25] = "--..";
//}

int len;
int dp[SZ];

int solve(int indx){
    if(indx == len) return 1;
    int &ret = dp[indx];
    if(ret != -1) return ret;

    ret = 0;
    int i;
    char s[81];

    for(i=0;i<80 && indx+i<len;i++){
        s[i] = arr[i+indx];
        s[i+1] = '\0';
        if(mp.find(s) != mp.end()) ret += mp[s] * solve(indx+i+1);
    }

    return ret;
}

int main() {
//    init();

    int t, i, n, j, k;
    char s[25];
    char word[81];

    scanf("%d",&t);

    while(t--){
        scanf("%s",arr);
        scanf("%d",&n);
        clr(mp);

        REP(i, n){
            scanf("%s",s);
            k = strlen(s);
            word[0] = '\0';
            REP(j, k) strcat(word, morse[ s[j]-'A' ]);
            mp[word]++;
        }

        len = strlen(arr);
        REP1(i, 0, len) dp[i] = -1;

        printf("%d\n",solve(0));
        if(t) puts("");
    }


    return 0;
}












