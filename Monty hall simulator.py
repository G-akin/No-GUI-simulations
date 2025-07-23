import random
itternum=int(input("Input the number of itterations to execute the monty hall problem over?"))
wins=0
guess=0
doors=["m","g","n"]

for i in range (1,itternum):
    guess=random.randint(0,2)
    random.shuffle(doors)
    if doors[guess]=="m":
        wins+=1

print("Itterations: ", itternum)
print("Wins: ",wins)
print("Losses: ", itternum - wins)
print("Winrate: ", 100*(wins/itternum),"%")
