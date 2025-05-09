#ifndef QT_H
#define QT_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QFont>

class tictactoeUI : public QMainWindow {
    Q_OBJECT

public:
    tictactoeUI(QWidget *parent = nullptr);

private:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *buttons[3][3];

    void setupStyle();
};

#endif // QT_H