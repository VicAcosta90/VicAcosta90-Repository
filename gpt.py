import random

secret_number = random.randint(1, 100)
guess = None
attempts = 0

while guess != secret_number:
    guess = int(input("What's your guess? "))
    attempts +=1
    
    if guess < secret_number:
        print("It's higher!")
    elif guess > secret_number:
        print("It's lower!")
    else:
        print(f"Congratulations! The number is {secret_number}!")
        print(f"You reached it in {attempts} attempts!")