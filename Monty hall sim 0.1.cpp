//Monty hall sim in C++
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

int get_randint(int min, int max){
   static std::random_device rd;      
    static std::mt19937 gen(rd());     
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main()
{   
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
        guess = get_randint(0,2);
        random_shuffle(&doors[0],&doors[3]);
        if (doors[guess] == "m"){
            wins++;
        };
        copy(doors, doors + 3, doors_otherside);
    }
    float winrate = (float)wins/itternum;
    int losses = itternum-wins;
    cout << "Iterations: " << itternum << endl ;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Winrate: " << 100*winrate <<"%";
    cin >> dummyvar ;
}   
