#include "tempcontroller.h"
#include "updater.h"

#include <QTimer>
#include <QDebug>

TempController::TempController(int intervall, QString logFile, QString tempFile) : intervall(intervall), tempFile(tempFile), logFile(logFile)
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
    Updater *up = new Updater(logFile, tempFile);
    connect(up, SIGNAL(finished()), up, SLOT(deleteLater()));
    up->start();
}
