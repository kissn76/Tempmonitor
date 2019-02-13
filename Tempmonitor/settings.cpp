#include "settings.h"

#include <QSettings>

Settings::Settings(const QString settingsFile)
    : settingsFile(settingsFile)
{
    loadSettings();
}

Settings::~Settings()
{
}

void Settings::loadSettings()
{
    QSettings settings(settingsFile, QSettings::NativeFormat);

    intervall = settings.value("intervall", 5000).toInt();
    tempFile = settings.value("tempFile", "/sys/class/thermal/thermal_zone0/temp").toString();
    logFile = settings.value("logFile", "/mnt/log/temp.log").toString();
    dateFormat = settings.value("dateFormat", "yyyy-MM-dd HH:mm:ss").toString();
}

void Settings::saveSettings()
{
    QSettings settings(settingsFile, QSettings::NativeFormat);

    settings.setValue("intervall", intervall);
    settings.setValue("tempFile", tempFile);
    settings.setValue("logFile", logFile);
    settings.setValue("dateFormat", dateFormat);
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
