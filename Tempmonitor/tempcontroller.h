#ifndef TEMPCONTROLLER_H
#define TEMPCONTROLLER_H

#include "settings.h"

#include <QObject>

class TempController : public QObject
{
    Q_OBJECT

public:
    TempController(Settings *settings);
    ~TempController();

public slots:
    void update();

private:
    Settings *settings;
};

#endif // TEMPCONTROLLER_H
