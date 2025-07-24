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
    string doors_otherside[3] = {"m","g","n"};
    cout <<"How many iterations with swapping would you like to simulate the monty hall problem for?"<<endl;
    cin >> itternum;

    int size = sizeof(doors) / sizeof(doors[0]);
    for (int i = 0; i < itternum ; i++) {
        // guess = randint(0,2);
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
        guess1 = randint(0,2);
        opendoor = randint(0,2);

       for (int i=0;i<2;i++){
        if (doors[opendoor] == "m" || opendoor==guess1){
            opendoor = opendoor + 1;
           }
      
        if (opendoor>2){
            opendoor = opendoor - 3;

        } else if(opendoor<0){
            opendoor = opendoor + 3;
            }
        }
        // cout << opendoor << endl ;

        // guess = guess + 1;

        // // if (guess >2 ){
        //     guess = guess -3;
        // }
        
        // if (guess < 0){
        // //     guess = guess +3;
        // }
        guess = guess1 + 1;

        // cout << "GGESS!!!"<< guess<<endl;
        for (int i = 0; i < 2 ; i++){
            if (guess == opendoor || guess == guess1){
                guess = guess + 1 ;               
                if (guess > 2 ){
                    guess = guess -3;
                }else if (guess < 0){
                    guess = guess +3;
                }
            }
        }   
        cout <<"Guess: "<< guess << endl;
        cout <<"Guess1: "<< guess1 << endl;
        cout <<"Opendoor: "<< opendoor << endl;
        cout << endl;
        if (guess == guess1 || guess == opendoor) {
            cout << "Invalid guess" << endl;
        }
        // cout <<"Opendoor: " << opendoor << endl;
        
        // if (doors[opendoor] == "m" || opendoor<0 || opendoor>2){
        //     // cout <<"Invalid open door" << endl;
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
