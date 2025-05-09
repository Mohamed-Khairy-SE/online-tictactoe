
    /*
    - switch palyers
    1- check if clicked button is still empty 
    2- click hander
    3- set value
    4- check if the player has won
    */
#ifndef LOGIC
#define LOGIC

#include <iostream>
#include <vector>
#include <utility>
#include <string>

class GameLogic {
private:
    std::vector<std::vector<char>> game;
    static constexpr char player_1 = 'X';
    static constexpr char player_2 = 'O';
    char current_player {};
    std::string theWinner{}; 
    bool playerHasWon;
public:
    
    GameLogic();
    void switchPlayer();
    bool isEmpty(std::pair<int, int> position);
    void setValue(std::pair<int, int> position);
    bool checkWinningStates(std::pair<int, int> position1,std::pair<int, int> position2,std::pair<int, int> position3);
    bool hasWon();
    std::string turnPlayEventHandler(std::pair<int,int> position);
    char getCurrentPlayer();
};

#endif
