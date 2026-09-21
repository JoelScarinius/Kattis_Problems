x = input()
y = input()

if int(x) > 0 and int(y) > 0:
    print(1)
elif int(x) < 0 and int(y) > 0:
    print(2)
elif int(x) < 0 and int(y) < 0:
    print(3)
elif int(x) > 0 and int(y) < 0:
    print(4)