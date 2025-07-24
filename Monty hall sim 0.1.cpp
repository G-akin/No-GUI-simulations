//Monty hall sim in C++
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

int randint(int min, int max){
   static std::random_device rd;      
    static std::mt19937 gen(rd());     
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main(){   
    int dummyvar;
    int opendoor;
    int guess;
    int wins = 0;
    int itternum;
    int guess1;

    string doors[3] = {"m","g","n"};
    int indexes[3] = {0,1,2};

    cout <<"How many iterations with swapping would you like to simulate the monty hall problem for?"<<endl;
    cin >> itternum;

    int size = sizeof(doors) / sizeof(doors[0]);
    for (int i = 0; i < itternum ; i++) {

        random_shuffle(&doors[0],&doors[3]);

        guess1 = randint(0,2);
        opendoor = randint(0,2);

        if (doors[opendoor] == "m"){
            opendoor = opendoor + (randint(0,1) * 2 -1);

        if (opendoor>2){
            opendoor = opendoor - 3;

        } else if(opendoor<0){
            opendoor = opendoor + 3;
            }
        }
        
        cout <<"Guess: "<< guess << endl;
        cout <<"Guess1: "<< guess1 << endl;
        cout <<"Opendoor: "<< opendoor << endl;
        cout << endl;

        if (doors[guess] == "m"){ 
            wins = wins + 1;
        }

    }
    float winrate = (float)wins/itternum;
    int losses = itternum-wins;
    cout << "Iterations: " << itternum << endl ;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Winrate: " << 100*winrate <<"%";
    cin >> dummyvar ;
}   
