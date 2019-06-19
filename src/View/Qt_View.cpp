//
// Created by Max on 09/06/2019.
//

#include "Qt_View.h"
#include "../Controller/ObservableGame_Controller.h"

Qt_View::Qt_View(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Ataxx");
    setMinimumSize(404, 528);

    setMinimumWidth(404);
    setMaximumWidth(404);
    setMinimumHeight(528);
    setMaximumHeight(528);

    QWidget* mainWidget = new QWidget();
    QVBoxLayout* qvBoxLayout = new QVBoxLayout();

    QHBoxLayout* qhBoxLayoutButton = new QHBoxLayout();
    QHBoxLayout* qhBoxLayoutScore = new QHBoxLayout();

    gridLayout = new QGridLayout();
    notification = new QLabel();
    restartButton = new QPushButton();
    quitButton = new QPushButton();

    scorePlayer1 = new QLabel();
    scorePlayer2 = new QLabel();

    gridLayout->setSpacing(4);
    gridLayout->setMargin(0);

    notification->setStyleSheet("border-style: solid; border-width:1px; border-color: black;"
                                "max-width:388px; max-height: 20px; min-width: 390px; min-height: 20px;");
    notification->setAlignment(Qt::AlignCenter);

    restartButton->setStyleSheet("background-color: #1abc9c; border-style: solid; border-width:1px; border-color: #16a085;"
                                 "max-width:190px; max-height: 30px; min-width: 190px; min-height: 30px;");
    restartButton->setText("Restart Game");

    quitButton->setStyleSheet("background-color: #9b59b6; border-style: solid; border-width:1px; border-color: #8e44ad;"
                              "max-width:190px; max-height: 30px; min-width: 190px; min-height: 30px;");
    quitButton->setText("Quit Game");

    scorePlayer1->setStyleSheet("background-color: #3498db; border-style: solid; border-width:1px; border-color: #2980b9;"
                                "max-width:190px; max-height: 30px; min-width: 190px; min-height: 30px;");

    scorePlayer2->setStyleSheet("background-color: #e74c3c; border-style: solid; border-width:1px; border-color: #c0392b;"
                                "max-width:190px; max-height: 30px; min-width: 190px; min-height: 30px;");

    qhBoxLayoutButton->addWidget(restartButton);
    qhBoxLayoutButton->addWidget(quitButton);
    qhBoxLayoutButton->setContentsMargins(0, 10, 0, 0);
    qhBoxLayoutButton->setSpacing(8);

    qhBoxLayoutScore->addWidget(scorePlayer1);
    qhBoxLayoutScore->addWidget(scorePlayer2);
    qhBoxLayoutScore->setContentsMargins(0, 5, 0, 10);
    qhBoxLayoutScore->setSpacing(8);

    qvBoxLayout->addWidget(notification);
    qvBoxLayout->addLayout(qhBoxLayoutScore);
    qvBoxLayout->addLayout(gridLayout);
    qvBoxLayout->addLayout(qhBoxLayoutButton);

    mainWidget->setLayout(qvBoxLayout);

    setCentralWidget(mainWidget);

    notification->setText("Start of the game");
}

