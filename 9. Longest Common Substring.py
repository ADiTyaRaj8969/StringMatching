# Write a program to find the longest common substring between two strings using dynamic programming.
def longest_common_substring(s1, s2):
    n, m = len(s1), len(s2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    max_len = 0
    end_index = 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > max_len:
                    max_len = dp[i][j]
                    end_index = i - 1
    return s1[end_index - max_len + 1:end_index + 1]

# Example usage
s1 = "abcdef"
s2 = "zabcf"
lcs = longest_common_substring(s1, s2)
print("Longest Common Substring:", lcs)

"""
Time Complexity (TC): O(N*M) where N = length of s1, M = length of s2
Space Complexity (SC): O(N*M) due to DP table
"""
