#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT

public:
    Settings(const QString settingsFile = "/etc/tempmonitor/tempmonitor.conf");
    ~Settings();

    int getIntervall() const;
    void setIntervall(int value);

    QString getTempFile() const;
    void setTempFile(const QString &value);

    QString getLogFile() const;
    void setLogFile(const QString &value);

    QString getDateFormat() const;
    void setDateFormat(const QString &value);

    bool isNoLog() const;
    void setNoLog(bool value);

    bool isPrintStdo() const;
    void setPrintStdo(bool value);

private:
    int intervall;
    QString tempFile;
    QString logFile;
    QString dateFormat;
    bool noLog = false;
    bool printStdo = false;
    QString settingsFile;

    void loadSettings();
    void saveSettings();
};

#endif // SETTINGS_H
