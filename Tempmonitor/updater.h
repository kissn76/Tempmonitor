#ifndef UPDATER_H
#define UPDATER_H

#include <QThread>

class Updater : public QThread
{
    Q_OBJECT
public:
    Updater();
    ~Updater();
    void run();

private:
    QString tempFile = "/home/nn/temp";
    QString logFile = "/home/nn/temp.log";
    QString dateFormat = "yyyy-MM-dd HH:mm:ss";
};

#endif // UPDATER_H
