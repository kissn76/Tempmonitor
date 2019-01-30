#include "tempcontroller.h"
#include "updater.h"

#include <QTimer>

TempController::TempController(int intervall) : intervall(intervall)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(intervall);
}

TempController::~TempController()
{
}

void TempController::update()
{
    Updater *up = new Updater();
    connect(up, SIGNAL(finished()), up, SLOT(deleteLater()));
    up->start();
}
