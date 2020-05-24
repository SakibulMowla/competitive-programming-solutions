#include <bits/stdc++.h>

using namespace std;

struct data {
    int child[26];
    data () {
        memset(child, -1, sizeof child);
    }
};

vector <data> trie;
int nodes;

void addWord (string &s) {
    int now = 0;
    for (auto &c: s) {
        if (trie[now].child[c-'a'] == -1) {
            trie.push_back(data());
            trie[now].child[c-'a'] = nodes++;
        }
        now = trie[now].child[c-'a'];
    }
    return;
}

bool solveWin (int pos, int player) {
    bool ret = (player == 0)? false: true;

    for (int i = 0; i < 26; i++) {
        if (trie[pos].child[i] != -1) {
            bool tmp = solveWin(trie[pos].child[i], player^1);
            if ((player == 0 and tmp == true) or (player == 1 and tmp == false)) {
                ret = !ret;
                break;
            }
        }
    }

    return ret;
}

bool solveLoss (int pos, int player) {
    bool ret = (player == 0)? true: false;
    bool enter = false;

    for (int i = 0; i < 26; i++) {
        if (trie[pos].child[i] != -1) {
            enter = true;
            bool tmp = solveLoss(trie[pos].child[i], player^1);
            if ((player == 0 and tmp == false) or (player == 1 and tmp == true)) {
                ret = !ret;
                break;
            }
        }
    }

    if (!enter) ret = !ret;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    trie.push_back(data());
    nodes = 1;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        addWord(s);
    }

    bool winPossible = solveWin(0, 0);
    bool LossPossible = !solveLoss(0, 0);

    if (!winPossible) {
        cout << "Second" << endl;
    } else if (winPossible and LossPossible) {
        cout << "First" << endl;
    } else {
        if (k & 1) cout << "First" << endl;
        else cout << "Second" << endl;
    }

    return 0;
}

