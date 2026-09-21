n, m = map(int, input().split())

# reachable[a][b] = True if a can eventually become b
reachable = [[False] * 26 for _ in range(26)]

# Zero translations: every letter can become itself
for i in range(26):
    reachable[i][i] = True

# Direct translations
for _ in range(n):
    a, b = input().split()
    a = ord(a) - ord('a')
    b = ord(b) - ord('a')
    reachable[a][b] = True

# Transitive closure
for k in range(26):
    for i in range(26):
        for j in range(26):
            if reachable[i][k] and reachable[k][j]:
                reachable[i][j] = True

# Check word pairs
for _ in range(m):
    word1, word2 = input().split()

    if len(word1) != len(word2):
        print("no")
        continue

    matches = True

    for a, b in zip(word1, word2):
        a = ord(a) - ord('a')
        b = ord(b) - ord('a')

        if not reachable[a][b]:
            matches = False
            break

    print("yes" if matches else "no")