//
// Created by Max on 08/06/2019.
//

#include "Console_View.h"
#include "../Controller/ObservableGame_Controller.h"

void Console_View::updateView(Subject *subject) {
    ObservableGame_Controller* controller = dynamic_cast<ObservableGame_Controller*>(subject);

    if(controller == nullptr) { return; }

    int p1Pawn = controller->getPlayer1Pawn();
    int p2Pawn = controller->getPlayer2Pawn();

    cout << endl << termcolor::blue << "Player 1 : " << p1Pawn << termcolor::grey << " | " << termcolor::red << "Player 2 : " << p2Pawn << endl;

    cout << "    ";
    for(int column = 0; column < 7; ++column) {
        cout << termcolor::cyan << (column+1) << "   ";
    }
    cout << endl;

    for (int line = 0; line < 7; ++line) {
        cout << termcolor::cyan << (line+1) << "|  ";

        for (int column = 0; column < 7; ++column) {
            int value = controller->getValue(line, column);

            switch ( value ) {
                case 1 :
                    cout << termcolor::blue << value << "   ";
                    break;
                case 2 :
                    cout << termcolor::red << value << "   ";
                    break;
                case 3 :
                    cout << termcolor::white << value << "   ";
                    break;
                default:
                    cout << termcolor::grey << value << "   ";
                    break;
            }
        }
        cout << endl;
    }


    if( controller->getFinishStatement() ) {
        cout << termcolor::yellow << "Game finished ! ";

        if(p1Pawn > p2Pawn) {
            cout << termcolor::blue << "Player 1 has won" << endl;
        } else if (p1Pawn < p2Pawn) {
            cout << termcolor::red << "Player 2 has won" << endl;
        } else {
            cout << termcolor::yellow << "Equality" << endl;
        }

        if( !controller->isMixedMode() ) {
            string statement;

            while(statement != "restart" || statement != "quit") {
                cout << termcolor::grey << "Type 'restart' to launch a new game, or 'quit' to exit the game : ";
                cin >> statement;

                if(statement == "restart") {
                    controller->restartGame();
                } else if(statement == "quit") {
                    return;
                }
            }
        }
    }

    if( !controller->isMixedMode() ) {
        checkInput(*controller);
    }
}

void Console_View::checkInput(ObservableGame_Controller &controller) {
    if(controller.getActualPlayer() == 1) {
        cout << termcolor::blue << "Player " << controller.getActualPlayer() << " > ";
    } else {
        cout << termcolor::red << "Player " << controller.getActualPlayer() << " > ";
    }

    int startRow = 0, startColumn = 0, arrivalLine = 0, arrivalColumn = 0;

    std::cin >> startRow >> startColumn >> arrivalLine >> arrivalColumn;

    controller.playAction(startRow-1, startColumn-1, arrivalLine-1, arrivalColumn-1);
}