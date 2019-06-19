//
// Created by Max on 20/05/2019.
//

#ifndef MINI_PROJECT_CONSOLE_VIEW_H
#define MINI_PROJECT_CONSOLE_VIEW_H

#include "../../tools/Observer/Observer.h"

class ObservableGame_Controller;

class Console_View : public Observer {
public:
    virtual void updateView(Subject* subject) override;
    void checkInput(ObservableGame_Controller &controller);

    virtual ~Console_View() = default;
};

#endif //MINI_PROJECT_CONSOLE_VIEW_H
