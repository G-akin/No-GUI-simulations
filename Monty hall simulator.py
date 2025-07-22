import random
import time


def runtime(start_time):
    global it
    current_time = time.time()
    dt = (current_time - start_time)
    print("Time taken:",dt,"seconds")
    print("Rate:",(dt/it)**-1,"Per second")

wins = 0
#it = 1000
it=int(input("How many iterations with swapping would you like to simulate the monty hall problem for?"))
global_start_time = time.time()    
for i in range (1,it+1):
    #print("iteration:",i)
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
    #succesrate = wins/i
    #print("succesrate:",succesrate)
succesrate = wins/it
print("Iterations:",(it))
print("Wins",wins)
print("losses:",(it-wins))
print("succesrate:",succesrate*100,"%")
runtime(global_start_time)
