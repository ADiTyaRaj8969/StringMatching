# Create a program that reads a text file and identifies the positions of multiple keywords using Rabin–Karp or KMP.

def compute_hash(s, base=256, mod=10**9+7):
    h = 0
    for c in s:
        h = (h * base + ord(c)) % mod
    return h

def rabin_karp_search(text, pattern):
    n, m = len(text), len(pattern)
    positions = []

    if m > n:
        return positions

    pattern_hash = compute_hash(pattern)
    text_hash = compute_hash(text[:m])
    power = pow(256, m-1, 10**9+7)

    for i in range(n - m + 1):
        if text_hash == pattern_hash and text[i:i+m] == pattern:
            positions.append(i)
        if i < n - m:
            text_hash = (text_hash - ord(text[i]) * power) % 10**9+7
            text_hash = (text_hash * 256 + ord(text[i + m])) % 10**9+7
    return positions

# Read file
with open("input.txt", "r") as f:
    text = f.read()

keywords = ["apple", "banana", "cherry"]

for keyword in keywords:
    positions = rabin_karp_search(text, keyword)
    print(f'Keyword "{keyword}" found at positions: {positions}')

"""
Time Complexity (TC): O(N*M) worst case due to hash collisions, N = text length, M = pattern length
Space Complexity (SC): O(1) extra space for rolling hash
"""
