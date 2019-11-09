/** 
 * Slot machine game written in c++.
 * Data Structure Assignment2
 * Written by Ritish Karki. Student ID 00676516
 * **/
#include <iostream>
#include "Game.cpp"
#include <ctime>
#include <string>
int main(){
    // for generating different set of random numbers every time
    srand(time(0));
    string yes_no;

    Game *game = new Game();
    cout << endl << "Welcome to the Slot Machine game. Below are the winning combinations. " << endl;


    // displaying winning table
    cout << " ---------------------- " << endl 
    <<"| Combination | payout  |" << endl 
    << " ---------------------- " << endl 
    <<"|   A A A     |  $14    |" << endl 
    << "|   B B B     |	 $35    |" << endl
    << "|   C C C     |  $100   |" << endl
    << "|   7 7 7     |  $900   |" << endl
    << " ---------------------- " << endl;

    cout << "You currently have $100. Enter the game (yes/no) :" ;
    getline (cin, yes_no);

    if(yes_no == "yes" || yes_no == "Yes" || yes_no == "YES"){
        game->Play();
    }else{
        exit(0);
    }
    delete(game);
    return 0;
}