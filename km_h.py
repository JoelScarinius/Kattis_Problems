n = int(input())

max_speed = 10

for i in range(n):
    speed = input()

    if speed != "/":
        print(speed)
        max_speed = max(int(speed), max_speed)
    else:
        # 10*(m//10 +1)
        print(max_speed + 10 - (max_speed % 10) )
