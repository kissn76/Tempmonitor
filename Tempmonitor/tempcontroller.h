#ifndef TEMPCONTROLLER_H
#define TEMPCONTROLLER_H

#include <QObject>

class TempController : public QObject
{
    Q_OBJECT

public:
    TempController(int intervall);
    ~TempController();

public slots:
    void update();

private:
    int intervall;
};

#endif // TEMPCONTROLLER_H
