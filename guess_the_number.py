low = 1
high = 1000

while True:
    guess = (low + high) // 2
    print(guess)

    response = input()

    if response == "correct":
        break
    elif response == "lower":
        high = guess - 1
    elif response == "higher":
        low = guess + 1