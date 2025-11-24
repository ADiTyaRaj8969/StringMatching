# Implement the Aho–Corasick algorithm to search multiple patterns simultaneously in a given text.
from collections import deque, defaultdict

class TrieNode:
    def __init__(self):
        self.children = {}
        self.failure = None
        self.output = []

class AhoCorasick:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, pattern, index):
        node = self.root
        for c in pattern:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.output.append(index)

    def build_failure_links(self):
        queue = deque()
        self.root.failure = self.root
        for child in self.root.children.values():
            child.failure = self.root
            queue.append(child)

        while queue:
            node = queue.popleft()
            for c, child in node.children.items():
                fail = node.failure
                while fail != self.root and c not in fail.children:
                    fail = fail.failure
                if c in fail.children:
                    fail = fail.children[c]
                child.failure = fail
                child.output += fail.output
                queue.append(child)

    def search(self, text, patterns):
        node = self.root
        for i, c in enumerate(text):
            while node != self.root and c not in node.children:
                node = node.failure
            if c in node.children:
                node = node.children[c]
            for idx in node.output:
                print(f'Pattern "{patterns[idx]}" found at index {i - len(patterns[idx]) + 1}')

# Example usage
patterns = ["he", "she", "his", "hers"]
text = "ushers"

ac = AhoCorasick()
for i, p in enumerate(patterns):
    ac.insert(p, i)
ac.build_failure_links()
ac.search(text, patterns)

"""
Time Complexity (TC): O(N + Σ|Pi| + K)
- N = length of text
- Σ|Pi| = total length of all patterns
- K = total number of matches found
Space Complexity (SC): O(Σ|Pi| * alphabet_size) due to Trie nodes
"""
