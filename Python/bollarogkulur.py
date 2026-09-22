cups = [1, 0, 0]

for i in range(5):
  j = int(input())
  k = int(input())

  prev = cups[k-1]
  cups[k-1] = cups[j-1]
  cups[j-1] = prev

max_val = max(cups)

print(cups.index(max_val)+1)