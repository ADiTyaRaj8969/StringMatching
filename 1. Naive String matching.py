# Implement the naive string matching algorithm to find all occurrences of a pattern in a given text.
# Naive String Matching Algorithm
# Time Complexity:
#   Best Case: O(n)
#   Worst Case: O(n * m)
#   Average Case: O(n * m)
# Space Complexity: O(1)

def naive_string_match(text, pattern):
    n = len(text)
    m = len(pattern)
    found = False

    for i in range(n - m + 1):
        j = 0
        while j < m and text[i + j] == pattern[j]:
            j += 1
        if j == m:
            print(f"Pattern found at index {i}")
            found = True

    if not found:
        print("Pattern not found.")


# Example usage
text = "ABABDABACDABABCABAB"
pattern = "ABABCABAB"
naive_string_match(text, pattern)
