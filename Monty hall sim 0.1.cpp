//Monty hall sim in C++
// #include <random>
// #include <array> 
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int wins = 0;
    int itternum;
    string doors[3] = {"m","g","n"};
    string doors_otherside[3] = {"m","g","n"};
    cout <<"How many iterations with swapping would you like to simulate the monty hall problem for?";
    cin >> itternum;

    for (int i = 0; i < itternum ; i++) {
        cout <<i;
        random_shuffle(&doors[0],&doors[3]);
        // std : : shuffle
        // doors = {"m","g","n"};
    }

}   