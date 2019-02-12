#include "updater.h"

#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Updater::Updater(Settings *settings)
    : settings(settings)
{
}

Updater::~Updater()
{
}

void Updater::run()
{
    QString dateTime = QDateTime::currentDateTime().toString(settings->getDateFormat());

    double temperature = 0;
    QFile inFile(settings->getTempFile());
    if (inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&inFile);
        temperature = in.readAll().toDouble() / 1000;
    } else {
        qDebug() << inFile.fileName() << "is not a valid temperature file!";
        exit(0);
    }
    inFile.close();

    if (settings->isPrintStdo())
    {
        qDebug() << dateTime << ": " << temperature;
    }

    if (!settings->isNoLog())
    {
        QFile outFile(settings->getLogFile());
        if (outFile.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&outFile);
            out << dateTime << ";" << temperature << endl;
        } else {
            qDebug() << outFile.fileName() << "is not writeable file!";
            exit(0);
        }
        outFile.close();
    }
}
