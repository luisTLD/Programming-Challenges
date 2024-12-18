# Boyer-Moore Algorithm

The Boyer-Moore algorithm is an efficient string searching (or pattern matching) algorithm used to find occurrences of a substring (pattern) within a larger text.

## How It Works

Boyer-Moore uses two key techniques for efficient searching:
1. **Bad Character**: Skips past characters in the text that don’t match the pattern.
2. **Good Suffix**: Skips past sections of the pattern that have already been matched.

These heuristics allow the algorithm to skip over parts of the text, making it faster than other simple string search algorithms.

- Finds all occurrences of a pattern in a given text.
- Returns a list of indices where the pattern occurs.
