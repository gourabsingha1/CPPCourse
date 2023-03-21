#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        TrieNode* links[26];
        bool flag = 0;

        // if trie doesn't contain character, put it
        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;
        }

        void put(char ch, TrieNode* node) {
            links[ch - 'a'] = node;
        }

        TrieNode* get(char ch) {
            return links[ch - 'a'];
        }

        // last character of a word
        void setEnd() {
            flag = 1;
        }

        // check if word is found
        bool isEnd() {
            return flag;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            // moves to the reference trie
            node = node->get(word[i]);
        }
        // last reference trie
        node->setEnd();
    }

    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if(!node->containsKey(prefix[i])) {
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return 1;
    }
};