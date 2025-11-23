// Implement the Rabin–Karp algorithm using rolling hash to match a pattern in a text efficiently.
#include <bits/stdc++.h>
using namespace std;

// Rabin–Karp Algorithm
// Time Complexity:
//   Best Case: O(n + m)
//   Average Case: O(n + m)
//   Worst Case: O(n * m)  // when hash collisions occur frequently
// Space Complexity: O(1)

#define d 256  // number of characters in the input alphabet
#define q 101  // a prime number for modulo

void rabinKarp(const string& text, const string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text window
    int h = 1;
    bool found = false;

    // Precompute h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++) h = (h * d) % q;

    // Calculate initial hash values
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at index " << i << endl;
                found = true;
            }
        }

        // Recalculate hash for next window
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }

    if (!found)
        cout << "Pattern not found." << endl;
}

int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    rabinKarp(text, pattern);
    return 0;
}
