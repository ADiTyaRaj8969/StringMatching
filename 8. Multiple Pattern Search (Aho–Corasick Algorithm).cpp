// Implement the Aho–Corasick algorithm to search multiple patterns simultaneously in a given text.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    TrieNode* failure = nullptr;
    vector<int> output;  // store indexes of patterns ending here
};

class AhoCorasick
{
   private:
    TrieNode* root;

   public:
    AhoCorasick() { root = new TrieNode(); }

    void insert(const string& pattern, int index)
    {
        TrieNode* node = root;
        for (char c : pattern)
        {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->output.push_back(index);
    }

    void buildFailureLinks()
    {
        queue<TrieNode*> q;
        root->failure = root;
        for (auto& p : root->children)
        {
            p.second->failure = root;
            q.push(p.second);
        }

        while (!q.empty())
        {
            TrieNode* curr = q.front();
            q.pop();
            for (auto& p : curr->children)
            {
                char c = p.first;
                TrieNode* child = p.second;

                TrieNode* fail = curr->failure;
                while (fail != root && !fail->children.count(c)) fail = fail->failure;
                if (fail->children.count(c))
                    fail = fail->children[c];

                child->failure = fail;

                // merge output
                child->output.insert(child->output.end(), fail->output.begin(), fail->output.end());

                q.push(child);
            }
        }
    }

    void search(const string& text, vector<string>& patterns)
    {
        TrieNode* node = root;
        for (int i = 0; i < text.size(); i++)
        {
            char c = text[i];
            while (node != root && !node->children.count(c)) node = node->failure;

            if (node->children.count(c))
                node = node->children[c];

            for (int idx : node->output)
                cout << "Pattern \"" << patterns[idx] << "\" found at index "
                     << i - patterns[idx].size() + 1 << endl;
        }
    }
};

int main()
{
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ushers";

    AhoCorasick ac;
    for (int i = 0; i < patterns.size(); i++) ac.insert(patterns[i], i);

    ac.buildFailureLinks();
    ac.search(text, patterns);

    return 0;
}

/*
Time Complexity (TC): O(N + Σ|Pi| + K)
- N = length of text
- Σ|Pi| = total length of all patterns
- K = total number of matches found
Space Complexity (SC): O(Σ|Pi| * alphabet_size) due to Trie nodes
*/