void Qt_View::updateView(Subject *subject) {
    ObservableGame_Controller* controller = dynamic_cast<ObservableGame_Controller*>(subject);
    if(controller == nullptr) { return; }

    connect( restartButton,  &QPushButton::clicked, this, [controller, this]() { clickRestart(*controller); } );
    connect( quitButton,  &QPushButton::clicked, this, [controller, this]() { clickQuit(*controller); } );

    clearLayout(gridLayout);

    int p1Pawn = controller->getPlayer1Pawn();
    int p2Pawn = controller->getPlayer2Pawn();

    QString text = "<span style='font-size:10pt; font-weight:400;'>Player 1 score :</span><br><span style='font-size:12pt; font-weight:600;'>" + QString::number(p1Pawn) + "</span>";
    scorePlayer1->setText(text);
    scorePlayer1->setAlignment(Qt::AlignCenter);

    text = "<span style='font-size:10pt; font-weight:400;'>Player 2 score :</span><br><span style='font-size:12pt; font-weight:600;'>" + QString::number(p2Pawn) + "</span>";
    scorePlayer2->setText(text);
    scorePlayer2->setAlignment(Qt::AlignCenter);


    bool gameStatement = controller->getFinishStatement();

    if( gameStatement ) {
        std::string text = "GAME FINISHED ! ";

        if(p1Pawn > p2Pawn) { text += "Player 1 has won "; }
        else if (p1Pawn < p2Pawn) { text += "Player 2 has won "; }
        else { text += "Equality "; }

        notification->setText(QString::fromStdString(text));
        notification->setStyleSheet("border-style: solid; border-width:1px; border-color: #f39c12;"
                                    "max-width:388px; max-height: 20px; min-width: 390px; min-height: 20px;");
    }

    for (int line = 0; line < 7; ++line) {
        for (int column = 0; column < 7; ++column) {
            int value = controller->getValue(line, column);

            QPushButton* pawn = new QPushButton();

            if(value != 0) {
                if(value == 1) {
                    pawn->setStyleSheet("background-color: #3498db; border-style: solid; border-width:2px; border-color: #2980b9;"
                                        "max-width:50px; max-height:50px; min-width:50px; min-height:50px;");
                } else if (value == 2) {
                    pawn->setStyleSheet("background-color: #e74c3c; border-style: solid; border-width:2px; border-color: #c0392b;"
                                        "max-width:50px; max-height:50px; min-width:50px; min-height:50px;");
                } else if (value == 3) {
                    pawn->setStyleSheet("background-color: #95a5a6; border-style: solid; border-width:2px; border-color: #7f8c8d;"
                                        "max-width:50px; max-height:50px; min-width:50px; min-height:50px;");
                }

                if(!gameStatement) {
                    int player = controller->getActualPlayer();

                    std::string text = "Player " + std::to_string(player) + " it's your turn !";
                    notification->setText(QString::fromStdString(text));

                    if(player == 1) {
                        notification->setStyleSheet("border-style: solid; border-width:1px; border-color: #2980b9;"
                                                    "max-width:388px; max-height: 20px; min-width: 390px; min-height: 20px;");
                    } else if(player == 2) {
                        notification->setStyleSheet("border-style: solid; border-width:1px; border-color: #c0392b;"
                                                    "max-width:388px; max-height: 20px; min-width: 390px; min-height: 20px;");
                    }

                    if(value == player) {
                        connect( pawn,  &QPushButton::clicked, this, [line, column, controller, this]() { clickCircle(line, column, *controller); } );
                    }
                }
            } else {
                pawn->setStyleSheet("background-color: #ecf0f1; border-style: solid; border-width:2px; border-color: #bdc3c7;"
                                    "max-width:50px; max-height: 50px; min-width: 50px; min-height: 50px;");
            }

            gridLayout->addWidget(pawn, line, column);
        }
    }
}

void Qt_View::clearLayout(QLayout *layout, bool deleteWidgets) {
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (deleteWidgets) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater();
            }
        }

        if (QLayout* childLayout = item->layout()) {
            clearLayout(childLayout, deleteWidgets);
        }

        delete item;
    }
}


void Qt_View::clickCircle(int startLine, int startColumn, ObservableGame_Controller &controller) {
    GridType grid = controller.getPlayableMap(startLine, startColumn);

    for (int line = 0; line < 7; ++line) {
        for (int column = 0; column < 7; ++column) {
            int value = grid[line][column];

            QPushButton* pawn = dynamic_cast<QPushButton*>(this->gridLayout->itemAtPosition(line, column)->widget());
            if( pawn->property("playableCase") == "true") {
                pawn->setStyleSheet("background-color: #ecf0f1; border-style: solid; border-width:2px; border-color: #bdc3c7;"
                                    "max-width:50px; max-height: 50px; min-width: 50px; min-height: 50px;");
                pawn->setProperty("playableCase", "false");

                disconnect(pawn, nullptr , nullptr, nullptr);
            }

            if (value != 0) {
                if (value == 1) {
                    pawn->setStyleSheet("background-color: #ecf0f1; border-style: solid; border-width:2px; border-color: #2ecc71;"
                                        "max-width:50px; max-height: 50px; min-width: 50px; min-height: 50px;");
                    pawn->setProperty("playableCase", "true");

                } else if (value == 2) {
                    pawn->setStyleSheet("background-color: #ecf0f1; border-style: solid; border-width:2px; border-color: #27ae60;"
                                        "max-width:50px; max-height:50px; min-width:50px; min-height: 50px;");
                    pawn->setProperty("playableCase", "true");
                }

                connect( pawn,  &QPushButton::clicked, this, [startLine, startColumn, line, column, &controller, this]() {
                    controller.playAction(startLine, startColumn, line, column);
                } );

                gridLayout->addWidget( pawn, line, column);
            }
        }
    }
}

void Qt_View::clickRestart(ObservableGame_Controller &controller) {
    controller.restartGame();
}

void Qt_View::clickQuit(ObservableGame_Controller &controller) {
    QApplication::quit();
}
