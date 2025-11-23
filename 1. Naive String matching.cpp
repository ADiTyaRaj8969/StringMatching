// Implement the naive string matching algorithm to find all occurrences of a pattern in a given
// text.
#include <bits/stdc++.h>
using namespace std;

// Naive String Matching Algorithm
// Time Complexity:
//   Best Case: O(n)
//   Worst Case: O(n * m)
//   Average Case: O(n * m)
// Space Complexity: O(1)

void naiveStringMatch(const string& text, const string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    bool found = false;

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found." << endl;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    naiveStringMatch(text, pattern);
    return 0;
}
