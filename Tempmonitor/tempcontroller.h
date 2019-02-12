#ifndef TEMPCONTROLLER_H
#define TEMPCONTROLLER_H

#include <QObject>

class TempController : public QObject
{
    Q_OBJECT

public:
    TempController(int intervall, QString logFile, QString tempFile);
    ~TempController();

public slots:
    void update();

private:
    int intervall;
    QString tempFile;
    QString logFile;
};

#endif // TEMPCONTROLLER_H
