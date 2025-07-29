//Monty hall sim in C++
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <chrono>
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
    cout <<"How many iterations of the monty hall problem would you like to simulate?"<<endl;
    cin >> itternum;
    auto start_time =chrono::high_resolution_clock::now();
    int size = sizeof(doors) / sizeof(doors[0]);
    for (int i = 0; i < itternum ; i++) {    
        random_shuffle(&doors[0],&doors[3]);
        guess1 = randint(0,2);
        opendoor = randint(0,2);

        for (int i=0;i<2;i++){
            if (doors[opendoor] == "m" || opendoor==guess1){
                opendoor = opendoor + 1;
            }
     
            if (opendoor>2){
                opendoor = opendoor - 3;
            }   
        }

        guess = guess1;
        for (int i = 0; i < 2 ; i++){
            if (guess == opendoor || guess == guess1){
                guess = guess + 1 ;               
                if (guess > 2 ){
                        guess = guess -3;
                }
            }
        }   

        if (doors[guess] == "m"){ 
            wins++;
        }
    }
    auto end_time =  chrono::high_resolution_clock::now();

    float time_taken_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    float seconds_taken = time_taken_ns/1000000000;
    float rate = itternum/seconds_taken;
    float winrate = (float)wins/itternum;

    int losses = itternum-wins;
    cout << "Iterations: " << itternum << endl ;
    cout << "Wins when swapping:: " << wins << endl;
    cout << "wins when not swapping: " << losses << endl;
    cout << "Winrate when swapping: " << 100*winrate <<"%"<< endl;
    cout << "Winrate when not swapping: " << 100-(100*winrate) <<"%"<<endl;
    cout << "Time taken: " << fixed << setprecision(9) << seconds_taken << " seconds" << endl;
    cout <<"Rate: " << rate << " per second";
    cin >> dummyvar ;
}       
