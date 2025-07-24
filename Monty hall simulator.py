import random

wins = 0
it=int(input("How many iterations with swapping would you like to simulate the monty hall problem for?"))   

for i in range (1,it+1):
    doors = ["m","g","n"]
    random.shuffle(doors)
    otherside = list.copy(doors)
    guess=random.randint(0,2)
    otherside.pop(guess)
    if doors[guess]!="m":
        otherside.remove("m")
 
    #presenter
    nextglist = list.copy(doors)    
    nextglist.pop(guess)    
    nextglist.remove(otherside[0])
    guess2 = nextglist[0]
    if guess2 == "m":
        wins = wins+1

succesrate = wins/it
print("Iterations:",(it))
print("Wins",wins)
print("losses:",(it-wins))
print("succesrate when swapping:",succesrate*100,"%")
print("succesrate when not swapping:",100-(succesrate*100),"%")
