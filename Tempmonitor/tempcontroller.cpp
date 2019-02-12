#include "tempcontroller.h"
#include "updater.h"

#include <QTimer>

TempController::TempController(Settings *settings)
    : settings(settings)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(settings->getIntervall());
}

TempController::~TempController()
{
}

void TempController::update()
{
    Updater *up = new Updater(settings);
    connect(up, SIGNAL(finished()), up, SLOT(deleteLater()));
    up->start();
}
