//
// Created by Max on 19/05/2019.
//

#ifndef MINI_PROJECT_GAME_CONTROLLER_H
#define MINI_PROJECT_GAME_CONTROLLER_H

#include <iostream>
#include <cmath>

#include "../Model/Grid_Model.h"
#include "../../tools/termColor/termcolor.hpp"

using std::cout;
using std::endl;
using std::abs;

class Game_Controller {
private:
    Grid_Model* gridModel;

    int player1_Pawn = 0;
    int player2_Pawn = 0;

    unsigned short actualPlayer = 0;
    bool gameFinished = false;

public:
    Game_Controller() = default;

    int getValue(int line, int column) { return this->gridModel->getValue(line, column); }
    int setValue(int line, int column, int value) { this->gridModel->setValue(line, column, value); }

    int getPlayer1Pawn() const { return player1_Pawn; }
    void setPlayer1Pawn(int player1Pawn) { player1_Pawn = player1Pawn; }
    int getPlayer2Pawn() const { return player2_Pawn; }
    void setPlayer2Pawn(int player2Pawn) { player2_Pawn = player2Pawn; }

    void setActualPlayer(unsigned short player) { this->actualPlayer = player; }
    unsigned short getActualPlayer() const { return this->actualPlayer; }
    void setGameFinished() { this->gameFinished = true; }
    bool getFinishStatement() { return this->gameFinished; }

    virtual void launchGame();
    void restartGame();

    virtual bool playAction(int startRow, int startColumn, int arrivalLine, int arrivalColumn);
    void updateNbPawn();
    unsigned short getWaitingPlayer();

    // Reverse the actual player
    void switchPlayer();

    // Reduce the range of the loop if case is next to a border
    void static setMinMax(int startRow, int startColumn, int& minLine, int& maxLine, int& minColumn, int& maxColumn);

    // Convert the opponent player's pieces adjacent to the destination square to the moving player
    void changeClosePawn(int arrivalRow, int arrivalColumn);

    // Return a map with position where the player can play for a given position
    GridType getPlayableMap(int startRow, int startColumn);

    // Return true if the player has at least one possibility to play for a given position, else return false
    bool checkPlayableCase(int startRow, int startColumn);

    // Set game finished if at least one player can't play
    void checkGameFinished();

    virtual ~Game_Controller() {
        delete(this->gridModel);
    }
};

#endif //MINI_PROJECT_GAME_CONTROLLER_H
