#include "updater.h"

#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Updater::Updater(QString logFile, QString tempFile) : tempFile(tempFile), logFile(logFile)
{
    this->dateFormat = "yyyy-MM-dd HH:mm:ss";
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
    } else {
        qDebug() << tempFile << "is not a valid temperature file!";
        exit(0);
    }
    inFile.close();

    QFile outFile(logFile);
    if (outFile.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&outFile);
        out << dateTime << ";" << temperature << endl;
    } else {
        qDebug() << logFile << "is not writeable file!";
        exit(0);
    }
    outFile.close();
}
