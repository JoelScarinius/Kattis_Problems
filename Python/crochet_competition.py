day_number = {
    "Mon": 0,
    "Tue": 1,
    "Wed": 2,
    "Thu": 3,
    "Fri": 4,
    "Sat": 5,
    "Sun": 6,
}

def to_minutes(s):
    day, time = s.split()
    h, m = map(int, time.split(":"))
    return day_number[day] * 1440 + h * 60 + m

start = to_minutes(input())
end = to_minutes(input())

duration = (end - start) % (7 * 24 * 60)

if duration == 0:
    duration = 7 * 24 * 60

days = duration // 1440
duration %= 1440

hours = duration // 60
minutes = duration % 60

parts = []

if days:
    parts.append(f"{days} day{'s' if days != 1 else ''}")

if hours:
    parts.append(f"{hours} hour{'s' if hours != 1 else ''}")

if minutes:
    parts.append(f"{minutes} minute{'s' if minutes != 1 else ''}")

if len(parts) == 1:
    print(parts[0])
elif len(parts) == 2:
    print(parts[0] + " and " + parts[1])
else:
    print(", ".join(parts))

# """
# Crochet Competition
# https://open.kattis.com/problems/crochetcompetition

# The National Crochet Pattern Competition (NCPC) is an annual team-based event for crocheters of all skill levels, from beginner to expert. Teams design, write, and crochet original patterns within a time limit, which can range from minutes to a full week depending on the complexity—sometimes spanning weekends. Contestants may take breaks to eat, sleep, or go home, but the timer continues running.

# NCPC has asked you to develop a system that calculates the total competition duration from the start and end times, provided with weekday, hour, and minute. The reported duration should be precise, correctly expressed in days, hours, and minutes, using as few components as necessary while minimizing the sum of the integer values.
# """

# """
# Input
# Input consists of two lines.

# The first line gives the competition’s start time.

# The second line gives the competition’s end time.

# Times are formatted as “Www HH:MM”, where

# Www is the three-letter weekday abbreviation: Mon, Tue, Wed, Thu, Fri, Sat, or Sun.

# HH the two-digit hour, from 
#  to 
# .

# MM is the two-digits minutes, from 
#  to 
# .

# If the start and end times are identical, the competition lasts exactly one week.

# Output
# Output the competition duration in days, hours, and minutes, using the singular or plural form as appropriate (e.g., 1 day, 2 days). List the components in order – days, hours, minutes – separating three components with commas and two with “and”; omit any component with a value of zero.

# Sample Input 1	Sample Output 1
# Mon 08:00
# Mon 15:00
# 7 hours
# Sample Input 2	Sample Output 2
# Mon 10:00
# Wed 08:59
# 1 day, 22 hours, 59 minutes
# Sample Input 3	Sample Output 3
# Fri 20:00
# Mon 08:00
# 2 days and 12 hours
# """
# import sys

# from datetime import datetime, timedelta

# day_number = {
#     "Mon": 0,
#     "Tue": 1,
#     "Wed": 2,
#     "Thu": 3,
#     "Fri": 4,
#     "Sat": 5,
#     "Sun": 6,
# }

# def parse_time(s):
#     day, time = s.split()
#     # print("Time:", time[:2])
#     # print("Time:", time[3:])
#     return datetime(2000, 1, 3) + timedelta(
#         days=day_number[day],
#         hours=int(time[:2]),
#         minutes=int(time[3:])
#     )

# def to_minutes(s):
#     day, time = s.split()
#     h, m = map(int, time.split(":"))
#     return day_number[day] * 1440 + h * 60 + m



# def main():
#     # start = parse_time("Mon 08:00")
#     # end = parse_time("Mon 15:00")
#     # # start = parse_time("Mon 10:00")
#     # # end = parse_time("Wed 08:59")
#     # # start = parse_time("Fri 20:00")
#     # # end = parse_time("Mon 08:00")
#     # # start = parse_time("Wed 15:00")
#     # # end = parse_time("Wed 15:00")
#     # # start = parse_time(input())
#     # # end = parse_time(input())
#     # if end == start:
#     #     print("7 days")
#     # else:
#     #     duration = end - start
#     #     hours = duration.seconds // 3600
#     #     if end.day - start.day < 0:
#     #         days = start.day - end.day - (1 if hours == 0 else 2)
#     #     else:
#     #         days = duration.days            
#     #     output = ""
#     #     if duration.seconds % 3600 == 0:
#     #         minutes = 0
#     #     else:
#     #         minutes = duration.seconds // 60 - hours * 60

#     #     if days > 0 and hours > 0 and minutes > 0:
#     #         # all
#     #         output += "1 day, " if days == 1 else  str(days) + " days, "
#     #         output += "1 hour, " if hours == 1 else  str(hours) + " hours, "
#     #         output += "1 minute, " if minutes == 1 else  str(minutes) + " minutes, "
#     #     elif (days > 0 and hours > 0) or (days > 0 and minutes > 0) or (hours > 0 and minutes > 0):
#     #         # "double"
#     #         if days == 0:
#     #             output += "1 hour and " if hours == 1 else  str(hours) + " hours and "
#     #             output += "1 minute" if minutes == 1 else  str(minutes) + " minutes"
#     #         elif hours == 0:
#     #             output += "1 day and " if days == 1 else  str(days) + " days and "
#     #             output += "1 minute" if minutes == 1 else  str(minutes) + " minutes"
#     #         else:
#     #             output += "1 day and " if days == 1 else  str(days) + " days and "
#     #             output += "1 hour" if hours == 1 else  str(hours) + " hours"
#     #     else:
#     #         #  'single'
#     #         if hours + minutes == 0:
#     #             output += "1 day" if days == 1 else  str(days) + " days"
#     #         elif minutes + days == 0:
#     #             output += "1 hour" if hours == 1 else  str(hours) + " hours"
#     #         else:
#     #             output += "1 minute" if minutes == 1 else  str(minutes) + " minutes"

#     #     print(output)

#     start = to_minutes("Mon 08:00")
#     end = to_minutes("Mon 15:00")
#     start = to_minutes("Mon 10:00")
#     end = to_minutes("Wed 08:59")
#     start = to_minutes("Fri 20:00")
#     end = to_minutes("Mon 08:00")
#     start = to_minutes("Wed 15:00")
#     end = to_minutes("Wed 15:00")
#     # start = to_minutes(input())
#     # end = to_minutes(input())

#     duration = (end - start) % (7 * 24 * 60)

#     if duration == 0:
#         duration = 7 * 24 * 60

#     days = duration // 1440
#     duration %= 1440

#     hours = duration // 60
#     minutes = duration % 60

#     parts = []

#     if days:
#         parts.append(f"{days} day{'s' if days != 1 else ''}")

#     if hours:
#         parts.append(f"{hours} hour{'s' if hours != 1 else ''}")

#     if minutes:
#         parts.append(f"{minutes} minute{'s' if minutes != 1 else ''}")

#     if len(parts) == 1:
#         print(parts[0])
#     elif len(parts) == 2:
#         print(parts[0] + " and " + parts[1])
#     else:
#         print(", ".join(parts))


# if __name__ == "__main__":
#     main()