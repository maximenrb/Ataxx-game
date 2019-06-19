//
// Created by Max on 20/05/2019.
//

#ifndef MINI_PROJECT_OBSERVER_H
#define MINI_PROJECT_OBSERVER_H

#include <iostream>

class Subject;

using std::cout;
using std::endl;

class Observer  {
public:
    virtual void updateView(Subject* subject) = 0;

    virtual ~Observer() {}
};

#endif //MINI_PROJECT_OBSERVER_H
