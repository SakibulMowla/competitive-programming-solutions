//
//  main.cpp
//  Works Application Exam#4
//
//  Created by Kaidul Islam on 15/2/17.
//  Copyright © 2017 Kaidul Islam. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int64;

const int MAX = 100001;
const int BIT_TYPE = 2;
const int MSB = 41;
int n;
int64 arr[MAX];
int64 suffix[MAX];
int64 prefix[MAX];

class Trie {
    struct trieNode {
        trieNode* children[BIT_TYPE];
        trieNode() {
            for(int i = 0; i < BIT_TYPE; i++) {
                children[i] = nullptr;
            }
        }
        ~trieNode() {
            for(int i = 0; i < BIT_TYPE; i++) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    };
    trieNode* root;

public:
    Trie(): root(new trieNode()) {
    }

    ~Trie() {
        delete root;
        root = nullptr;
    }

    void insert(int64 key) {
        trieNode* pCrawl = root;
        for(int i = MSB; i >= 0; i--) {
            int bit = (bool)(key & (1LL << i));
            if(!pCrawl->children[bit]) {
                pCrawl->children[bit] = new trieNode();
            }
            pCrawl = pCrawl->children[bit];
        }
    }

    int64 query(int64 key) {
        int64 Xor = 0LL;
        trieNode* pCrawl = root;
        for(int i = MSB; i >= 0; i--) {
            int bit = (bool)(key & (1LL << i));
            if(pCrawl->children[bit ^ 1]) {
                Xor |= (1LL << i);
                pCrawl = pCrawl->children[bit ^ 1];
            } else {
                pCrawl = pCrawl->children[bit];
            }
        }
        return Xor;
    }
};

int main(void) {
//#ifndef ONLINE_JUDGE
//#endif
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    while (scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }
        prefix[0] = arr[0];
        suffix[n - 1] = arr[n - 1];
        int64 result = prefix[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
            suffix[n - i - 1] = suffix[n - i] ^ arr[n - i - 1];
            result = max(result, prefix[i]);
        }

        Trie* trie = new Trie();
        trie->insert(0LL);
        result = trie->query(0);
        for(int i = n - 1; i >= 0; i--) {
            result = max(result, trie->query(prefix[i]));
            trie->insert(suffix[i]);
        }
        printf("%lld\n", result);
    }
    //    delete trie;
    return 0;
}
