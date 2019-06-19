//
// Created by Max on 08/06/2019.
//

#include "ObservableGame_Controller.h"

ObservableGame_Controller::ObservableGame_Controller(int argc, char **argv) {
    ParseArgs* parseArgs = new ParseArgs();

    parseArgs->addArg( "help", {"console", "graphic", "mixed"} , "mode", 'm' );
    parseArgs->addArg( "false", {"false", ""} , "help", 'h' );

    map<string, string> argMap;
    parseArgs->getArgMap(argc, argv, argMap);

    string mode = argMap["mode"];

    if(argMap["help"] == "" || mode == "help") {
        cout << "Attaxx by Maxime NARBAUD" << endl << endl;
        cout << "Help :" << endl
             << " -h, --help    ==> show help" << endl
             << " -m, --mode 'console / graphic / mixed'    ==> start game in the chosen mode" << endl;

        exit(0);

    } else if ( mode == "console") {
        shared_ptr<Console_View> consoleView( new Console_View() );

        this->addObserver(consoleView);
        this->launchGame();

    } else if(mode == "graphic") {
        QApplication app(argc, argv);

        shared_ptr<Qt_View> qtView( new Qt_View() );

        this->addObserver(qtView);
        qtView->show();

        this->launchGame();
        QApplication::exec();

    } else if(mode == "mixed") {
        this->setMixedMode();

        QApplication app(argc, argv);

        shared_ptr<Qt_View> qtView( new Qt_View() );
        shared_ptr<Console_View> consoleView( new Console_View() );

        this->addObserver(qtView);
        qtView->show();
        this->addObserver(consoleView);

        this->launchGame();
        QApplication::exec();
    }
}

void ObservableGame_Controller::launchGame() {
    Game_Controller::launchGame();
    notifyObservers();
}

bool ObservableGame_Controller::playAction(int startRow, int startColumn, int arrivalLine, int arrivalColumn) {
    bool moved = Game_Controller::playAction(startRow, startColumn, arrivalLine, arrivalColumn);

    notifyObservers();

    return moved;
}

bool ObservableGame_Controller::isMixedMode() const {
    return mixedMode;
}

void ObservableGame_Controller::setMixedMode() {
    this->mixedMode = true;
}
