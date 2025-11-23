// Construct a finite automaton for a given pattern and use it to find matches in a text.
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// Finite Automata String Matching Algorithm
// Time Complexity:
//   Preprocessing (Building TF): O(m * NO_OF_CHARS)
//   Searching: O(n)
//   Overall: O(m * NO_OF_CHARS + n)
// Space Complexity: O(m * NO_OF_CHARS)

void computeTransitionFunction(string pattern, vector<vector<int>>& TF)
{
    int m = pattern.size();
    for (int state = 0; state <= m; state++)
    {
        for (int x = 0; x < NO_OF_CHARS; x++)
        {
            int nextState = 0;
            if (state < m && x == pattern[state])
                nextState = state + 1;
            else
            {
                for (int ns = state; ns > 0; ns--)
                {
                    if (pattern[ns - 1] == x)
                    {
                        int i;
                        for (i = 0; i < ns - 1; i++)
                            if (pattern[i] != pattern[state - ns + 1 + i])
                                break;
                        if (i == ns - 1)
                            nextState = ns;
                    }
                }
            }
            TF[state][x] = nextState;
        }
    }
}

void finiteAutomataSearch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<vector<int>> TF(m + 1, vector<int>(NO_OF_CHARS));
    computeTransitionFunction(pattern, TF);

    int state = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        state = TF[state][(int)text[i]];
        if (state == m)
        {
            cout << "Pattern found at index " << i - m + 1 << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found." << endl;
}

int main()
{
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    finiteAutomataSearch(text, pattern);
    return 0;
}
