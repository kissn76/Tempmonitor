#include "updater.h"

#include <QDateTime>
#include <QFile>
#include <QTextStream>

Updater::Updater()
{
}

Updater::~Updater()
{
}

void Updater::run()
{
    QString dateTime = QDateTime::currentDateTime().toString(dateFormat);

    double temperature = 0;
    QFile inFile(tempFile);
    if (inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&inFile);
        temperature = in.readAll().toDouble() / 1000;
    }
    inFile.close();

    QFile outFile(logFile);
    if (outFile.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&outFile);
        out << dateTime << ";" << temperature << endl;
    }
    outFile.close();
}
