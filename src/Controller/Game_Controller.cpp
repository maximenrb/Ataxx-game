//
// Created by Max on 19/05/2019.
//

#include "Game_Controller.h"

void Game_Controller::launchGame() {
    this->gridModel = new Grid_Model();

    this->setValue(0, 0, 1);
    this->setValue(6, 6, 1);
    this->setValue(0, 6, 2);
    this->setValue(6, 0, 2);

    this->setPlayer1Pawn(2);
    this->setPlayer2Pawn(2);

    this->setActualPlayer(1);
}

void Game_Controller::updateNbPawn() {
    this->setPlayer1Pawn(0);
    this->setPlayer2Pawn(0);

    for (int line = 0; line < 7; ++line) {
        for (int column = 0; column < 7; ++column) {
            int value = this->getValue(line, column);

            switch (value) {
                case 1 :
                    this->player1_Pawn++;
                    break;
                case 2 :
                    this->player2_Pawn++;
                    break;
                default:
                    break;
            }
        }
    }
}

void Game_Controller::switchPlayer() {
    if(this->getActualPlayer() == 1) {
        this->setActualPlayer(2);
    } else {
        this->setActualPlayer(1);
    }
}

unsigned short Game_Controller::getWaitingPlayer() {
    if(this->getActualPlayer() == 1) {
        return 2;
    } else {
        return 1;
    }
}

void Game_Controller::setMinMax(int startRow, int startColumn, int& minLine, int& maxLine, int& minColumn, int& maxColumn) {
    if(startRow - 2 >= 0) {
        minLine = -2;
    } else if(startRow - 1 >= 0) {
        minLine = -1;
    }

    if(startColumn - 2 >= 0) {
        minColumn = -2;
    } else if(startColumn - 1 >= 0) {
        minColumn = -1;
    }

    if(startRow + 2 < GridSIZE) {
        maxLine = 2;
    } else if(startRow + 1 < GridSIZE) {
        maxLine = 1;
    }

    if(startColumn + 2 < GridSIZE) {
        maxColumn = 2;
    } else if(startColumn + 1 < GridSIZE) {
        maxColumn = 1;
    }
}

void Game_Controller::restartGame() {
    delete(gridModel);
    this->player1_Pawn = 0;
    this->player2_Pawn = 0;
    this->actualPlayer = 0;
    this->gameFinished = false;

    this->launchGame();
}

bool Game_Controller::playAction(int startRow, int startColumn, int arrivalLine, int arrivalColumn) {
    if( this->getActualPlayer() == this->gridModel->getValue(startRow, startColumn) ) {
        GridType grid = getPlayableMap(startRow, startColumn);

        int value = grid[arrivalLine][arrivalColumn];

        if ( value == 1 || value == 2 ) {
            if ( value == 2 ) {
                this->gridModel->setValue(startRow, startColumn, 0);
            }

            this->gridModel->setValue(arrivalLine, arrivalColumn, this->getActualPlayer());
            this->changeClosePawn(arrivalLine, arrivalColumn);
            this->updateNbPawn();
            this->switchPlayer();
            this->checkGameFinished();

            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

GridType Game_Controller::getPlayableMap(int startRow, int startColumn) {
    Grid_Model* gridModel_Playable = new Grid_Model();

    int minLine = 0, maxLine = 0, minColumn = 0, maxColumn = 0;

    Game_Controller::setMinMax(startRow, startColumn, minLine, maxLine, minColumn, maxColumn);

    for (int line = minLine; line <= maxLine; ++line) {
        for(int column = minColumn; column <= maxColumn; ++column) {

            if( this->gridModel->getValue(startRow+line, startColumn+column) == 0 ) {

                if( abs(line) != 2 && abs(column) != 2) {
                    gridModel_Playable->setValue(startRow+line, startColumn+column, 1);
                } else {
                    gridModel_Playable->setValue(startRow+line, startColumn+column, 2);
                }
            }
        }
    }

    GridType grid = gridModel_Playable->getGrid();
    delete(gridModel_Playable);

    return grid;
}

void Game_Controller::changeClosePawn(int arrivalRow, int arrivalColumn) {
    unsigned short waitingPlayer = this->getWaitingPlayer();
    unsigned short player = this->getActualPlayer();

    int minLine = 0, maxLine = 0, minColumn = 0, maxColumn = 0;

    if(arrivalRow - 1 >= 0) { minLine = -1; }
    if(arrivalColumn - 1 >= 0) { minColumn = -1; }
    if(arrivalRow + 1 < GridSIZE) { maxLine = 1; }
    if(arrivalColumn + 1 < GridSIZE) { maxColumn = 1; }

    for (int line = minLine; line <= maxLine; ++line) {
        for(int column = minColumn; column <= maxColumn; ++column) {

            if( this->getValue(arrivalRow+line, arrivalColumn+column) == waitingPlayer ) {
                this->setValue(arrivalRow+line, arrivalColumn+column, player);
            }
        }
    }
}

void Game_Controller::checkGameFinished() {
    bool player1CanPlay = false;
    bool player2CanPlay = false;

    for (int line = 0; line < GridSIZE; ++line) {
        for (int column = 0; column < GridSIZE; ++column) {
            int value = this->getValue(line, column);

            if( value == 1 && !player1CanPlay) {
                if( checkPlayableCase(line, column) ) {
                    player1CanPlay = true;
                }

            } else if ( value == 2 && !player2CanPlay) {
                if( checkPlayableCase(line, column) ) {
                    player2CanPlay = true;
                }
            }

            if(player1CanPlay && player2CanPlay) {
                return;
            }
        }
    }
    this->setGameFinished();
}

bool Game_Controller::checkPlayableCase(int startRow, int startColumn) {
    int minLine = 0, maxLine = 0, minColumn = 0, maxColumn = 0;

    Game_Controller::setMinMax(startRow, startColumn, minLine, maxLine, minColumn, maxColumn);

    for (int line = minLine; line <= maxLine; ++line) {
        for(int column = minColumn; column <= maxColumn; ++column) {

            if( this->getValue(startRow+line, startColumn+column) == 0 ) {
                return true;
            }
        }
    }

    return false;
}