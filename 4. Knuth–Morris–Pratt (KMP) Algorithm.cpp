// Implement the KMP algorithm using the prefix (LPS) array and display the matching indices.
#include <bits/stdc++.h>
using namespace std;

// KMP (Knuth–Morris–Pratt) Algorithm
// Time Complexity:
//   Preprocessing (LPS computation): O(m)
//   Searching: O(n)
//   Overall: O(n + m)
// Space Complexity: O(m)

void computeLPSArray(const string& pattern, vector<int>& lps)
{
    int m = pattern.size();
    int len = 0;  // length of previous longest prefix suffix
    lps[0] = 0;

    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(const string& text, const string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0, j = 0;  // index for text, pattern
    bool found = false;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found." << endl;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPsearch(text, pattern);
    return 0;
}
