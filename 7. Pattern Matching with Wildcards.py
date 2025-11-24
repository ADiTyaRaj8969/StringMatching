# Implement string pattern matching that supports wildcards ? (single char) and * (multiple chars).
def is_match(text, pattern):
    n, m = len(text), len(pattern)
    dp = [[False] * (m + 1) for _ in range(n + 1)]
    dp[0][0] = True  # empty pattern matches empty text

    # Handle patterns starting with *
    for j in range(1, m + 1):
        if pattern[j - 1] == '*':
            dp[0][j] = dp[0][j - 1]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if pattern[j - 1] == '?' or pattern[j - 1] == text[i - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            elif pattern[j - 1] == '*':
                dp[i][j] = dp[i][j - 1] or dp[i - 1][j]

    return dp[n][m]

# Example usage
text = "hello_world"
pattern = "he*o?world"
print("Pattern matches the text!" if is_match(text, pattern) else "Pattern does not match.")

"""
Time Complexity (TC): O(N*M) where N = text length, M = pattern length
Space Complexity (SC): O(N*M) due to DP table
"""
