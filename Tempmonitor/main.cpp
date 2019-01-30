#include "tempcontroller.h"

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TempController tc(60 * 1000);

    return a.exec();
}
