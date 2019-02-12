#include "tempcontroller.h"

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //https://www.qtcentre.org/threads/67271-Question-on-proper-use-of-QCommandLineOption
    QCommandLineOption i_opt({"i", "intervall"}, "Refresh intervall", "intervall");
    QCommandLineOption l_opt({"l", "logfile"}, "Logfile path", "logfile");
    QCommandLineOption t_opt({"t", "tempfile"}, "Temperature file path. Usualy in sys filesystem.", "tempfile");
    QCommandLineParser parser;

    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(i_opt);
    parser.addOption(l_opt);
    parser.addOption(t_opt);
    parser.process(QCoreApplication::arguments());

    int intervall = parser.value("intervall").toInt();
    int intervallMs = 5 * 1000;
    QString logFile = "/mnt/log/temp.log";
    QString tempFile  = "/sys/class/thermal/thermal_zone0/temp";

    if (parser.isSet(i_opt))
    {
        if (intervall <= 0)
        {
            qDebug() << "Intervall must be a higher integer then 0!";
            parser.showHelp();
        } else {
            intervallMs = intervall * 1000;
        }
    }

    if (parser.isSet(l_opt))
    {
        QString l_temp = parser.value("logfile");

        if (l_temp.isEmpty())
        {
            parser.showHelp();
        } else {
            logFile = l_temp;
        }
    }

    if (parser.isSet(t_opt))
    {
        QString t_temp = parser.value("tempfile");

        if (t_temp.isEmpty())
        {
            parser.showHelp();
        } else {
            tempFile = t_temp;
        }
    }

    TempController tc(intervallMs, logFile, tempFile);

    return a.exec();
}
