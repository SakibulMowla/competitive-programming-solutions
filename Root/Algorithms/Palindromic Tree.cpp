//courtesy - http://adilet.org/blog/25-09-14/

#include <bits/stdc++.h>

using namespace std;

struct PalindromicTree {
    struct state {
        map <char, int> next;
        int len, link;
    };

    const int MAXLEN = 100000 + 10;
    string s;
    vector <state> tree;
    int sz;
    int last;

    ///For finding total number of palindromes
    vector <int> dp;
    ///For finding total number of palindromes

    /**
        node 1 is root with len = -1
        node 2 is root with len = 0
    **/
    PalindromicTree() {
        tree = vector <state> (MAXLEN);
        ///For finding total number of palindromes
        dp = vector <int> (MAXLEN, 0);
        ///For finding total number of palindromes
        sz = last = 2;
        tree[1].len = -1; tree[1].link = 1;
        tree[2].len = 0; tree[2].link = 1;
    }

    void buildTree(string& str) {
        s = str;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            Insert(i, s[i]);
        }

        ///total number of palindromes(Unique + Non-unique) = palindromes
        long long palindromes = 0;
        for (auto x: dp) palindromes += x;
        ///total number of unique palindromes is just the number of nodes in the tree except the 2 roots

        return;
    }

    /**
        returns true is a new palindromic substring is found adding new character c and false otherwise
    **/
    bool Insert(int pos, char c) {
        int cur = last, curlen = 0;

        while (true) {
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
                break;
            cur = tree[cur].link;
        }
        if (tree[cur].next[c]) {
            last = tree[cur].next[c];
            return false;
        }

        sz++;
        last = sz;
        tree[sz].len = tree[cur].len + 2;
        tree[cur].next[c] = sz;

        if (tree[sz].len == 1) {
            tree[sz].link = 2;
            ///For finding total number of palindromes
            dp[sz] = 1;
            ///For finding total number of palindromes
            return true;
        }

        while (true) {
            cur = tree[cur].link;
            curlen = tree[cur].len;
            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
                tree[sz].link = tree[cur].next[c];
                break;
            }
        }

        ///For finding total number of palindromes
        dp[sz] = 1 + dp[tree[sz].link];
        ///For finding total number of palindromes

        return true;
    }
};


int main() {

    return 0;
}
