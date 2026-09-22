"""
Many ways to do this, I can use counter and count occurencies of revert, I can create my own simple counter or using regular expressions for finding patterns and count occurencies.
"""

import sys
# from collections import Counter
# import re

text = sys.stdin.readline().strip().split("\"")

# counter = Counter(text)

counter = 0
for i in text:
    if i == "Revert ":
        counter += 1
    else:
        break

print("revert" if counter % 2 != 0 else "unrevert")

# import re
# import sys

# print("revert" if len(re.findall(r'\bRevert\b', sys.stdin.readline())) % 2 != 0 else "unrevert")


# another way to solve it
# s = input()
# reverts = 0

# while s.startswith('Revert "'):
#     reverts += 1
#     s = s[8:-1]

# print("revert" if reverts % 2 else "unrevert")