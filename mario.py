from cs50 import get_int


while True:
    h = get_int("Height: ")  # Gets input from user
    if h < 9 and h > 0:
        break

for i in range(1, h + 1):
    for j in range(0, h - i):
        print(" ", end="")  # Prints the spaces
        j += j
    for k in range(0, i):
        print("#", end="")  # Prints the hashes
        k += k

    print("")
    i += i
