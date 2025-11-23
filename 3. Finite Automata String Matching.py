# Construct a finite automaton for a given pattern and use it to find matches in a text.
# Finite Automata String Matching Algorithm
# Time Complexity:
#   Preprocessing (Building TF): O(m * NO_OF_CHARS)
#   Searching: O(n)
#   Overall: O(m * NO_OF_CHARS + n)
# Space Complexity: O(m * NO_OF_CHARS)

NO_OF_CHARS = 256

def compute_transition_function(pattern):
    m = len(pattern)
    TF = [[0] * NO_OF_CHARS for _ in range(m + 1)]

    for state in range(m + 1):
        for x in range(NO_OF_CHARS):
            next_state = 0
            if state < m and x == ord(pattern[state]):
                next_state = state + 1
            else:
                for ns in range(state, 0, -1):
                    if ord(pattern[ns - 1]) == x:
                        if pattern[:ns - 1] == pattern[state - ns + 1:state]:
                            next_state = ns
                            break
            TF[state][x] = next_state
    return TF


def finite_automata_search(text, pattern):
    n = len(text)
    m = len(pattern)
    TF = compute_transition_function(pattern)

    state = 0
    found = False

    for i in range(n):
        state = TF[state][ord(text[i])]
        if state == m:
            print(f"Pattern found at index {i - m + 1}")
            found = True

    if not found:
        print("Pattern not found.")


# Example usage
text = "AABAACAADAABAAABAA"
pattern = "AABA"
finite_automata_search(text, pattern)
