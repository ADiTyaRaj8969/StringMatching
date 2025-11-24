// Write a program to find the longest common substring between two strings using dynamic
// programming.
#include <bits/stdc++.h>
using namespace std;

string longestCommonSubstring(const string& s1, const string& s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0, endIndex = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    return s1.substr(endIndex - maxLength + 1, maxLength);
}

int main()
{
    string s1 = "abcdef";
    string s2 = "zabcf";
    string lcs = longestCommonSubstring(s1, s2);
    cout << "Longest Common Substring: " << lcs << endl;
    return 0;
}

/*
Time Complexity (TC): O(N*M) where N = length of s1, M = length of s2
Space Complexity (SC): O(N*M) due to DP table
*/
