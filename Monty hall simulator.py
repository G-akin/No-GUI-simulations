import random
import time

wins = 0
#it = 1000
it=int(input("How many iterations with swapping would you like to simulate the monty hall problem for?"))
start_time = time.time()    
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
end_time = time.time()
time_taken = end_time-start_time

succesrate = wins/it
print("Iterations:",(it))
print("Wins when swapping: ",wins)
print("Wins when not swapping: ",(it-wins))
print("Winrate when swapping: ",succesrate*100,"%")
print("Winratee when not swapping: ",100-(succesrate*100),"%")
print("Time taken: ", time_taken,"seconds")
print("Rate: ", it/time_taken)
