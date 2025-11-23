# Implement the Rabin–Karp algorithm using rolling hash to match a pattern in a text efficiently.
# Rabin–Karp Algorithm
# Time Complexity:
#   Best Case: O(n + m)
#   Average Case: O(n + m)
#   Worst Case: O(n * m)  # occurs if many hash collisions
# Space Complexity: O(1)

def rabin_karp(text, pattern, d=256, q=101):
    n = len(text)
    m = len(pattern)
    p = 0  # hash value for pattern
    t = 0  # hash value for text window
    h = 1
    found = False

    # Precompute h = pow(d, m-1) % q
    for _ in range(m - 1):
        h = (h * d) % q

    # Calculate initial hash values
    for i in range(m):
        p = (d * p + ord(pattern[i])) % q
        t = (d * t + ord(text[i])) % q

    # Slide the pattern over text
    for i in range(n - m + 1):
        if p == t:
            if text[i:i + m] == pattern:
                print(f"Pattern found at index {i}")
                found = True

        # Recalculate hash for next window
        if i < n - m:
            t = (d * (t - ord(text[i]) * h) + ord(text[i + m])) % q
            if t < 0:
                t += q

    if not found:
        print("Pattern not found.")


# Example usage
text = "ABCCDDAEFG"
pattern = "CDD"
rabin_karp(text, pattern)
