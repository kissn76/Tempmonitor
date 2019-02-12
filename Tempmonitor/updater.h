#ifndef UPDATER_H
#define UPDATER_H

#include "settings.h"

#include <QThread>

class Updater : public QThread
{
    Q_OBJECT
public:
    Updater(Settings *settings);
    ~Updater();
    void run();

private:
    Settings *settings;
};

#endif // UPDATER_H
