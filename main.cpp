#include <QApplication>
#include "Qt.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    tictactoeUI window;
    window.show();
    return app.exec();
}