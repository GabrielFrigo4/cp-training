import sys

def get_rules():
    rules = {}
    for _ in range(8):
        c1, c2, c3, c4 = sys.stdin.readline().strip()
        rules[(c1, c2, c3)] = c4
    return rules

def apply_rules(word, rules, n):
    """Apply rewriting rules to the word."""
    new_word = []
    for i in range(n):
        new_letter = rules[(word[(i - 2) % n], word[i], word[(i + 1) % n])]
        new_word.append(new_letter)
    return ''.join(new_word)

def get_lexicographically_smallest_cyclic_shift(word):
    """Find the lexicographically smallest cyclic shift of the word."""
    return min(word[i:] + word[:i] for i in range(len(word)))

def process_word(n, word, rules, s):
    """Efficiently compute the final transformed word after s steps."""
    seen = {}  # Stores index of first occurrence of each word
    sequence = []  # Stores sequence of transformations

    for step in range(s):
        if word in seen:  # Cycle detected
            cycle_start = seen[word]
            cycle_length = step - cycle_start
            remaining_steps = (s - step) % cycle_length
            return get_lexicographically_smallest_cyclic_shift(sequence[cycle_start + remaining_steps])

        seen[word] = step
        sequence.append(word)
        word = apply_rules(word, rules, n)

    return get_lexicographically_smallest_cyclic_shift(word)

def main():
    while True:
        line = sys.stdin.readline().strip()
        if not line:
            break

        n = int(line)  # Read word length
        word = sys.stdin.readline().strip()  # Read initial word
        rules = get_rules()  # Read rewriting rules
        s = int(sys.stdin.readline().strip())  # Read number of rewriting steps

        print(process_word(n, word, rules, s))

if __name__ == "__main__":
    main()
