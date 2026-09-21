a_r = list(range(-999, 0, 1)) + list(range(1, 1000, 1))
b_r = list(range(999, 0, -1)) + list(range(-1, -1000, -1))
a = b = 0
sample = int(input())
if sample*2 > 999:
    a = a_r[(sample-1)*2]
    b = b_r[sample-1]
elif sample*2 < -999: 
    a = a_r[sample*2+1]
    b = b_r[(sample)]
else:
    a = a_r[sample*2]
    b = b_r[sample]
print(f"{a} {b}")

# c = int(input())

# if c == 0:
#     print(-999, 999)
# elif c == 1:
#     print(-998, 999)
# elif c == -1:
#     print(-999, 998)
# elif c > 0:
#     print(1, c - 1)
# else:
#     print(-1, c + 1)