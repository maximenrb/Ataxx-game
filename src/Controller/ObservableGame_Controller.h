//
// Created by Max on 20/05/2019.
//

#ifndef MINI_PROJECT_OBSERVABLEGAME_CONTROLLER_H
#define MINI_PROJECT_OBSERVABLEGAME_CONTROLLER_H

#include <memory>
#include <QApplication>

#include "Game_Controller.h"
#include "../../tools/Observer/Subject.h"
#include "../../tools/ParseArgs/ParseArgs.h"
#include "../View/Console_View.h"
#include "../View/Qt_View.h"

using std::shared_ptr;

class ObservableGame_Controller : public Game_Controller, public Subject {
private:
    bool mixedMode = false;

public:
    ObservableGame_Controller(int argc, char *argv[]);

    virtual void launchGame() override;
    virtual bool playAction(int startRow, int startColumn, int arrivalLine, int arrivalColumn) override;

    // Used to disable console input if mixed mode is selected
    void setMixedMode();
    bool isMixedMode() const;

    virtual ~ObservableGame_Controller() {}

};

#endif //MINI_PROJECT_OBSERVABLEGAME_CONTROLLER_H
