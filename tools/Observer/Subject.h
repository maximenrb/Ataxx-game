//
// Created by Max on 20/05/2019.
//

#ifndef MINI_PROJECT_SUBJECT_H
#define MINI_PROJECT_SUBJECT_H

#include <list>
#include <memory>

#include "Observer.h"

using std::list;
using std::shared_ptr;

class Subject {
private:
    list<shared_ptr<Observer>> observers;

protected:
    void notifyObservers() {
        for(const auto& observer : observers) {
            if(observer != nullptr) {
                observer->updateView(this);
            }
        }
    }

public:
    void addObserver(const shared_ptr<Observer>& observer) {
        observers.push_back(observer);
    }

    void removeObserver(const shared_ptr<Observer>& observer) {
        for(auto it = observers.begin(); it != observers.end(); it++) {
            if(*it == observer) {
                observers.erase(it);
                return;
            }
        }
    }

    virtual ~Subject() {};
};


#endif //MINI_PROJECT_SUBJECT_H
