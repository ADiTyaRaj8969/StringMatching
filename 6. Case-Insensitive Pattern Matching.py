# Modify an existing string matching algorithm to perform case-insensitive pattern search.
def search_pattern(text, pattern):
    txt = text.lower()
    pat = pattern.lower()

    n = len(txt)
    m = len(pat)

    for i in range(n - m + 1):
        j = 0
        while j < m:
            if txt[i + j] != pat[j]:
                break
            j += 1
        if j == m:
            print(f"Pattern found at index {i}")

# Example usage
text = "Hello World, HELLO Universe!"
pattern = "hello"
search_pattern(text, pattern)

"""
Time Complexity (TC): O((N-M+1)*M) where N = length of text, M = length of pattern
Space Complexity (SC): O(N+M) due to lowercase conversion of text and pattern
"""
