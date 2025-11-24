// Implement the Boyer–Moore string matching algorithm using the bad character rule.
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// Boyer–Moore Algorithm (Bad Character Heuristic)
// Time Complexity:
//   Best Case: O(n/m)
//   Average Case: O(n)
//   Worst Case: O(m * n)  // when pattern and text have repeated characters
// Space Complexity: O(NO_OF_CHARS)

void badCharHeuristic(string pattern, int m, vector<int>& badChar)
{
    for (int i = 0; i < NO_OF_CHARS; i++) badChar[i] = -1;

    for (int i = 0; i < m; i++) badChar[(int)pattern[i]] = i;
}

void boyerMooreSearch(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> badChar(NO_OF_CHARS);

    badCharHeuristic(pattern, m, badChar);

    int s = 0;  // s = shift of the pattern with respect to text
    bool found = false;

    while (s <= (n - m))
    {
        int j = m - 1;

        // Move backward through pattern
        while (j >= 0 && pattern[j] == text[s + j]) j--;

        if (j < 0)
        {
            cout << "Pattern found at index " << s << endl;
            found = true;

            // Shift pattern
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    if (!found)
        cout << "Pattern not found." << endl;
}

int main()
{
    string text = "ABAAABCD";
    string pattern = "ABC";
    boyerMooreSearch(text, pattern);
    return 0;
}
