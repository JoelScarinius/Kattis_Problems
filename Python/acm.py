import sys

tot_time = solved = 0
stats = {}

while (True):
    line = sys.stdin.readline()
    if "-1" == line.strip():
        print(f"{solved} {tot_time}")
        break
    else:
        time, problem, result = line.split(" ")
        if result.strip() == "wrong":
            stats[problem] = stats.get(problem, 0) + 1
        else:
            solved += 1
            tot_time += int(time) + 20*stats.get(problem, 0)
        