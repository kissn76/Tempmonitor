#ifndef UPDATER_H
#define UPDATER_H

#include <QThread>

class Updater : public QThread
{
    Q_OBJECT
public:
    Updater(QString logFile, QString tempFile);
    ~Updater();
    void run();

private:
    QString tempFile;
    QString logFile;
    QString dateFormat;
};

#endif // UPDATER_H
