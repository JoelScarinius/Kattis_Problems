n = int(input())

lectures = list(map(int, input()))

coffees = 0
for i in lectures:
    if i == 0 and coffees > 0:
        coffees -= 1
    elif i == 0:
        n -= 1
    else:
        coffees = 2
print(n)