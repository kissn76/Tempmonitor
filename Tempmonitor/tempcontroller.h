#ifndef TEMPCONTROLLER_H
#define TEMPCONTROLLER_H

#include <QObject>

class TempController : public QObject
{
    Q_OBJECT

public:
    TempController(int intervall, QString logFile, QString tempFile, bool noLog, bool printStdo);
    ~TempController();

public slots:
    void update();

private:
    int intervall;
    QString tempFile;
    QString logFile;
    bool noLog;
    bool printStdo;
};

#endif // TEMPCONTROLLER_H
