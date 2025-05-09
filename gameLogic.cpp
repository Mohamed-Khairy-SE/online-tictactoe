#include "gameLogic.h"

GameLogic::GameLogic() {
    game = std::vector<std::vector<char>>(3, std::vector<char>(3, '-'));
    playerHasWon = false;
    current_player = player_1;
}
std::string GameLogic::turnPlayEventHandler(std::pair<int,int> position){
    // 1- check if the clicked position is clicked
   if(isEmpty(position)){
        // 1.1- set the value
        setValue(position);
        // 1.2- check if the palyer has won
        if(hasWon()){        
            // 1.2.1 if the player has won -> terminate the game
            return theWinner;
        }else{
            // 1.2.2- if not switch player 
            switchPlayer();
            return "";
        }
        
   }
   return "This Square is not Empty";
}
// switch between the two players
void GameLogic::switchPlayer(){
    switch(current_player){
        case player_1:
            current_player = player_2;
            break;
        case player_2:
            current_player = player_1;
            break;
    }
}
// check if the clicked position is empty 
bool GameLogic::isEmpty(std::pair<int, int> position) {
    int row = position.first;
    int col = position.second;
    return game[row][col] == '-';
}
// set the value of the clicked position with the current player value
void GameLogic::setValue(std::pair<int, int> position){
    int row = position.first;
    int col = position.second;
    game[row][col] == current_player;
}
// helper for hasWon method to check the three main winning states
bool GameLogic::checkWinningStates(std::pair<int, int> position1,std::pair<int, int> position2,std::pair<int, int> position3){
    bool winningStaterRow =
    (position1.first == position2.first && position2.first == position3.first) &&
    (position1.second + position2.second + position3.second == 3);

    bool winningStaterColumn =
    (position1.second == position2.second && position2.second == position3.second) &&
    (position1.first + position2.first + position3.first == 3);

    bool winningStaterDiagonal =
    (position1.second + position2.second + position3.second == 3) &&
    (position1.first + position2.first + position3.first == 3);

    return winningStaterRow || winningStaterColumn || winningStaterDiagonal;

}

bool GameLogic::hasWon(){
  // loop for checking if any row applied a winning state
  for(int i = 0;i<3;i++){
    bool isTerminated = checkWinningStates({i,0},{i,1},{i,2}) && (game[i][0] == game[i][1] &&game[i][1]==  game[i][2]);
     if(isTerminated){
        playerHasWon = true;
       break;
     }
  }
  // loop for checking if any column applied a winning state
  for(int i = 0;i<3;i++){
    bool isTerminated = checkWinningStates({0,i},{1,i},{2,i}) && (game[0][i] == game[1][i] &&game[1][i]==  game[2][i]);
     if(isTerminated){
        playerHasWon = true;
        break;
     }
  }
  // check if the diagonals applyied the winning states
  bool isTerminated = checkWinningStates({0,0},{1,1},{2,2}) && (game[0][0] == game[1][1] &&game[1][1]==  game[2][2]);
  if(isTerminated){
    playerHasWon = true;
 }
 if(playerHasWon){
    theWinner = current_player;
    return true;
 }else{
    return false;
 }
 
}