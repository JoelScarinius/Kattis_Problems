import sys

x, y, n = sys.stdin.readline().split(" ")

for i in range(1, int(n) + 1, 1):
    if i % int(x) == 0:
        if i % int(y) == 0:
            print("FizzBuzz")
        else:
            print("Fizz")
    elif i % int(y) == 0:
        print("Buzz")
    else:
        print(i)