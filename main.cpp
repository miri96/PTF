#include "punto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Punto w;
    w.show();

    return a.exec();
}
