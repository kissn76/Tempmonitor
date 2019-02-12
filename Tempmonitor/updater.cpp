#include "updater.h"

#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Updater::Updater(QString logFile, QString tempFile, bool noLog, bool printStdo)
    : tempFile(tempFile), logFile(logFile), noLog(noLog), printStdo(printStdo)
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

    if (printStdo)
    {
        qDebug() << dateTime << ": " << temperature;
    }

    if (!noLog)
    {
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
}
