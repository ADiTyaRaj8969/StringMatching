# Implement the Boyer–Moore string matching algorithm using the bad character rule.
# Boyer–Moore Algorithm (Bad Character Heuristic)
# Time Complexity:
#   Best Case: O(n/m)
#   Average Case: O(n)
#   Worst Case: O(m * n)
# Space Complexity: O(NO_OF_CHARS)

NO_OF_CHARS = 256

def bad_char_heuristic(pattern):
    bad_char = [-1] * NO_OF_CHARS
    for i, ch in enumerate(pattern):
        bad_char[ord(ch)] = i
    return bad_char


def boyer_moore_search(text, pattern):
    n = len(text)
    m = len(pattern)
    bad_char = bad_char_heuristic(pattern)

    s = 0  # shift of the pattern
    found = False

    while s <= n - m:
        j = m - 1

        # Compare characters from end of pattern
        while j >= 0 and pattern[j] == text[s + j]:
            j -= 1

        if j < 0:
            print(f"Pattern found at index {s}")
            found = True
            s += (m - bad_char[ord(text[s + m])] if s + m < n else 1)
        else:
            s += max(1, j - bad_char[ord(text[s + j])])

    if not found:
        print("Pattern not found.")


# Example usage
text = "ABAAABCD"
pattern = "ABC"
boyer_moore_search(text, pattern)
