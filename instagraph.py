n, m = map(int, input().split())

edges = set()
for i in range(m):
    u, v = map(int, input().split())
    edges.add((u,v))

cc = [0] * (n+1)

for (u,v) in edges:
    if (v,u) not in edges:
        cc[v] = cc[v]+1

m = 1
for (i,_) in enumerate(cc):
    if (cc[i] > cc[m]):
        m = i
print(f"{m} {cc[m]}")
