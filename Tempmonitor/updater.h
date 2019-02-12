#ifndef UPDATER_H
#define UPDATER_H

#include <QThread>

class Updater : public QThread
{
    Q_OBJECT
public:
    Updater(QString logFile, QString tempFile, bool noLog, bool printStdo);
    ~Updater();
    void run();

private:
    QString tempFile;
    QString logFile;
    QString dateFormat;
    bool noLog;
    bool printStdo;
};

#endif // UPDATER_H
