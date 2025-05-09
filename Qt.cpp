#include "Qt.h"

tictactoeUI::tictactoeUI(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Tic-Tac-Toe");
    this->setFixedSize(400, 400);

    centralWidget = new QWidget(this);
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(10);
    gridLayout->setContentsMargins(20, 20, 20, 20);

    QFont buttonFont("Segoe UI", 24, QFont::Bold);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            buttons[row][col] = new QPushButton("");
            buttons[row][col]->setFont(buttonFont);
            buttons[row][col]->setMinimumSize(100, 100);
            gridLayout->addWidget(buttons[row][col], row, col);
        }
    }

    setCentralWidget(centralWidget);
    setupStyle();
}

void tictactoeUI::setupStyle()
{
    QString styleSheet = R"(
        QPushButton {
            background-color: #2d2d30;
            color: #ffffff;
            border: 2px solid #555;
            border-radius: 10px;
        }
        QPushButton:hover {
            background-color: #3e3e42;
        }
        QPushButton:pressed {
            background-color: #1e1e1e;
        }
    )";

    centralWidget->setStyleSheet(styleSheet);
}