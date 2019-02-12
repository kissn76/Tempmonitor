#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT

public:
    Settings();
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
    int intervall = 5 * 1000;
    QString tempFile = "/sys/class/thermal/thermal_zone0/temp";
    QString logFile = "/mnt/log/temp.log";
    QString dateFormat = "yyyy-MM-dd HH:mm:ss";
    bool noLog = false;
    bool printStdo = false;
};

#endif // SETTINGS_H
