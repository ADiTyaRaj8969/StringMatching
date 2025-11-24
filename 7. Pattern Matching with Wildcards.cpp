// Implement string pattern matching that supports wildcards ? (single char) and * (multiple chars).
#include <bits/stdc++.h>
using namespace std;

// Function to check if pattern matches text (wildcards ? and *)
bool isMatch(const string& text, const string& pattern)
{
    int n = text.size(), m = pattern.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;  // empty pattern matches empty text

    // Handle patterns with *
    for (int j = 1; j <= m; j++)
    {
        if (pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j - 1] == '?' || pattern[j - 1] == text[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

int main()
{
    string text = "hello_world";
    string pattern = "he*o?world";

    if (isMatch(text, pattern))
        cout << "Pattern matches the text!" << endl;
    else
        cout << "Pattern does not match." << endl;

    return 0;
}

/*
Time Complexity (TC): O(N*M) where N = text length, M = pattern length
Space Complexity (SC): O(N*M) due to DP table
*/
