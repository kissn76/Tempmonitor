#include "settings.h"
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
    QCommandLineOption n_opt({"n", "nolog"}, "Don't log to file");
    QCommandLineOption t_opt({"t", "tempfile"}, "Temperature file path. Usualy in sys filesystem.", "tempfile");
    QCommandLineOption p_opt({"p", "print"}, "Print to standard output");
    QCommandLineParser parser;

    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(i_opt);
    parser.addOption(l_opt);
    parser.addOption(n_opt);
    parser.addOption(t_opt);
    parser.addOption(p_opt);
    parser.process(QCoreApplication::arguments());

    Settings *settings = new Settings();

    if (parser.isSet(i_opt))
    {
        int i_tmp = parser.value("intervall").toInt();

        if (i_tmp <= 0)
        {
            qDebug() << "Intervall must be a higher integer then 0!";
            parser.showHelp();
        } else {
            settings->setIntervall(i_tmp * 1000);
        }
    }

    if (parser.isSet(l_opt))
    {
        QString l_tmp = parser.value("logfile");

        if (l_tmp.isEmpty())
        {
            parser.showHelp();
        } else {
            settings->setLogFile(l_tmp);
        }
    }

    if (parser.isSet(n_opt))
    {
        settings->setNoLog(true);
    }

    if (parser.isSet(t_opt))
    {
        QString t_tmp = parser.value("tempfile");

        if (t_tmp.isEmpty())
        {
            parser.showHelp();
        } else {
            settings->setTempFile(t_tmp);
        }
    }

    if (parser.isSet(p_opt))
    {
        settings->setPrintStdo(true);
    }

    TempController tc(settings);

    return a.exec();
}
