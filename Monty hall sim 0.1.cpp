//Monty hall sim in C++
 #include <random>
// #include <array> 
#include <algorithm>
#include <iostream>
using namespace std;

int get_randint(int min, int max){
   static std::random_device rd;       // Non-deterministic seed
    static std::mt19937 gen(rd());      // Mersenne Twister engine

    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main()
{   
    int opendoor;
    int guess;
    int wins = 0;
    int itternum;
    string doors[3] = {"m","g","n"};
    string doors_otherside[3] = {"m","g","n"};
    cout <<"How many iterations with swapping would you like to simulate the monty hall problem for?"<<endl;
    cin >> itternum;
    // cout << doors << endl;
    int size = sizeof(doors) / sizeof(doors[0]);
    

    for (int i = 0; i < itternum ; i++) {
        // cout << i  << ":";
        // for ( int j = 0;  j < size; j++) {
            // cout << doors[j] <<"" ;
        //    }   
        guess = get_randint(0,2);
        // cout << "" << endl;
        // cout << "guess:" << guess;
        // cout << "" << endl;
        random_shuffle(&doors[0],&doors[3]);
        if (doors[guess] == "m"){
            wins++;
        };
        copy(doors, doors + 3, doors_otherside);
        // std : : shuffle
        // doors = {"m","g","n"};
    }
    float winrate = (float)wins/itternum;
    int losses = itternum-wins;
    cout << "Iterations: " << itternum << endl ;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Winrate: " << winrate;


}   
