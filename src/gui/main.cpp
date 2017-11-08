#include <QApplication>

#include "base58checktranscoderwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Base58CheckTranscoderWidget w;
    w.show();

    return a.exec();
}
