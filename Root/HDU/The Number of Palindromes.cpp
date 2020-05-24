//courtesy - http://adilet.org/blog/25-09-14/

#include <bits/stdc++.h>

using namespace std;

struct PalindromicTree {
    const int MAXLEN = 100000 + 10;

    /**
        every node represents a palindrome
        len - the length of palindrome represented by current node
        next - transition from this node to other nodes by different characters
        link - node number of longest suffix palindrome of current node
    **/
    struct state {
        map <char, int> next;
        int len, link;
    };

    string s;
    vector <state> tree;
    int sz;
    int last;


    /**
        node 1 is root with len = -1
        node 2 is root with len = 0
    **/
    PalindromicTree() {
        tree = vector <state> (MAXLEN);
        sz = last = 2;
        tree[1].len = -1; tree[1].link = 1;
        tree[2].len = 0; tree[2].link = 1;
    }


    /**
        Tested Problem: NUMOFPAL(SPOJ), LPS (SPOJ)
    */
    void buildTree(string& str) {
        s = str;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            Insert(i, s[i]);
        }

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

        return true;
    }
};


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;

        PalindromicTree PT;
        PT.buildTree(s);

        cout << "Case #" << cs + 1 << ": " << PT.sz - 2 << endl;
    }

    return 0;
}
