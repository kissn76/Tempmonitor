#include "settings.h"

Settings::Settings()
{
}

Settings::~Settings()
{
}

int Settings::getIntervall() const
{
    return intervall;
}

void Settings::setIntervall(int value)
{
    intervall = value;
}

QString Settings::getTempFile() const
{
    return tempFile;
}

void Settings::setTempFile(const QString &value)
{
    tempFile = value;
}

QString Settings::getLogFile() const
{
    return logFile;
}

void Settings::setLogFile(const QString &value)
{
    logFile = value;
}

QString Settings::getDateFormat() const
{
    return dateFormat;
}

void Settings::setDateFormat(const QString &value)
{
    dateFormat = value;
}

bool Settings::isNoLog() const
{
    return noLog;
}

void Settings::setNoLog(bool value)
{
    noLog = value;
}

bool Settings::isPrintStdo() const
{
    return printStdo;
}

void Settings::setPrintStdo(bool value)
{
    printStdo = value;
}
