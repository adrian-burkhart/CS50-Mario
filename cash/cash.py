from cs50 import get_float

while True:
    input = get_float("Change owed: ")
    if input > 0:
        break

input = input * 100
change = int(input)

coins = round((change - change % 25) / 25)  # Quarters
change = change % 25
coins = round(coins + (change - change % 10) / 10)  # Dimes
change = round(change % 10)
coins = round(coins + (change - change % 5) / 5)  # Nickels
change = change % 5
coins = round(coins + change / 1)  # Pennies

print(f"{coins}")