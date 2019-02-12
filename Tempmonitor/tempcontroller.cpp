#include "tempcontroller.h"
#include "updater.h"

#include <QTimer>
#include <QDebug>

TempController::TempController(int intervall, QString logFile, QString tempFile, bool noLog, bool printStdo)
    : intervall(intervall), tempFile(tempFile), logFile(logFile), noLog(noLog), printStdo(printStdo)
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
    Updater *up = new Updater(logFile, tempFile, noLog, printStdo);
    connect(up, SIGNAL(finished()), up, SLOT(deleteLater()));
    up->start();
}
