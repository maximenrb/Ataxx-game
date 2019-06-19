//
// Created by Max on 03/06/2019.
//

#ifndef MINI_PROJECT_QT_VIEW_H
#define MINI_PROJECT_QT_VIEW_H

#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

#include "../../tools/Observer/Observer.h"

class ObservableGame_Controller;

class Qt_View : public QMainWindow, public Observer {
    Q_OBJECT

private:
    QGridLayout* gridLayout;
    QLabel* notification;
    QLabel* scorePlayer1;
    QLabel* scorePlayer2;
    QPushButton* restartButton;
    QPushButton* quitButton;

public:
    // Create the structure of the qt view (main Widget, Layouts, Buttons...)
    Qt_View(QWidget *parent = nullptr);

    // Update the component of the view (add pawn to grid, connect(),
    virtual void updateView(Subject* subject) override;

    void clearLayout(QLayout* layout, bool deleteWidgets = true);

    virtual ~Qt_View() {}

public slots :
    void clickCircle(int startLine, int startColumn, ObservableGame_Controller& controller);
    void clickQuit(ObservableGame_Controller& controller);
    void clickRestart(ObservableGame_Controller& controller);
};


#endif //MINI_PROJECT_QT_VIEW_H
