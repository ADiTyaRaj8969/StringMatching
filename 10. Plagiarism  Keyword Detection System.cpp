// Create a program that reads a text file and identifies the positions of multiple keywords using
// Rabin–Karp or KMP.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll BASE = 256;  // number of characters

ll computeHash(const string& s)
{
    ll hash_val = 0;
    for (char c : s)
    {
        hash_val = (hash_val * BASE + c) % MOD;
    }
    return hash_val;
}

vector<int> rabinKarpSearch(const string& text, const string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> positions;

    if (m > n)
        return positions;

    ll patternHash = computeHash(pattern);
    ll textHash = computeHash(text.substr(0, m));

    ll power = 1;
    for (int i = 0; i < m - 1; i++) power = (power * BASE) % MOD;

    for (int i = 0; i <= n - m; i++)
    {
        if (textHash == patternHash && text.substr(i, m) == pattern)
        {
            positions.push_back(i);
        }
        if (i < n - m)
        {
            textHash = (textHash - text[i] * power % MOD + MOD) % MOD;
            textHash = (textHash * BASE + text[i + m]) % MOD;
        }
    }
    return positions;
}

int main()
{
    ifstream file("input.txt");
    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    vector<string> keywords = {"apple", "banana", "cherry"};

    for (auto& keyword : keywords)
    {
        vector<int> positions = rabinKarpSearch(text, keyword);
        cout << "Keyword \"" << keyword << "\" found at positions: ";
        for (int pos : positions) cout << pos << " ";
        cout << endl;
    }

    return 0;
}

/*
Time Complexity (TC): O(N*M) worst case for N = text length, M = keyword length (hash collisions
possible) Space Complexity (SC): O(1) extra space for rolling hash
*/
