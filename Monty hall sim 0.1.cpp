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

    string doors[3] = {"m","g","n"};
    string doors_otherside[3] = {"m","g","n"};
    cout <<"How many iterations with swapping would you like to simulate the monty hall problem for?"<<endl;
    cin >> itternum;

    int size = sizeof(doors) / sizeof(doors[0]);
    for (int i = 0; i < itternum ; i++) {
        guess = randint(0,2);
        // cout << "Guess: " << guess << endl ;
        random_shuffle(&doors[0],&doors[3]);

        copy(doors, doors + 3, doors_otherside);
        // cout << i  << ":";
        // cout << "Doors: " ;
        // for ( int j = 0;  j < size; j++) {   //consider making func for printing arrays
        //     cout << doors[j] ;
        // }
        // cout << endl;

        // cout << "Doors_otherside: " ;
        // for ( int j = 0;  j < size; j++) {   //consider making func for printing arrays
        //     cout << doors_otherside[j] ;
        // }
        // cout << endl;

        opendoor=randint(0,2);

        if (doors[opendoor] == "m"){
            // opendoor = (opendoor-randint(1,2)) ;
            if (opendoor != 2){
                opendoor = opendoor + 1;
            }
            else {
                opendoor = opendoor - 1;
            }
            

        }

    if (opendoor!=0){
        guess = opendoor-1;
    }
        
    else {
        guess= opendoor+1;
    }
    
        // cout <<"Opendoor: " << opendoor << endl;
        
        // if (doors[opendoor] == "m" || opendoor<0 || opendoor>2){
        //     cout <<"Invalid open door" << endl;
        // } 

        if (doors[guess] == "m"){ 
            wins++;
        }
        // cout << endl ;
    }
    float winrate = (float)wins/itternum;
    int losses = itternum-wins;
    cout << "Iterations: " << itternum << endl ;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Winrate: " << 100*winrate <<"%";
    cin >> dummyvar ;
}   
