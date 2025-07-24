import random

wins = 0
doors = ["m","g","n"]
it = int(input("How many iterations with swapping would you like to simulate the monty hall problem for?"))   

for i in range (1,it+1):
    random.shuffle(doors)
    opendoor = random.randint(0,2)
    guess = random.randint(0,2)
    
    for i in range(0,2):
        if opendoor == guess or doors[opendoor] == "m":
            opendoor += 1

        if opendoor > 2:
            opendoor = opendoor-3
  
    guess2 = 0

    for i in range(0,2):
        if guess2 == opendoor or guess2 == guess:
            guess2 += 1
        else:
            break

    if doors[guess2] == "m":
        wins = wins+1

succesrate = wins/it
print("Iterations: ",(it))
print("Wins when swapping: ",wins)
print("losses when not swapping :",(it-wins))
print("succesrate when swapping: ",succesrate*100,"%")
print("succesrate when not swapping:",100-(succesrate*100),"%")
